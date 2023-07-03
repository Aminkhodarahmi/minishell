/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:32:43 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 14:59:01 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_builtin_hdoc(t_input *in, t_list *arg_list)
{
	t_arg	*sub;
	int		i;

	i = 0;
	sub = (t_arg *)arg_list->content;
	in->split_in = arr_dup(sub->arg);
	in->q_state = sub->quotes;
	if (ft_lstsize(arg_list) == 1 && in->is_hdoc)
	{
		if (in->split_in && (is_builtin(in) || is_builtin2(in)))
		{
			while (in->split_in[i])
			{
				if (!(ft_strncmp(in->split_in[i], "<<", 3))
					&& in->q_state[i] == 0)
				{
					remove_redir(in, i);
					i--;
				}
				i++;
			}
			exec_args(in);
		}
	}
	fr_arr(in->split_in);
}

void	child(t_input *in, t_list *sub_list, int index)
{
	verify_redirs(in);
	if (sub_list->next != NULL)
	{
		if (!in->is_outfile)
			dup2(in->fd[index % 2][1], STDOUT_FILENO);
	}
	close(in->fd[index % 2][1]);
	if (index > 0)
	{
		close(in->fd[index % 2][1]);
		if (!in->is_infile)
			dup2(in->fd[(index + 1) % 2][0], STDIN_FILENO);
		close(in->fd[(index + 1) % 2][0]);
	}
	close(in->fd[index % 2][0]);
	if (in->is_outfile)
		close(in->back_stdout);
	if (in->split_in[0])
	{
		if (is_builtin(in) && !in->total_pipes)
			exit (g_quit);
		else
			exec_args(in);
	}
	exit (g_quit);
}

void	sub_pipex(t_input *in, t_list *sub_list, int index, int *flag)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(in->fd[index % 2][1]);
		close(in->fd[index % 2][0]);
		*flag = 1;
	}
	if (!pid)
		child(in, sub_list, index);
	close(in->fd[index % 2][1]);
	if (index == 0 && sub_list->next == NULL)
		close(in->fd[index % 2][0]);
	if (index > 0 && sub_list->next != NULL)
		close(in->fd[(index + 1) % 2][0]);
	if (index > 0 && sub_list->next == NULL)
	{
		close(in->fd[index % 2][0]);
		close(in->fd[(index + 1) % 2][0]);
	}
}

void	kill_last_process(t_input *in, int flag)
{
	if (flag)
		error_msg(in, "Fork error", -2, 0);
	while (in->total_pipes >= 0)
	{
		waitpid(-1, &in->status, 0);
		if (WIFEXITED(in->status))
			g_quit = WEXITSTATUS(in->status);
		in->total_pipes--;
	}
	if (g_quit == 250)
		g_quit = 1;
}

void	pipex(t_input *in, t_list *arg_list)
{
	t_arg	*sub;
	t_list	*sub_list;
	int		index;
	int		flag;

	index = 0;
	flag = 0;
	sub_list = arg_list;
	while (sub_list && WIFEXITED(in->status))
	{
		if (pipe(in->fd[index % 2]) == -1)
			error_msg(in, "Pipe error", -1, 0);
		sub = (t_arg *)sub_list->content;
		in->split_in = sub->arg;
		in->q_state = sub->quotes;
		if_minishell(in);
		sub_pipex(in, sub_list, index, &flag);
		sub_list = sub_list->next;
		index++;
	}
	kill_last_process(in, flag);
	exec_builtin_hdoc(in, arg_list);
	free_list(in, arg_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:10:53 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 14:59:46 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	remove_redir(t_input *in, int i)
{
	char	**sub;
	int		j;

	j = 0;
	sub = malloc(sizeof(char *) * (arr_len(in->split_in) - 1));
	while (in->split_in[j] && j < i)
	{
		sub[j] = ft_strdup(in->split_in[j]);
		j++;
	}
	i += 2;
	while (in->split_in[i])
	{
		sub[j] = ft_strdup(in->split_in[i]);
		in->q_state[j] = in->q_state[i];
		j++;
		i++;
	}
	sub[j] = NULL;
	fr_arr(in->split_in);
	in->split_in = NULL;
	in->split_in = sub;
}

void	here_doc(t_input *in, int i)
{
	char	*eof;
	int		fd;
	char	*here_doc;

	here_doc = NULL;
	fd = open(".hd_tmp", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		error_msg(in, "No such file or directory", -1, 0);
	eof = ft_strdup(in->split_in[i + 1]);
	free(in->prompt);
	in->prompt = ft_strdup("> ");
	while (1)
	{
		here_doc = readline(in->prompt);
		if (!here_doc || !(ft_strcmp(here_doc, eof)))
			break ;
		write(fd, here_doc, ft_strlen(here_doc));
		write(fd, "\n", 1);
		free(here_doc);
	}
	close(fd);
	free(here_doc);
	free(eof);
}

void	exec_hdoc(t_input *in)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid < 0)
		error_msg(in, "Fork error", -1, 0);
	if (!pid)
	{
		signal(SIGINT, handler4);
		while (in->split_in[i])
		{
			if (!(ft_strncmp(in->split_in[i], "<<", 3)) && in->q_state[i] == 0)
				here_doc(in, i);
			i++;
		}
		exit (0);
	}
	waitpid(pid, &in->status, 0);
	g_quit = WEXITSTATUS(in->status);
}

int	verify_hdoc(t_input *in)
{
	int	i;

	i = 0;
	in->is_hdoc = 0;
	while (in->split_in[i])
	{
		if (!(ft_strncmp(in->split_in[i], "<<", 3)) && in->q_state[i] == 0)
			in->is_hdoc = 1;
		i++;
	}
	if (in->is_hdoc)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		exec_hdoc(in);
	}
	return (0);
}

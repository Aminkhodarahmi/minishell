/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:14:44 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/24 23:16:30 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	infile_sub(t_input *in)
{
	if (!is_builtin(in))
	{
		if (dup2(in->fd_in, STDIN_FILENO) == -1)
			error_msg(in, "Dup error", -2, 0);
	}
	close(in->fd_in);
	in->is_infile = 1;
}

int	infile(t_input *in, int i)
{
	if (!(ft_strncmp(in->split_in[i], "<", 2)) && in->q_state[i] == 0)
		in->fd_in = open(in->split_in[i + 1], O_RDONLY);
	if (!(ft_strncmp(in->split_in[i], "<<", 3)) && in->q_state[i] == 0)
		in->fd_in = open(".hd_tmp", O_RDONLY);
	if (in->fd_in == -1)
	{
		if (errno == EACCES)
			error_msg(in, "Permission denied", i + 1, 0);
		else if (!(ft_strncmp(in->split_in[i], "<<", 3)) && errno == 2)
			error_msg(in, "here_doc: could not find here_doc file", -1, 0);
		else
			error_msg(in, "No such file or directory", i + 1, 0);
		return (1);
	}
	else
	{
		remove_redir(in, i);
		if (!in->split_in[0])
		{
			close(in->fd_in);
			return (1);
		}
		infile_sub(in);
	}
	return (0);
}

void	outfile_sub(t_input *in)
{
	if (!in->is_outfile)
		in->back_stdout = dup(STDOUT_FILENO);
	if (dup2(in->fd_out, STDOUT_FILENO) == -1)
		error_msg(in, "Dup error", -2, 0);
	close(in->fd_out);
	in->is_outfile = 1;
}

int	outfile(t_input *in, int i)
{
	if (!(ft_strncmp(in->split_in[i], ">", 2)) && in->q_state[i] == 0)
		in->fd_out = open(in->split_in[i + 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!(ft_strncmp(in->split_in[i], ">>", 3)) && in->q_state[i] == 0)
		in->fd_out = open(in->split_in[i + 1],
				O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (in->fd_out == -1)
	{
		if (errno == EACCES)
			error_msg(in, "Permission denied", i + 1, 0);
		else
			error_msg(in, "No such file or directory", i + 1, 0);
		return (1);
	}
	else
	{
		remove_redir(in, i);
		if (!in->split_in[0])
		{
			close(in->fd_out);
			return (1);
		}
		outfile_sub(in);
	}
	return (0);
}

void	verify_redirs(t_input *in)
{
	int	i;

	i = -1;
	in->is_infile = 0;
	in->is_outfile = 0;
	while (in->split_in[++i])
	{
		if (!(ft_strncmp(in->split_in[i], "<", 1)) && in->q_state[i] == 0)
		{
			if (infile(in, i))
				return ;
			i--;
		}
		else if (!(ft_strncmp(in->split_in[i], ">", 1)) && in->q_state[i] == 0)
		{
			if (outfile(in, i))
				return ;
			i--;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:14:44 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/09 18:15:47 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	outfile_aux(t_input *in)
{
	if (!in->is_outfile)
		in->back_stdout = dup(STDOUT_FILENO);
	if (dup2(in->fd_out, STDOUT_FILENO) == -1)
		error_msg(in, ERR_DUP, -2, 0);
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
			error_msg(in, ERR_PERM, i + 1, 0);
		else
			error_msg(in, ERR_FILE, i + 1, 0);
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
		outfile_aux(in);
	}
	return (0);
}

void	check_redirs(t_input *in)
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
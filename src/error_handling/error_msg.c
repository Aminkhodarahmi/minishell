/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:58:39 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 14:56:14 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_list(t_input *in, t_list *arg_list)
{
	t_arg	*sub;
	t_list	*sub_list;

	sub_list = arg_list;
	while (sub_list)
	{
		sub = (t_arg *)sub_list->content;
		fr_arr(sub->arg);
		free(sub->quotes);
		sub_list = sub_list->next;
	}
	ft_lstclear(&arg_list, free);
	in->q_state = NULL;
	in->split_in = NULL;
}

int	update_g_quit(char *ERR, int is_abs)
{
	if (!ft_strcmp(ERR, "is a directory"))
		return (126);
	else if (!ft_strcmp(ERR, "Permission denied"))
	{
		if (is_abs == 1)
			return (126);
	}
	else if (!ft_strcmp(ERR, "No such file or directory"))
	{
		if (is_abs == 1)
			return (127);
	}
	else if (!ft_strcmp(ERR, "command not found"))
		return (127);
	else if (!ft_strcmp(ERR, "Syntax error near unexpected token `newLine"))
		return (258);
	else if (!ft_strcmp(ERR, "Syntax error near unexpected token '|'"))
		return (258);
	else if (!ft_strcmp(ERR, "Syntax error near unexpected token '<'"))
		return (258);
	else if (!ft_strcmp(ERR, "Syntax error near unexpected token '>'"))
		return (258);
	return (1);
}

int	error_msg(t_input *in, char *MSG, int n, int is_abs)
{
	if (n >= 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(in->split_in[n], 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(MSG, 2);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putendl_fd(MSG, 2);
	}
	if (in->split_in && !is_builtin(in) && n != -2)
		exit(update_g_quit(MSG, is_abs));
	g_quit = update_g_quit(MSG, is_abs);
	in->is_err = 1;
	return (0);
}

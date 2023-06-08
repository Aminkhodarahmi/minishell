/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:58:39 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/08 18:52:53 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	update_g_exit_status(char *ERR, int is_abs)
{
	// for error 126, 127, 258
}

int	error_msg(t_input *in, char *MSG, int n, int is_abs)
{
	if (n >= 0)
	{
		ft_putstr_fd(SHELL, 2);
		ft_putstr_fd(in->split_in[n], 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(MSG, 2);
	}
	else
	{
		ft_putstr_fd(SHELL, 2);
		ft_putendl_fd(MSG, 2);
	}
	if (in->split_in && !is_builtin(in) && n != -2)
		exit(update_g_exit_status(MSG, is_abs));
	g_exit_status = update_g_exit_status(MSG, is_abs);
	in->is_err = 1;
	return (0);
}

int	error_msg(t_input *in, char *MSG, int n, int is_abs)
{
	if (n >= 0)
	{
		ft_putstr_fd(SHELL, 2);
		ft_putstr_fd(in->split_in[n], 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(MSG, 2);
	}
	else
	{
		ft_putstr_fd(SHELL, 2);
		ft_putendl_fd(MSG, 2);
	}
	if (in->split_in && !is_builtin(in) && n != -2)
		exit(update_g_exit_status(MSG, is_abs));
	g_exit_status = update_g_exit_status(MSG, is_abs);
	in->is_err = 1;
	return (0);
}

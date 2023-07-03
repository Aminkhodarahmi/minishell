/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:28:04 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 14:56:14 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-' && str[1] != '\0' && ft_isdigit(str[1]))
			i++;
		else if (!ft_isdigit(str[i]))
			return (0);
		else
			i++;
	}
	return (1);
}

int	verify_exit_args(t_input *in)
{
	if (str_is_digit(in->split_in[1]) && !in->split_in[2])
		g_quit = (ft_atoi(in->split_in[1]));
	else if (!str_is_digit(in->split_in[1]))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(in->split_in[1], 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd("numeric argument requiered", 2);
		g_quit = 255;
	}	
	else if (str_is_digit(in->split_in[1]) && in->split_in[2])
	{
		error_msg(in, "too many arguments", 0, 0);
		return (1);
	}
	return (0);
}

void	my_exit(t_input *in)
{
	g_quit = 0;
	if (!in->total_pipes)
		ft_putendl_fd("exit", 2);
	if (in->split_in[1])
	{
		if (verify_exit_args(in))
			return ;
	}
	fr_arr(in->split_in);
	free(in->q_state);
	ft_lstclear(in->env_list, free);
	free(in->prompt);
	close(0);
	close(1);
	close(2);
	exit(g_quit);
}

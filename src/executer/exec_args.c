/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:36:25 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/17 18:53:04 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_builtin2(t_input *in)
{
	if (in->split_in[2])
	{
		if (!(ft_strncmp(in->split_in[2], "pwd", 4)))
			return (1);
		else if (!(ft_strncmp(in->split_in[2], "env", 4)))
			return (1);
		else if (!(ft_strncmp(in->split_in[2], "cd", 3)))
			return (1);
		else if (!(ft_strncmp(in->split_in[2], "echo", 5)))
			return (1);
		else if (!(ft_strncmp(in->split_in[2], "export", 7)))
			return (1);
		else if (!(ft_strncmp(in->split_in[2], "unset", 6)))
			return (1);
		else if (!(ft_strncmp(in->split_in[2], "exit", 5)))
			return (1);
	}
	return (0);
}

int	is_builtin(t_input *in)
{
	if (!(ft_strncmp(in->split_in[0], "pwd", 4)))
		return (1);
	else if (!(ft_strncmp(in->split_in[0], "env", 4)))
		return (1);
	else if (!(ft_strncmp(in->split_in[0], "cd", 3)))
		return (1);
	else if (!(ft_strncmp(in->split_in[0], "echo", 5)))
		return (1);
	else if (!(ft_strncmp(in->split_in[0], "export", 7)))
		return (1);
	else if (!(ft_strncmp(in->split_in[0], "unset", 6)))
		return (1);
	else if (!(ft_strncmp(in->split_in[0], "exit", 5)))
		return (1);
	return (0);
}

void	exec_args(t_input *in)
{
	// if (!(ft_strncmp(in->split_in[0], "pwd", 4)))
	// 	pwd(in);
	// else if (!(ft_strncmp(in->split_in[0], "env", 4)))
	// 	env(in, 0);
	// else if (!(ft_strncmp(in->split_in[0], "cd", 3)))
	// 	cd(in);
	// else if (!(ft_strncmp(in->split_in[0], "echo", 5)))
	// 	echo(in);
	// else if (!(ft_strncmp(in->split_in[0], "export", 7)))
	// 	export(in);
	// else if (!(ft_strncmp(in->split_in[0], "unset", 6)))
	// 	unset(in, 1);
	if (!(ft_strncmp(in->split_in[0], "./minishell", 12)))
		exec_minishell(in);
	// else if (!(ft_strncmp(in->split_in[0], "exit", 5)))
	// 	my_exit(in);
	// else if (!(ft_strchr(in->split_in[0], '/')))
	// 	exec_cmd(in);
	// else
	// 	exec_absolute(in);
}

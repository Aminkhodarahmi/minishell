/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:36:25 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/17 13:48:01 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	// execute pwd
	// execute env
	// execute cd
	// execute echo
	// execute export
	// execute unset
	// execute exit
	// execute "./minishell"
	// execute '/'
}

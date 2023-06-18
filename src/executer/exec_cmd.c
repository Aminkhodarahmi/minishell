/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:30:51 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/17 18:54:09 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_minishell(t_input *in)
{
	// char	**new_env;
	int		size;
	int		i;

	if (in->total_pipes)
		exit (0);
	size = 0;
	i = -1;
	while (in->dup_env[++i])
	{
		if (ft_strchr(in->dup_env[i], '='))
			size++;
	}
	// new_env = dup_new_env(in->dup_env, size);
	// if (execve(in->split_in[0], in->split_in, new_env) == -1)
	// 	error_msg(in, ERR_CMD, 0, 0);
	// free_matrix(new_env);
}

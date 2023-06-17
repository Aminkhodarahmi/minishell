/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:13:26 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/09 18:13:57 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	count_pipes(t_input *in)
{
	int	i;

	i = 0;
	in->total_pipes = 0;
	while (in->split_in[i] != NULL)
	{
		if (!(ft_strncmp(in->split_in[i], "|", 2)) && in->q_state[i] == 0)
			in->total_pipes++;
		i++;
	}
	return (in->total_pipes);
}

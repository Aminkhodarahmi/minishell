/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:29:50 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 15:02:00 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**arr_dup(char **arrs)
{
	char	**out;
	int		size;
	int		i;

	i = 0;
	size = arr_len(arrs);
	out = malloc(sizeof(char *) * (size + 1));
	if (!out)
		return (NULL);
	while (arrs[i])
	{
		out[i] = ft_strdup(arrs[i]);
		if (!out[i])
		{
			fr_arr(out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_arr_loc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:26:16 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 12:42:01 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**rm_arr_loc(char **arrs, int pos)
{
	int		i;
	int		j;
	char	**sub;

	i = 0;
	j = 0;
	sub = malloc(arr_len(arrs));
	while (arrs[i])
	{
		if (i == pos)
			i++;
		sub[j] = arrs[i];
		i++;
		j++;
	}
	sub[j] = NULL;
	return (sub);
}

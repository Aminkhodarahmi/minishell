/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:29:32 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 15:02:00 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**arr_add_back(char **arrs, char *str)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!str)
		return (arrs);
	len = arr_len(arrs);
	out = malloc(sizeof(char *) * (len + 2));
	out[len + 1] = NULL;
	if (!out)
		return (arrs);
	while (++i < len && arrs[i] != NULL)
	{
		out[i] = ft_strdup(arrs[i]);
		if (!out[i])
		{
			fr_arr(arrs);
			fr_arr(out);
		}
	}
	out[i] = ft_strdup(str);
	fr_arr(arrs);
	return (out);
}

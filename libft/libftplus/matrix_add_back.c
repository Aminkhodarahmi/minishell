/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:29:32 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 12:40:42 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftplus.h"

char	**matrix_add_back(char **matrix, char *str)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!str)
		return (matrix);
	len = matrix_len(matrix);
	out = malloc(sizeof(char *) * (len + 2));
	out[len + 1] = NULL;
	if (!out)
		return (matrix);
	while (++i < len && matrix[i] != NULL)
	{
		out[i] = ft_strdup(matrix[i]);
		if (!out[i])
		{
			free_matrix(matrix);
			free_matrix(out);
		}
	}
	out[i] = ft_strdup(str);
	free_matrix(matrix);
	return (out);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_matrix_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:26:16 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 12:39:59 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftplus.h"

char	**del_matrix_pos(char **matrix, int pos)
{
	int		i;
	int		j;
	char	**aux;

	i = 0;
	j = 0;
	aux = malloc(matrix_len(matrix));
	while (matrix[i])
	{
		if (i == pos)
			i++;
		aux[j] = matrix[i];
		i++;
		j++;
	}
	aux[j] = NULL;
	return (aux);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:30:39 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/15 18:49:53 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		printf("(null)\n");
	else
	{
		while (matrix[i])
		{
			printf("%s\n", matrix[i]);
			i++;
		}
	}
}

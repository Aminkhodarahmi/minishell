/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:30:39 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 12:41:13 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftplus.h"

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		ft_printf("(null)\n");
	else
	{
		while (matrix[i])
		{
			ft_printf("%s\n", matrix[i]);
			i++;
		}
	}
}
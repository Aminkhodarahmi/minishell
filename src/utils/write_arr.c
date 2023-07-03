/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:30:39 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 12:42:57 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>

void	write_arr(char **arrs)
{
	int	i;

	i = 0;
	if (!arrs)
		printf("(null)\n");
	else
	{
		while (arrs[i])
		{
			printf("%s\n", arrs[i]);
			i++;
		}
	}
}

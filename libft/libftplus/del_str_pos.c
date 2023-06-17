/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_str_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:26:34 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/15 18:41:31 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*del_str_pos(char *str, int n)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	aux = malloc(ft_strlen(str));
	while (str[i])
	{
		if (i == n)
			i++;
		aux[j] = str[i];
		i++;
		j++;
	}
	aux[j] = '\0';
	return (aux);
}

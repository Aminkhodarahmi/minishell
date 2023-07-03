/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_str_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:26:34 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 12:42:09 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*del_str_pos(char *str, int n)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	j = 0;
	sub = malloc(ft_strlen(str));
	while (str[i])
	{
		if (i == n)
			i++;
		sub[j] = str[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

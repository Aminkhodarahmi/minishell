/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:29:03 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 12:40:38 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftplus.h"

char	**list_to_matrix(t_list *lst)
{
	int		i;
	char	**matrix;
	t_list	*aux;

	i = 0;
	aux = lst;
	matrix = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	while (aux)
	{
		matrix[i] = ft_strdup(aux->content);
		aux = aux->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

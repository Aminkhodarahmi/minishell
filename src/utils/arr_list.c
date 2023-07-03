/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:29:03 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 14:57:25 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**arr_list(t_list *lst)
{
	int		i;
	char	**arrs;
	t_list	*sub;

	i = 0;
	sub = lst;
	arrs = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	while (sub)
	{
		arrs[i] = ft_strdup(sub->content);
		sub = sub->next;
		i++;
	}
	arrs[i] = NULL;
	return (arrs);
}

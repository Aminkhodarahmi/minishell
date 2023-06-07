/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:27:22 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 12:40:15 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftplus.h"

void	ft_lst_free(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

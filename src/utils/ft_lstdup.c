/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:27:59 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 12:42:25 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_list	*ft_lstdup(t_list *sub)
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*lst;

	new_lst = 0;
	lst = sub;
	while (lst)
	{
		tmp = ft_lstnew(lst->content);
		if (!tmp)
			return (0);
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}

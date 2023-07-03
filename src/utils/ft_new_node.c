/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:32:51 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 12:42:29 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_list	*ft_new_node(void *content, size_t size)
{
	t_list	*stack;
	void	*sub;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	sub = malloc(size);
	if (!sub)
	{
		free(stack);
		stack = NULL;
	}
	ft_memcpy(sub, content, size);
	stack->content = sub;
	stack->next = NULL;
	return (stack);
}

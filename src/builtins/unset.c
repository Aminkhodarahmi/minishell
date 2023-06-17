/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:04:13 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/17 13:42:56 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	delete_head(t_input *in)
{
	t_list	*tmp;

	tmp = *in->env_list;
	*in->env_list = (*in->env_list)->next;
	ft_lstdelone(tmp, free);
}

void	unset_from_list(t_input *in, char **var, int size_var)
{
	t_list	*aux;
	t_list	*tmp;
	char	*str;

	aux = *in->env_list;
	str = (char *)aux->content;
	if (!(ft_strncmp((*var), str, size_var)) && str[size_var] == '=')
		delete_head(in);
	else
	{
		while (aux)
		{
			if (aux->next != NULL)
				str = (char *)aux->next->content;
			if (!(ft_strncmp((*var), str, size_var)) && str[size_var] == '=')
			{
				tmp = aux->next;
				aux->next = aux->next->next;
				ft_lstdelone(tmp, free);
				break ;
			}
			aux = aux->next;
		}
	}
}

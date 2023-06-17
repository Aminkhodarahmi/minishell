/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:57:05 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/15 19:23:31 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_export(t_list **lst, int i)
{
	t_list	*aux;
	char	*str;

	aux = *lst;
	while (aux)
	{
		i = 0;
		str = (char *)aux->content;
		ft_putstr_fd("export ", 1);
		while (str[i] != '=' && str[i] != '\0')
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
		if (str[i] != '\0')
		{
			ft_putstr_fd("=\"", 1);
			while (str[++i] != '\0')
				ft_putchar_fd(str[i], 1);
			ft_putendl_fd("\"", 1);
		}
		else
			write(1, "\n", 1);
		aux = aux->next;
	}
}

void	env(t_input *in, int is_export)
{
	t_list	*aux;

	if (in->split_in[1] != NULL)
	{
		error_msg(in, ERR_FILE, 0, 0);
		return ;
	}
	if (!is_export)
	{
		aux = (*in->env_list);
		while (aux)
		{
			if (ft_strchr(aux->content, '='))
				ft_putendl_fd((char *)aux->content, 1);
			aux = aux->next;
		}
	}
	else
	{
		aux = ft_lstdup(*in->env_list);
		ft_lst_sort(&aux, ft_strcmp);
		print_export(&aux, is_export);
		ft_lst_free(aux);
	}
}

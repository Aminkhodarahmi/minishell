/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:57:05 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/24 23:09:04 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_export(t_list **lst, int i)
{
	t_list	*sub;
	char	*str;

	sub = *lst;
	while (sub)
	{
		i = 0;
		str = (char *)sub->content;
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
		sub = sub->next;
	}
}

void	env(t_input *in, int is_export)
{
	t_list	*sub;

	if (in->split_in[1] != NULL)
	{
		error_msg(in, "No such file or directory", 0, 0);
		return ;
	}
	if (!is_export)
	{
		sub = (*in->env_list);
		while (sub)
		{
			if (ft_strchr(sub->content, '='))
				ft_putendl_fd((char *)sub->content, 1);
			sub = sub->next;
		}
	}
	else
	{
		sub = ft_lstdup(*in->env_list);
		ft_lst_sort(&sub, ft_strcmp);
		print_export(&sub, is_export);
		ft_lst_free(sub);
	}
}

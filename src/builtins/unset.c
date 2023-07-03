/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:04:13 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 14:57:21 by akhodara         ###   ########.fr       */
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
	t_list	*sub;
	t_list	*tmp;
	char	*str;

	sub = *in->env_list;
	str = (char *)sub->content;
	if (!(ft_strncmp((*var), str, size_var)) && str[size_var] == '=')
		delete_head(in);
	else
	{
		while (sub)
		{
			if (sub->next != NULL)
				str = (char *)sub->next->content;
			if (!(ft_strncmp((*var), str, size_var)) && str[size_var] == '=')
			{
				tmp = sub->next;
				sub->next = sub->next->next;
				ft_lstdelone(tmp, free);
				break ;
			}
			sub = sub->next;
		}
	}
}

int	is_valid_id(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i])) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	unset_sub2(t_input *in, char *var)
{
	int		size_var;

	size_var = ft_strlen(var);
	unset_from_list(in, &var, size_var);
	if (!(ft_strncmp(var, "PATH=", size_var)))
		in->path_unset = 1;
	fr_arr(in->dup_env);
	in->dup_env = arr_list(*in->env_list);
}

void	unset(t_input *in, int j)
{
	char	*var;
	char	*tmp_env;

	if (in->split_in[1] == NULL)
		return ;
	while (in->split_in[j])
	{
		if (!is_valid_id(in->split_in[j]))
			error_msg(in, "not a valid identifier", j, 0);
		else
		{
			var = ft_strdup(in->split_in[j]);
			tmp_env = ft_getenv(var, in);
			if (tmp_env)
			{
				unset_sub2(in, var);
				free(tmp_env);
			}
			free(var);
		}
		j++;
	}
}

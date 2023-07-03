/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:55:51 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 19:41:06 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	valid_id(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i])) && str[i] != '=' && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	export_sub(t_input *in, char **sub, int j)
{
	char	*env_value;
	char	*var;

	if (!valid_id(sub[0]))
		error_msg(in, "not a valid identifier", j, 0);
	else
	{
		env_value = ft_getenv(sub[0], in);
		if (env_value)
		{
			var = ft_strdup(sub[0]);
			unset_from_list(in, &var, ft_strlen(var));
			ft_lstadd_back(in->env_list,
				ft_new_node((void *) in->split_in[j],
					ft_strlen(in->split_in[j]) + 1));
			free(env_value);
			free(var);
		}
		else
		{
			ft_lstadd_back(in->env_list,
				ft_new_node((void *) in->split_in[j],
					ft_strlen(in->split_in[j]) + 1));
		}
	}
}

void	export(t_input *in)
{
	char	**sub;
	int		j;

	if (in->split_in[1] == NULL)
	{
		env(in, 1);
		return ;
	}
	j = 1;
	while (in->split_in[j])
	{
		if (ft_strlen(in->split_in[j]) != 0)
		{	
			sub = ft_split(in->split_in[j], '=');
			if (*sub)
				export_sub(in, sub, j);
			fr_arr(sub);
		}
		else
			error_msg(in, "minishell: `': not a valid identifier", -1, 0);
		j++;
	}
	fr_arr(in->dup_env);
	in->dup_env = arr_list(*in->env_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:00:23 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/20 14:09:36 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_var_aux(t_input *in)
{
	if (in->f.i > 1 && in->split_in[in->f.j][in->f.i] == '"'
		&& in->split_in[in->f.j][in->f.i - 2] == '"')
		return (2);
	if (in->split_in[in->f.j][in->f.i] == '"' && !in->f.double_q)
		return (2);
	if (in->split_in[in->f.j][in->f.i] == '"' && in->f.double_q)
		return (1);
	if (in->split_in[in->f.j][in->f.i] == '\'' && !in->f.single_q
		&& !in->f.double_q)
		return (1);
	if (in->split_in[in->f.j][in->f.i] == '\'' && in->f.single_q
		&& !in->f.double_q)
		return (1);
	if (in->split_in[in->f.j][in->f.i] == '?')
	{
		in->f.i--;
		return (0);
	}
	if (in->split_in[in->f.j][in->f.i] == '_')
	{
		in->f.i--;
		return (0);
	}
	else
		return (2);
}

void	reset_vars(t_input *in)
{
	ft_bzero(&in->f, sizeof(in->f));
}

void	handle_dollar(t_input *in)
{
	in->f.i++;
	quotes_state(in, in->split_in[in->f.j]);
}

void	handle_non_alnum(t_input *in)
{
	char	*aux;

	if (in->split_in[in->f.j][in->f.i] == '\0')
	{
		in->f.i--;
		return ;
	}
	if (in->split_in[in->f.j][in->f.i] == '$')
	{
		if (ft_isalnum(in->split_in[in->f.j][in->f.i + 1])
			&& in->split_in[in->f.j][in->f.i + 1] != '\0')
			return ;
		in->f.i--;
		return ;
	}
	check_var_aux(in);
	aux = del_str_pos(in->split_in[in->f.j], in->f.i - 1);
	free(in->split_in[in->f.j]);
	in->split_in[in->f.j] = ft_strdup(aux);
	free(aux);
}

void	handle_alnum(t_input *in)
{
	char	*aux;
	char	*var;

	aux = ft_substr(in->split_in[in->f.j], 0, in->f.i);
	var = get_expanded_var(in->split_in[in->f.j], in->f.i + 1);
	insert_exp_var(in, &var, &aux, in->f.j);
	in->f.i = in->f.count - 1;
}

void	expand_vars(t_input *in)
{
	reset_vars(in);
	while (in->split_in[in->f.j] != NULL)
	{
		in->f.i = 0;
		while (in->split_in[in->f.j][in->f.i] != '\0')
		{
			quotes_state(in, in->split_in[in->f.j]);
			if (in->split_in[in->f.j][in->f.i] == '$' && !in->f.single_q)
			{
				handle_dollar(in);
				if (!ft_isalnum(in->split_in[in->f.j][in->f.i]))
					handle_non_alnum(in);
				else
					handle_alnum(in);
			}
			in->f.i++;
		}
		in->f.j++;
	}
	in->split_in = quotes(in);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:54:03 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 14:59:46 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	quotes_state(t_input *in, char *str)
{
	if (str[in->f.i] == '"'
		&& !in->f.single_q && !in->f.double_q)
	{
		in->f.double_q = 1;
		return (1);
	}
	else if (str[in->f.i] == '"'
		&& !in->f.single_q && in->f.double_q)
	{	
		in->f.double_q = 0;
		return (1);
	}
	else if (str[in->f.i] == '\''
		&& !in->f.single_q && !in->f.double_q)
	{
		in->f.single_q = 1;
		return (1);
	}
	else if (str[in->f.i] == '\''
		&& in->f.single_q && !in->f.double_q)
	{
		in->f.single_q = 0;
		return (1);
	}
	return (0);
}

static char	*delete_quote(t_input *in, char *str)
{
	char	*final_str;
	int		j;
	int		i;

	final_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!quotes_state(in, str))
		{
			final_str[j] = str[i];
			j++;
		}
		i++;
	}
	final_str[j] = '\0';
	return (final_str);
}

void	initi(t_input *in, char *var, char *value)
{
	char	*tmp;

	tmp = ft_strjoin(var, value);
	in->split_in = malloc(sizeof(char *) * 3);
	in->split_in[0] = ft_strdup("export");
	in->split_in[1] = tmp;
	in->split_in[2] = NULL;
}

void	update_env_var(t_input *in, char *var, char *value)
{
	char	**sub_in;

	sub_in = NULL;
	if (in->split_in)
		sub_in = arr_dup(in->split_in);
	if (in->split_in)
		fr_arr(in->split_in);
	initi(in, var, value);
	export(in);
	fr_arr(in->split_in);
	in->split_in = NULL;
	in->split_in = sub_in;
}

char	**quotes(t_input *in)
{
	int		size;
	char	**result;
	char	*sub;
	int		i;

	size = arr_len(in->split_in);
	i = 0;
	result = (char **)malloc((size + 1) * sizeof(char *));
	while (in->split_in[i] != NULL)
	{
		ft_bzero(&in->f, sizeof(in->f));
		sub = delete_quote(in, in->split_in[i]);
		if (!ft_strncmp(in->split_in[i], sub, ft_strlen(sub)))
			in->q_state[i] = 0;
		else
			in->q_state[i] = 1;
		result[i] = sub;
		i++;
	}
	result[size] = NULL;
	update_env_var(in, "_=", result[size - 1]);
	fr_arr(in->split_in);
	in->split_in = result;
	return (result);
}

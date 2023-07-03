/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:00:23 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 15:46:36 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*******************************************************************************
* This function verifies the existence of a variable in a specific             *
* element of the 'split_in' array,considering various cases based on the       *
* surrounding quotes and specific characters.It returns different values       *
* to indicate the result of the verification process.                          *
******************************************************************************/

int	verify_var_sub(t_input *in)
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

/*******************************************************************************
* This function verifies the existence of a variable at the current position   *
* within a specific element of the 'split_in' array.                           *
* It checks if the character following '$' is alphanumeric,                    *
* and handles different cases accordingly.                                     *
******************************************************************************/

int	verify_var(t_input *in)
{
	in->f.i++;
	quotes_state(in, in->split_in[in->f.j]);
	if (!ft_isalnum(in->split_in[in->f.j][in->f.i]))
	{
		if (in->split_in[in->f.j][in->f.i] == '\0')
		{
			in->f.i--;
			return (2);
		}
		if (in->split_in[in->f.j][in->f.i] == '$')
		{
			if (ft_isalnum(in->split_in[in->f.j][in->f.i + 1])
				&& in->split_in[in->f.j][in->f.i + 1] != '\0')
				return (0);
			return (2);
		}
		return (verify_var_sub(in));
	}
	in->f.i--;
	return (0);
}

/*******************************************************************************
* This function handles the expansion of variables within a specific           *
* element of the 'split_in' array. It verifies the variable existence          *
* and either removes the variable substring or inserts the expanded variable.  *
******************************************************************************/

void	expand_vars_sub(t_input *in)
{
	int		check;
	char	*sub;
	char	*var;

	check = verify_var(in);
	if (check == 1)
	{
		sub = del_str_pos(in->split_in[in->f.j], in->f.i - 1);
		free(in->split_in[in->f.j]);
		in->split_in[in->f.j] = ft_strdup(sub);
		free(sub);
	}
	else if (check == 0)
	{
		sub = ft_substr(in->split_in[in->f.j], 0, in->f.i);
		var = get_expanded_var(in->split_in[in->f.j], in->f.i + 1);
		insert_exp_var(in, &var, &sub, in->f.j);
		in->f.i = in->f.count - 1;
	}
}

/*******************************************************************************
* This function expands variables within the 'split_in' array by iterating     *
* through each element. It sets the state of quotes for each element           *
* and checks for the presence of '$' character.If not within single quotes,    *
* it calls the 'expand_vars_sub' function to perform variable expansion.       *
* Finally, it updates the 'split_in' array by applying quotes to the elements. *
******************************************************************************/

void	expand_vars(t_input *in)
{
	ft_bzero(&in->f, sizeof(in->f));
	while (in->split_in[in->f.j] != NULL)
	{
		in->f.i = 0;
		while (in->split_in[in->f.j][in->f.i] != '\0')
		{
			quotes_state(in, in->split_in[in->f.j]);
			if (in->split_in[in->f.j][in->f.i] == '$' && !in->f.single_q)
				expand_vars_sub(in);
			in->f.i++;
		}
		in->f.j++;
	}
	in->split_in = quotes(in);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:51:14 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 15:35:43 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*******************************************************************************
* This function handles the verification of quotes in the 'user_in' string,    *
* updating the corresponding flags accordingly.                                *
******************************************************************************/

void	verify_quotes(t_input *in)
{
	if (in->user_in[in->f.i] == '"' && !in->f.single_q
		&& !in->f.double_q)
		in->f.double_q = 1;
	else if (in->user_in[in->f.i] == '"' && !in->f.single_q
		&& in->f.double_q)
		in->f.double_q = 0;
	else if (in->user_in[in->f.i] == '\'' && !in->f.single_q
		&& !in->f.double_q)
		in->f.single_q = 1;
	else if (in->user_in[in->f.i] == '\'' && in->f.single_q
		&& !in->f.double_q)
		in->f.single_q = 0;
}

/*******************************************************************************
* This function is a helper function for verifying additional                  *
* errors related to pipes. It checks for the presence of the same character    *
* (stored in 'c') or whitespace consecutively in the 'user_in' string,         *
* up to a maximum of 2 occurrences.If more than 2 occurrences are found, it    *
* displays a syntax error message. The function returns 1 if a syntax error    *
* is detected, otherwise it returns 0.                                         *
******************************************************************************/

int	verify_errors_pipes_aux(t_input *in)
{
	int		count;
	char	c;

	count = 0;
	c = '\0';
	if (!in->f.double_q && !in->f.single_q)
		c = in->user_in[in->f.i];
	else
		in->f.i++;
	while ((in->user_in[in->f.i] == c || in->user_in[in->f.i] == ' ')
		&& count < 2 && in->user_in[in->f.i])
	{
		if (in->user_in[in->f.i] == c)
			count++;
		in->f.i++;
	}
	if (count >= 2)
		error_msg(in, "Syntax error near unexpected token '|'", -2, 0);
	if (count >= 2)
		return (1);
	return (0);
}

/*******************************************************************************
* This function verifies the presence of error pipes in the 'user_in' string   *
* by iterating through each character and checking for the '|' symbol.         *
* It sets a flag when encountering a '|' and calls a helper function to        *
* verify any additional errors related to pipes. If a syntax error is detected *
* or if the first character is '|', an appropriate error message is displayed  *
* and the function returns 1. Otherwise, it returns 0.                         *
******************************************************************************/

int	verify_error_pipes(t_input *in)
{
	int	flag;

	flag = 0;
	while (in->user_in[in->f.i])
	{
		verify_quotes(in);
		if (in->user_in[in->f.i] == '|')
		{
			flag = 1;
			if (verify_errors_pipes_aux(in))
				return (1);
		}
		else
		{
			if (!char_sp(in->user_in[in->f.i]))
				flag = 0;
			in->f.i++;
		}
	}
	if (in->user_in[0] == '|' || flag == 1)
	{
		error_msg(in, "Syntax error near unexpected token '|'", -2, 0);
		return (1);
	}	
	return (0);
}

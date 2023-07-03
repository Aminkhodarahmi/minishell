/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:55:59 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 15:28:35 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	verify_error_redirs_sub(t_input *in, int i)
{
	if ((in->split_in[0][0] == '<' || in->split_in[0][0] == '>')
		&& in->split_in[1] == NULL)
		error_msg(in, "Syntax error near unexpected token `newLine",
			-2, 0);
	else if (in->split_in[i - 1][0] == '<' || in->split_in[i - 1][0] == '>')
		error_msg(in, "Syntax error near unexpected token `newLine",
			-2, 0);
	if (in->is_err)
		return (1);
	return (0);
}

int	verify_error_redirs(t_input *in)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (in->split_in[i])
	{
		len = ft_strlen(in->split_in[i]);
		if (len > 0 && in->split_in[i + 1] != NULL)
		{
			if (in->split_in[i][0] == '<' && in->split_in[i + 1][0] == '|')
				error_msg(in, "Syntax error near unexpected token '|'", -2, 0);
			else if (in->split_in[i][0] == '>' && in->split_in[i + 1][0] == '|')
				error_msg(in, "Syntax error near unexpected token '|'", -2, 0);
			else if (in->split_in[i][0] == '<' && in->split_in[i + 1][0] == '<')
				error_msg(in, "Syntax error near unexpected token '<'", -2, 0);
			else if (in->split_in[i][0] == '>' && in->split_in[i + 1][0] == '>')
				error_msg(in, "Syntax error near unexpected token '>'", -2, 0);
			if (in->is_err)
				return (1);
		}
		i++;
	}
	len = verify_error_redirs_sub(in, i);
	return (len);
}

/*********************************************************************
* This function verifies arguments, initializes necessary variables, *
* and prepares the input for further processing.                     *
**********************************************************************/

int	verify_args(t_input *in)
{
	int		input_size;

	if (!in->user_in)
		return (0);
	ft_bzero(&in->f, sizeof(in->f));
	input_size = count_tokens(in->user_in, in, 0);
	in->split_in = malloc(sizeof(char *) * (input_size + 1));
	in->q_state_size = input_size;
	free(in->q_state);
	in->q_state = malloc(sizeof(int) * in->q_state_size);
	if (!in->split_in)
		return (0);
	ft_bzero(&in->f, sizeof(in->f));
	count_tokens(in->user_in, in, 1);
	in->split_in[input_size] = NULL;
	if (verify_error_redirs(in))
		return (0);
	expand_vars(in);
	return (input_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:55:59 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/20 14:07:25 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_error_redirs_aux(t_input *in, int i)
{
	if ((in->split_in[0][0] == '<' || in->split_in[0][0] == '>')
		&& in->split_in[1] == NULL)
		error_msg(in, ERR_SYNTAX, -2, 0);
	else if (in->split_in[i - 1][0] == '<' || in->split_in[i - 1][0] == '>')
		error_msg(in, ERR_SYNTAX, -2, 0);
	if (in->is_err)
		return (1);
	return (0);
}

int	check_error_redirs(t_input *in)
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
				error_msg(in, ERR_SYNTAX_PIPE, -2, 0);
			else if (in->split_in[i][0] == '>' && in->split_in[i + 1][0] == '|')
				error_msg(in, ERR_SYNTAX_PIPE, -2, 0);
			else if (in->split_in[i][0] == '<' && in->split_in[i + 1][0] == '<')
				error_msg(in, ERR_SYNTAX_IN, -2, 0);
			else if (in->split_in[i][0] == '>' && in->split_in[i + 1][0] == '>')
				error_msg(in, ERR_SYNTAX_OUT, -2, 0);
			if (in->is_err)
				return (1);
		}
		i++;
	}
	len = check_error_redirs_aux(in, i);
	return (len);
}

int	check_args(t_input *in)
{
	int	input_size;

	if (!in->user_in)
		return (0);
	ft_bzero(&in->f, sizeof(in->f));
	input_size = count_tokens(in->user_in, in, 0);
	in->split_in = (char **)malloc(sizeof(char *) * (input_size + 1));
	if (!in->split_in)
		return (0);
	in->q_state_size = input_size;
	in->q_state = (int *)malloc(sizeof(int) * in->q_state_size);
	if (!in->q_state)
	{
		free(in->split_in);
		return (0);
	}
	ft_bzero(&in->f, sizeof(in->f));
	count_tokens(in->user_in, in, 1);
	in->split_in[input_size] = NULL;
	if (check_error_redirs(in))
	{
		free(in->split_in);
		free(in->q_state);
		return (0);
	}
	expand_vars(in);
	return (input_size);
}

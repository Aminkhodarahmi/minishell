/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:51:36 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/19 16:59:05 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	check_quotes(t_input *in)
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

char	get_quotes_char(t_input *in)
{
	char	c;

	c = '\0';
	if (!in->f.double_q && !in->f.single_q)
	{
		c = in->user_in[in->f.i];
		if (c == '<' || c == '>')
			return (c);
	}
	else
	{
		in->f.i++;
	}
	return (c);
}

int	should_return_due_to_pipe_char(char c)
{
	return (c == '<' || c == '>');
}

int	count_matching_chars(t_input *in, char c)
{
	int	count;

	count = 0;
	while ((in->user_in[in->f.i] == c || in->user_in[in->f.i] == ' ') \
			&& count < 2 && in->user_in[in->f.i])
	{
		if (in->user_in[in->f.i] == c)
			count++;
		in->f.i++;
	}
	return (count);
}

int	check_quotes_and_pipes_aux(t_input *in)
{
	int		count;
	char	c;

	c = get_quotes_char(in);
	if (should_return_due_to_pipe_char(c))
		return (1);
	count = count_matching_chars(in, c);
	if (count >= 2)
	{
		error_msg(in, ERR_SYNTAX_PIPE, -2, 0);
		return (1);
	}
	return (0);
}

void	update_quote_flags(t_input *in, char currentChar)
{
	if (currentChar == '"' && !in->f.single_q && !in->f.double_q)
		in->f.double_q = 1;
	else if (currentChar == '"' && !in->f.single_q && in->f.double_q)
		in->f.double_q = 0;
	else if (currentChar == '\'' && !in->f.single_q && !in->f.double_q)
		in->f.single_q = 1;
	else if (currentChar == '\'' && in->f.single_q && !in->f.double_q)
		in->f.single_q = 0;
}

int	check_error_pipes(t_input *in)
{
	int		flag;
	char	currentChar;

	flag = 0;
	while (in->user_in[in->f.i])
	{
		currentChar = in->user_in[in->f.i];
		update_quote_flags(in, currentChar);
		if (currentChar == '|')
		{
			flag = 1;
			if (check_quotes_and_pipes_aux(in))
				return (1);
		}
		else
		{
			if (!char_sp(currentChar))
				flag = 0;
			in->f.i++;
		}
	}
	if (in->user_in[0] == '|' || flag == 1)
	{
		error_msg(in, ERR_SYNTAX_PIPE, -2, 0);
		return (1);
	}
	return (0);
}

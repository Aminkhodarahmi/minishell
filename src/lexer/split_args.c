/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:53:02 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/20 14:08:10 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	split_args_aux2(t_input *in, char **final_in, char c)
{
	(*final_in)[in->f.count++] = ' ';
	(*final_in)[in->f.count++] = c;
	if (in->user_in[in->f.i + 1] == c)
	{
		(*final_in)[in->f.count++] = c;
		in->f.i += 1;
	}
	(*final_in)[in->f.count] = ' ';
}

void	split_args_aux(t_input *in, char **final_in)
{
	char	c;

	while (in->user_in[in->f.i] != '\0')
	{
		check_quotes(in);
		c = in->user_in[in->f.i];
		if (in->f.double_q == 0 && in->f.single_q == 0 \
				&& (c == '|' || c == '<' || c == '>'))
		{
			(*final_in)[in->f.count++] = ' ';
			(*final_in)[in->f.count++] = c;
			if (in->user_in[in->f.i + 1] == c)
			{
				(*final_in)[in->f.count++] = c;
				in->f.i += 1;
			}
			(*final_in)[in->f.count] = ' ';
		}
		else
			(*final_in)[in->f.count] = c;
		in->f.count++;
		in->f.i++;
	}
}

int	calculate_final_in_size(t_input *in)
{
	int		size;
	char	c;

	size = 0;
	ft_bzero(&in->f, sizeof(in->f));
	while (in->user_in[in->f.i] != '\0')
	{
		check_quotes(in);
		c = in->user_in[in->f.i];
		if (in->f.double_q == 0 && in->f.single_q == 0 \
				&& (c == '|' || c == '<' || c == '>'))
		{
			if (in->user_in[in->f.i + 1] == c)
				in->f.i++;
			size += 2;
		}
		in->f.i++;
	}
	return (size + in->f.i + 1);
}

void	split_args(t_input *in)
{
	int		final_in_size;
	char	*final_in;

	final_in_size = calculate_final_in_size(in);
	final_in = (char *)malloc(sizeof(char) * final_in_size);
	ft_bzero(&in->f, sizeof(in->f));
	split_args_aux(in, &final_in);
	final_in[in->f.count] = '\0';
	free(in->user_in);
	in->user_in = final_in;
}

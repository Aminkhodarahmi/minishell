/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:54:03 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 10:54:57 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	update_env_var(t_input *in, char *var, char *value)
{
	char	**aux_in;
	char	*tmp;

	aux_in = NULL;
	if (in->split_in)
		aux_in = matrix_dup(in->split_in);
	tmp = ft_strjoin(var, value);
	if (in->split_in)
		free_matrix(in->split_in);
	in->split_in = malloc(sizeof(char *) * 3);
	in->split_in[0] = ft_strdup("export");
	in->split_in[1] = tmp;
	in->split_in[2] = NULL;
	export(in);
	free_matrix(in->split_in);
	in->split_in = NULL;
	in->split_in = aux_in;
}

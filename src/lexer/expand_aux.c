/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:03:57 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/19 17:00:09 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*expand_variable(t_input *in, char *var, char *aux, int j)
{
	int		len1;
	int		len2;
	int		len3;
	char	*last;
	char	*expanded;

	len1 = ft_strlen(aux);
	len2 = ft_strlen(var);
	len3 = ft_strlen(in->split_in[j]);
	last = ft_substr(in->split_in[j], len1 + len2 + 1, len3 - len2 - len1);
	if (!(ft_strncmp(var, "?", 2)))
		expanded = ft_itoa(g_exit_status);
	else if (j > 0 && !(ft_strncmp(in->split_in[j - 1], "<<", 3)))
		expanded = ft_strdup(in->split_in[j]);
	else
		expanded = ft_getenv(var, in);
	free(var);
	if (!expanded)
		expanded = ft_strdup("");
	in->f.count = len1 + ft_strlen(expanded);
	free(last);
	return (expanded);
}

void	insert_exp_var(t_input *in, char **var, char **aux, int j)
{
	char	*expanded;
	char	*last;

	expanded = expand_variable(in, *var, *aux, j);
	last = ft_substr(in->split_in[j], ft_strlen(*aux) + ft_strlen(*var) + 1,
			ft_strlen(in->split_in[j]) - ft_strlen(*var) - ft_strlen(*aux));
	free(*var);
	free(*aux);
	free(in->split_in[j]);
	*var = expanded;
	*aux = ft_strjoin3(*aux, expanded, last);
	in->split_in[j] = ft_strdup(*aux);
	free(last);
}

char	*get_expanded_var(char *str, int i)
{
	char	*aux;
	int		j;

	j = i;
	if (str[i] == '?')
		return (aux = ft_strdup("?"));
	if (str[i] == '_')
		return (aux = ft_strdup("_"));
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	aux = ft_substr(str, j, i - j);
	return (aux);
}

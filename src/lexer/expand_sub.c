/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:03:57 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 15:40:15 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*******************************************************************************
* This function inserts the expanded variable into the                         *
* 'split_in' array at index 'j', combining it with the substrings 'sub' and    *
* 'last'. The value of 'expanded' depends on different conditions:If the       *
* variable is "?", 'expanded' is set to the string representation of 'g_quit'. *
* If the previous element is "<<", 'expanded'                                  *
* is a duplicate of 'in->split_in[j]'.                                         *
******************************************************************************/

void	insert_exp_var(t_input *in, char **var, char **sub, int j)
{
	int		len1;
	int		len2;
	int		len3;
	char	*last;
	char	*expanded;

	len1 = ft_strlen(*sub);
	len2 = ft_strlen(*var);
	len3 = ft_strlen(in->split_in[j]);
	last = ft_substr(in->split_in[j], len1 + len2 + 1, len3 - len2 - len1);
	if (!(ft_strncmp(*var, "?", 2)))
		expanded = ft_itoa(g_quit);
	else if (j > 0 && !(ft_strncmp(in->split_in[j - 1], "<<", 3)))
		expanded = ft_strdup(in->split_in[j]);
	else
		expanded = ft_getenv(*var, in);
	free(*var);
	if (!expanded)
		expanded = ft_strdup("");
	in->f.count = len1 + ft_strlen(expanded);
	free(in->split_in[j]);
	in->split_in[j] = ft_strjoin3(*sub, expanded, last);
	free(*sub);
	free(expanded);
	free(last);
}

/*******************************************************************************
* This function returns the expanded variable from a given position            *
* 'i' in the 'str' string. If the character at position 'i' is '?' or '_',     *
* it returns a duplicate string of that character.Otherwise, it iterates through
* alphanumeric characters and underscores starting from 'i',                   *
* and returns a substring containing the characters encountered.               *
******************************************************************************/

char	*get_expanded_var(char *str, int i)
{
	char	*sub;
	int		j;

	j = i;
	if (str[i] == '?')
		return (sub = ft_strdup("?"));
	if (str[i] == '_')
		return (sub = ft_strdup("_"));
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	sub = ft_substr(str, j, i - j);
	return (sub);
}

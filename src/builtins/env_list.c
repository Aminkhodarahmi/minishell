/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:51:02 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/24 23:09:04 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_getenv_sub(t_list *sub, char **var, int size_var)
{
	int	total_size;

	while (sub)
	{
		size_var = ft_strlen(*var);
		total_size = ft_strlen(sub->content);
		if (!(ft_strncmp(*var, sub->content, size_var)))
		{
			free(*var);
			return (ft_substr(sub->content, size_var, total_size - size_var));
		}
		sub = sub->next;
	}
	free(*var);
	return (NULL);
}

char	*ft_getenv(const char *str, t_input *in)
{
	t_list	*sub;
	char	*var;
	int		size_var;

	sub = *in->env_list;
	var = NULL;
	while (sub)
	{
		size_var = ft_strlen(str);
		if (!(ft_strncmp(str, sub->content, size_var))
			&& ((char *)sub->content)[size_var] == '\0')
		{
			var = ft_strdup(sub->content);
			free(sub->content);
			sub->content = ft_strjoin(var, "=");
			free(var);
			return (ft_getenv(str, in));
		}
		sub = sub->next;
	}
	sub = *in->env_list;
	var = ft_strjoin(str, "=");
	return (ft_getenv_sub(sub, &var, size_var));
}

void	init_basic_env(t_input *in, char **pwd)
{
	in->dup_env = malloc(sizeof(char *) * 5);
	in->dup_env[0]
		= ft_strdup("PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	in->dup_env[1] = ft_strjoin("PWD=", (*pwd));
	in->dup_env[2] = ft_strdup("SHLVL=0");
	in->dup_env[3] = ft_strdup("_=./minishell");
	in->dup_env[4] = NULL;
}

void	dup_env(t_input *in, char **environ)
{
	int		i;
	char	*pwd;

	i = 0;
	in->dup_env = NULL;
	pwd = getcwd(NULL, 0);
	if (!(*environ))
		init_basic_env(in, &pwd);
	else
	{
		while (environ[i] != NULL)
			i++;
		in->dup_env = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (environ[i])
		{
			in->dup_env[i] = ft_strdup(environ[i]);
			i++;
		}
		in->dup_env[i] = NULL;
	}
	free(pwd);
}

void	init_env_list(t_input *in, t_list **envp, char **environ)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	dup_env(in, environ);
	while (in->dup_env[i] != NULL)
	{
		size = ft_strlen(in->dup_env[i]);
		ft_lstadd_back(envp, ft_new_node((void *) in->dup_env[i], size + 1));
		i++;
	}
}

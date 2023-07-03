/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:30:51 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 15:02:00 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	get_path(t_input *in)
{
	char	*sub;

	in->path_unset = 0;
	sub = ft_getenv("PATH", in);
	in->split_path = ft_split(sub, ':');
	free(sub);
	if (!in->split_path)
	{
		in->path_unset = 1;
		in->split_path = ft_split(" . ", '.');
	}
	return (in->path_unset);
}

int	get_cmd_path(t_input *in)
{
	int		i;
	char	*sub;
	char	*path;

	i = -1;
	while (in->split_path[++i])
	{
		sub = ft_strjoin(in->split_path[i], "/");
		path = ft_strjoin(sub, in->split_in[0]);
		if ((access(path, F_OK)) == 0 && !ft_strncmp(path, "/", 1))
		{
			in->cmd_path = ft_strdup(path);
			free(sub);
			free(path);
			return (1);
		}
		free(sub);
		free(path);
	}
	return (0);
}

char	**dup_new_env(char **arrs, int size)
{
	char	**out;
	int		i;
	int		j;

	i = 0;
	out = malloc(sizeof(char *) * (size + 1));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (arrs[i])
	{
		if (ft_strchr(arrs[i], '='))
		{
			out[j] = ft_strdup(arrs[i]);
			j++;
		}
		i++;
	}
	out[j] = NULL;
	return (out);
}

void	exec_minishell(t_input *in)
{
	char	**new_env;
	int		size;
	int		i;

	if (in->total_pipes)
		exit (0);
	size = 0;
	i = -1;
	while (in->dup_env[++i])
	{
		if (ft_strchr(in->dup_env[i], '='))
			size++;
	}
	new_env = dup_new_env(in->dup_env, size);
	if (execve(in->split_in[0], in->split_in, new_env) == -1)
		error_msg(in, "command not found", 0, 0);
	fr_arr(new_env);
}

void	exec_cmd(t_input *in)
{
	get_path(in);
	in->cmd_path = NULL;
	if (get_cmd_path(in))
		execve(in->cmd_path, in->split_in, in->dup_env);
	else
	{
		if (in->path_unset == 0)
			error_msg(in, "command not found", 0, 0);
		else
			error_msg(in, "No such file or directory", 0, 0);
	}
}

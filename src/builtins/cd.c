/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:26:57 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/24 23:08:30 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cd_sub(t_input *in, char **pwd, char **home_path)
{
	if (*pwd)
		update_env_var(in, "OLDPWD=", *pwd);
	else
	{
		update_env_var(in, "OLDPWD=", "");
		if (errno)
		{	
			chdir("/");
			*pwd = getcwd(NULL, 0);
		}	
	}
	free(*pwd);
	*pwd = getcwd(NULL, 0);
	update_env_var(in, "PWD=", *pwd);
	free(*home_path);
	free(*pwd);
}

void	cd(t_input *in)
{
	char	*home_path;
	char	*pwd;

	home_path = ft_getenv("HOME", in);
	pwd = getcwd(NULL, 0);
	if (!in->split_in[1] || !(ft_strncmp(in->split_in[1], "", 2)))
	{
		if (chdir(home_path) == -1)
			error_msg(in, "HOME not set", 0, 0);
	}
	else if (chdir(in->split_in[1]) == -1)
	{
		if (errno == EACCES)
			error_msg(in, "Permission denied", 0, 0);
		if (errno == ENAMETOOLONG)
			error_msg(in, "File name too long", 1, 0);
		else
			error_msg(in, "No such file or directory", 1, 0);
	}
	cd_sub(in, &pwd, &home_path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:57 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 10:53:13 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_basic_vars(t_input *in)
{
	char	*aux;

	aux = ft_getenv("PATH", in);
	if (!aux)
		update_env_var(in, "PATH=",
			"/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	else
		free(aux);
	aux = ft_getenv("SHLVL", in);
	if (!aux)
		update_env_var(in, "SHLVL=", "0");
	else
		free(aux);
	check_basic_vars2(in);
}

void	init_structs(t_input *in, t_list **envp)
{
	in->env_list = envp;
	in->user_in = NULL;
	in->split_in = NULL;
	in->cmd_path = NULL;
	in->total_pipes = 0;
	in->fd_in = 0;
	in->fd_out = 0;
	in->status = 0;
	g_exit_status = 0;
}

void	update_level(t_input *in)
{
	int		level;
	char	*number;
	char	*aux;	

	aux = ft_getenv("SHLVL", in);
	level = ft_atoi(aux);
	if (level < 0)
	{
		ft_putstr_fd(SHELL, 2);
		if (level == -1)
			level++;
		ft_putendl_fd(ERR_SHLVL, 2);
	}
	free(aux);
	level++;
	number = ft_itoa(level);
	update_env_var(in, "SHLVL=", number);
	free(number);
}

int	main(int argc, char **argv, char **environ)
{
	t_input	in;
	t_list	*envp;

	envp = NULL;
	if (argc == 1)
	{
		init_env_list(&in, &envp, environ);
		init_structs(&in, &envp);
		check_basic_vars(&in);
		update_level(&in);
		while (1)
		{
			signal(SIGINT, handler);
			signal(SIGQUIT, SIG_IGN);
			in.status = 0;
			read_input(&in);
			unlink(".hd_tmp");
		}
	}
	else
	{
		in.split_in = argv;
		error_msg(&in, ERR_ARG, -1, 0);
	}
	return (0);
}

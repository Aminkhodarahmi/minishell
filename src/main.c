/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:57 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 11:31:57 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_quit;

void	verify_basic_vars2(t_input *in)
{
	char	*sub;

	sub = ft_getenv("PWD", in);
	if (!sub)
	{
		sub = getcwd(NULL, 0);
		update_env_var(in, "PWD=", sub);
		free(sub);
	}
	else
		free(sub);
	sub = ft_getenv("_", in);
	if (!sub)
		update_env_var(in, "_=", "env");
	else
		free(sub);
}

void	verify_basic_vars(t_input *in)
{
	char	*sub;

	sub = ft_getenv("PATH", in);
	if (!sub)
		update_env_var(in, "PATH=",
			"/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	else
		free(sub);
	sub = ft_getenv("SHLVL", in);
	if (!sub)
		update_env_var(in, "SHLVL=", "0");
	else
		free(sub);
	verify_basic_vars2(in);
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
	g_quit = 0;
}

void	update_level(t_input *in)
{
	int		level;
	char	*number;
	char	*sub;	

	sub = ft_getenv("SHLVL", in);
	level = ft_atoi(sub);
	if (level < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		if (level == -1)
			level++;
		ft_putendl_fd("warning: shell level too high, resetting to 1", 2);
	}
	free(sub);
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
		verify_basic_vars(&in);
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
		error_msg(&in, "Syntax error: unpaired quotes", -1, 0);
	}
	return (0);
}

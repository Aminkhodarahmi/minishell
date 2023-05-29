/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:19:59 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/29 19:25:13 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sig_interrupt(int signum, siginfo_t *sinfo, void *c)
{
	// implement behaviour
	// terminate program
	// new prompt
	// return (0);
}

void	sig_quit(int signum, siginfo_t *sinfo, void *c)
{
	// implement behaviour
	// if typing command do nothing
	// if command being executed -> quit program
	// return (0);
}

void	sig_terminate(int signum, siginfo_t *sinfo, void *c)
{
	// implement behaviour
	// exit the shell safely (free everything)
	// return (0);
}

// check for errors
void	init_signals(void)
{
	struct sigaction si;
	struct sigaction sq;
	struct sigaction st;
	
	si.sa_flags = SA_SIGINFO;
	sq.sa_flags = SA_SIGINFO;
	st.sa_flags = SA_SIGINFO;
	si.sa_sigaction = sig_interrupt;
	sq.sa_sigaction = sig_quit;
	st.sa_sigaction = sig_terminate;
	sigaction(SIGINT, &sig_interrupt, NULL);
	sigaction(SIGQUIT, &sig_quit, NULL);
	sigaction(SIGTERM, &sig_terminate, NULL);
}



void	init(t_shell *s)
{
	s->user = getenv("user");
	init_signals();
		
}

void	prompt(t_shell *s)
{
	s->prompt = readline("shell > ");
	// if selfmade
	
}

int	main(int argc, char **argv)
{
	t_shell	*shell;
	// check args
	if (argc != 1)
		return (1);
	// initialize
	shell = malloc(sizeof(t_shell));
	init(shell);
	// check signals
	
	// prompt
	prompt(shell);

	// tokenize command
	
	// execute command

	// free and exit
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:19:59 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/29 17:28:16 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init(t_shell *s)
{
	
}

int	main(int argc, char **argv)
{
	t_shell	shell;
	// check args
	if (argc != 1)
		return (1);
	// initialize
	
	init(shell);
	// check signals

	// tokenize command

	// execute command

	// free and exit
	return (0);
}
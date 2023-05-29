/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:12:09 by rnauke            #+#    #+#             */
/*   Updated: 2023/05/29 19:20:22 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <curses.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <readline/history.h>
# include <readline/readline.h>

extern void	rl_replace_line(const char *s, int i);

// structs
typedef struct s_shell
{
	char	*user;
	char	*cwd;
	int		exit_code;
	char	*prompt;
}	t_shell;
// function

#endif

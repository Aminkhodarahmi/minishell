/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:00:27 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 12:47:32 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <errno.h>

# define R_END 0
# define W_END 1

# define SHELL "minishell: "
# define IS_DIR "is a directory"
# define ERR_PIPE "Pipe error"
# define ERR_FORK "Fork error"
# define ERR_DUP "Dup error"
# define ERR_SYNTAX "Syntax error near unexpected token `newLine"
# define ERR_SYNTAX_PIPE "Syntax error near unexpected token '|'"
# define ERR_SYNTAX_IN "Syntax error near unexpected token '<'"
# define ERR_SYNTAX_OUT "Syntax error near unexpected token '>'"
# define ERR_CMD "command not found"
# define ERR_FILE "No such file or directory"
# define ERR_PERM "Permission denied"
# define ERR_BIN "cannot execute binary file"
# define ERR_HOME "HOME not set"
# define ERR_ID "not a valid identifier"
# define ERR_ID2 "minishell: `': not a valid identifier"
# define ERR_ARG "Syntax error: unpaired quotes"
# define ERR_ARG2 "too many arguments"
# define ERR_SHLVL "warning: shell level too high, resetting to 1"
# define ERR_TOOLONG "File name too long"
# define ERR_HDOC "here_doc: could not find here_doc file"

extern int	g_exit_status;

typedef struct s_arg
{
	int		*quotes;
	char	**arg;
}	t_arg;

typedef struct s_flags
{
	int	i;
	int	j;
	int	start;
	int	count;
	int	count_double;
	int	single_q;
	int	double_q;
	int	global_q;
	int	global_count;
	int	global_sp;
}	t_flags;

typedef struct s_input
{
	int		fd[2][2];
	int		status;
	int		fd_in;
	int		fd_out;
	int		is_err;
	int		is_infile;
	int		is_outfile;
	int		is_hdoc;
	int		back_stdout;
	int		path_unset;
	int		total_pipes;
	int		q_state_size;
	int		*q_state;
	char	*prompt;
	char	*user_in;
	char	*cmd_path;
	char	**split_path;
	char	**split_in;
	char	**dup_env;
	t_list	**env_list;
	t_flags	f;
}	t_input;

int		main(int argc, char **argv, char **environ);
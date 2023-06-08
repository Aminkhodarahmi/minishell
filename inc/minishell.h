/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:00:27 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/08 19:04:26 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include "../libft/libftplus/libftplus.h"

# define R_END 0
# define W_END 1

# define SHELL "minishell: "
# define IS_DIR "is a folder"
# define ERR_PIPE "Error occurred while using pipe"
# define ERR_FORK "Error occurred while forking"
# define ERR_DUP "Error occurred while duplicating file descriptor"
# define ERR_SYNTAX "Syntax error: unexpected token `newLine'"
# define ERR_SYNTAX_PIPE "Syntax error: unexpected token '|'"
# define ERR_SYNTAX_IN "Syntax error: unexpected token '<'"
# define ERR_SYNTAX_OUT "Syntax error: unexpected token '>'"
# define ERR_CMD "Command not found"
# define ERR_FILE "File or directory does not exist"
# define ERR_PERM "Permission denied"
# define ERR_BIN "Cannot execute binary file"
# define ERR_HOME "HOME environment variable not set"
# define ERR_ID "Not a valid identifier"
# define ERR_ID2 "minishell: `': not a valid identifier"
# define ERR_ARG "Syntax error: unpaired quotes"
# define ERR_ARG2 "Too many arguments"
# define ERR_SHLVL "Warning: shell level too high, resetting to 1"
# define ERR_TOOLONG "File name exceeds maximum length"
# define ERR_HDOC "here_doc: could not find here_doc file"

extern int	g_exit_status;

typedef struct s_flags
{
	int	i;
	int	j;
	int	count;
	int	count_double;
	int	single_q;
	int	double_q;
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:00:27 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/17 19:17:39 by akhodara         ###   ########.fr       */
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
# include "../libft/libft/libft.h"

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

int			main(int argc, char **argv, char **environ);
void		update_level(t_input *in);
void		expand_vars(t_input *in);
void		expand_vars_aux(t_input *in);
int			check_var(t_input *in);
void		exec_minishell(t_input *in);
int			quotes_state(t_input *in, char *str);
// static char	*delete_quote(t_input *in, char *str);
void		update_env_var(t_input *in, char *var, char *value);
char		**quotes(t_input *in);
int			check_var_aux(t_input *in);
char		*get_expanded_var(char *str, int i);
void		insert_exp_var(t_input *in, char **var, char **aux, int j);
int			count_tokens(char *s, t_input *in, int split);
void		init_structs(t_input *in, t_list **envp);
void		check_basic_vars(t_input *in);
void		check_basic_vars2(t_input *in);
void		exec_builtin_hdoc(t_input *in, t_list *arg_list);
int			update_g_exit_status(char *ERR, int is_abs);
int			error_msg(t_input *in, char *MSG, int n, int is_abs);
int			check_error_pipes(t_input *in);
int			check_errors_pipes_aux(t_input *in);
void		check_quotes(t_input *in);
void		update_env_var(t_input *in, char *var, char *value);
int			pair_quotes(t_input *in);
int			is_space(char *str);
void		read_in_aux(t_input *in);
void		input_work(t_input *in, char **user);
void		read_input(t_input *in);
int			char_sp(char c);
int			is_builtin2(t_input *in);
int			is_builtin(t_input *in);
void		my_exit(t_input *in);
void		delete_head(t_input *in);
void		check_redirs(t_input *in);
int			outfile(t_input *in, int i);
void		outfile_aux(t_input *in);
int			infile(t_input *in, int i);
void		infile_aux(t_input *in);
void		unset_from_list(t_input *in, char **var, int size_var);
void		split_args_aux2(t_input *in, char **final_in, char c);
void		split_args_aux(t_input *in, char **final_in);
void		split_args(t_input *in);
int			valid_id(char *str);
int			check_hdoc(t_input *in);
void		exec_hdoc(t_input *in);
void		here_doc(t_input *in, int i);
void		remove_redir(t_input *in, int i);
int			count_pipes(t_input *in);
int			check_error_redirs_aux(t_input *in, int i);
int			check_error_redirs(t_input *in);
int			check_args(t_input *in);
void		export_aux(t_input *in, char **aux, int j);
void		export(t_input *in);
void		env(t_input *in, int is_export);
char		*ft_getenv_aux(t_list *aux, char **var, int size_var);
char		*ft_getenv(const char *str, t_input *in);
void		init_basic_env(t_input *in, char **pwd);
void		dup_env(t_input *in, char **environ);
void		init_env_list(t_input *in, t_list **envp, char **environ);

#endif

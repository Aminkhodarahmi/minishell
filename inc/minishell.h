/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:00:27 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/25 15:02:00 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <errno.h>

extern int	g_quit;

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
	int	num;
	int	count_double;
	int	single_q;
	int	double_q;
	int	global_q;
	int	global_count;
	int	global_sp;
	int	count_num;
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
void		init_structs(t_input *in, t_list **envp);
void		verify_basic_vars(t_input *in);
void		verify_basic_vars2(t_input *in);
void		if_minishell(t_input *in);
void		handler(int code);
void		handler2(int code);
void		handler3(int code);
void		handler4(int code);
int			char_sp(char c);
void		count_tokens_sub(t_input *in, char *s, int start);
void		count_tokens_sub2(t_input *in, char *s, int start);
int			count_tokens(char *s, t_input *in, int split);
void		split_args_sub2(t_input *in, char **final_in, char c);
void		split_args_sub(t_input *in, char **final_in);
int			calculate_final_in_size(t_input *in);
void		split_args(t_input *in);
int			quotes_state(t_input *in, char *str);
void		initi(t_input *in, char *var, char *value);
void		update_env_var(t_input *in, char *var, char *value);
char		**quotes(t_input *in);
int			verify_var_sub(t_input *in);
int			verify_var(t_input *in);
void		expand_vars_sub(t_input *in);
void		expand_vars(t_input *in);
char		*get_expanded_var(char *str, int i);
void		insert_exp_var(t_input *in, char **var, char **sub, int j);
void		verify_quotes(t_input *in);
int			verify_errors_pipes_aux(t_input *in);
int			verify_error_pipes(t_input *in);
int			verify_error_redirs_sub(t_input *in, int i);
int			verify_error_redirs(t_input *in);
int			verify_args(t_input *in);
int			pair_quotes(t_input *in);
int			is_space(char *str);
void		read_in_sub(t_input *in);
void		input_work(t_input *in, char **user);
void		read_input(t_input *in);
void		infile_sub(t_input *in);
int			infile(t_input *in, int i);
void		outfile_sub(t_input *in);
int			outfile(t_input *in, int i);
void		exec_builtin_hdoc(t_input *in, t_list *arg_list);
void		child(t_input *in, t_list *sub_list, int index);
void		sub_pipex(t_input *in, t_list *sub_list, int index, int *flag);
void		kill_last_process(t_input *in, int flag);
void		pipex(t_input *in, t_list *arg_list);
void		remove_redir(t_input *in, int i);
void		here_doc(t_input *in, int i);
void		exec_hdoc(t_input *in);
int			verify_hdoc(t_input *in);
int			get_path(t_input *in);
int			get_cmd_path(t_input *in);
char		**dup_new_env(char **arrs, int size);
void		exec_minishell(t_input *in);
void		exec_cmd(t_input *in);
void		exec_absolute(t_input *in);
int			is_builtin2(t_input *in);
int			is_builtin(t_input *in);
void		exec_args(t_input *in);
int			count_pipes(t_input *in);
void		init_arg_list_sub(t_input *in, t_list **arg_list, int i[4]);
void		init_arg_list(t_input *in);
void		free_list(t_input *in, t_list *arg_list);
int			update_g_quit(char *ERR, int is_abs);
int			error_msg(t_input *in, char *MSG, int n, int is_abs);
void		delete_head(t_input *in);
void		unset_from_list(t_input *in, char **var, int size_var);
int			is_valid_id(char *str);
void		unset_sub2(t_input *in, char *var);
void		unset(t_input *in, int j);
void		pwd(t_input *in);
int			valid_id(char *str);
void		export_sub(t_input *in, char **sub, int j);
void		export(t_input *in);
int			str_is_digit(char *str);
int			verify_exit_args(t_input *in);
void		my_exit(t_input *in);
void		print_export(t_list **lst, int i);
void		env(t_input *in, int is_export);
char		*ft_getenv_sub(t_list *sub, char **var, int size_var);
char		*ft_getenv(const char *str, t_input *in);
void		verify_redirs(t_input *in);
void		init_basic_env(t_input *in, char **pwd);
void		dup_env(t_input *in, char **environ);
void		init_env_list(t_input *in, t_list **envp, char **environ);
void		print_echo(t_input *in, int i);
int			is_n(char *str);
void		is_multiple_n(t_input *in, int i);
void		echo(t_input *in);
void		cd_sub(t_input *in, char **pwd, char **home_path);
void		cd(t_input *in);

void		ft_lst_free(t_list *lst);

void		ft_lst_sort(t_list **lst, int (*cmp)());
void		fr_arr(char **arrs);
void		write_arr(char **arrs);
int			arr_len(char **arrs);
char		**arr_dup(char **arrs);
char		**arr_add_back(char **arrs, char *str);
char		**arr_list(t_list *lst);
char		*del_str_pos(char *str, int n);
char		**rm_arr_loc(char **arrs, int pos);
void		ft_put_hex(unsigned int num, const char format);
int			ft_print_hex(unsigned int num, const char format);
char		*ft_strjoin3(const char *s1, const char *s2, const char *s3);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftplus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:34:27 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/07 12:53:33 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPLUS_H
# define LIBFTPLUS_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

t_list	*ft_new_node(void *content, size_t size);
t_list	*ft_lstdup(t_list *lst);
void	ft_lst_free(t_list *lst);
void	ft_lst_sort(t_list **lst, int (*cmp)());
void	free_matrix(char **matrix);
void	print_matrix(char **matrix);
int		matrix_len(char **matrix);
char	**matrix_dup(char **matrix);
char	**matrix_add_back(char **matrix, char *str);
char	**list_to_matrix(t_list *lst);
char	*del_str_pos(char *str, int n);
char	**del_matrix_pos(char **matrix, int pos);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:54:09 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/17 19:13:10 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *nptr);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t nmemb, size_t size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_strcmp(const char *str1, const char *str2);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_itoa(int n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memset(void *b, int c, size_t len);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char const *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr_fd(char const *s, int fd);

char			**ft_split(char const *s, char c);

void			*ft_calloc(size_t nmemb, size_t size);

char			*ft_strdup(const char *s);

char			*ft_strjoin(const char *s1, const char *s2);

size_t			ft_strlcat(char *dest, const char *src, size_t len);

size_t			ft_strlcpy(char *dst, const char *src, size_t size);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

char			*ft_substr(const char *s, unsigned int start, size_t len);

int				ft_tolower(int c);

int				ft_toupper(int c);

size_t			ft_strlen(const char *s);

t_list			*ft_lstnew(void *content);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_front(t_list **alst, t_list *new);

void			ft_lstadd_back(t_list **alst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void*));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

char			*ft_strtrim(char const *s1, char const *set);

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*get_next_line(int fd);

char			*ft_uitoa(unsigned int n);

t_list			*ft_new_node(void *content, size_t size);

t_list			*ft_lstdup(t_list *lst);

void			ft_lst_free(t_list *lst);

void			ft_lst_sort(t_list **lst, int (*cmp)());

void			free_matrix(char **matrix);

void			print_matrix(char **matrix);

int				matrix_len(char **matrix);

char			**matrix_dup(char **matrix);

char			**matrix_add_back(char **matrix, char *str);

char			**list_to_matrix(t_list *lst);

char			*del_str_pos(char *str, int n);

char			**del_matrix_pos(char **matrix, int pos);

void			ft_put_hex(unsigned int num, const char format);

int				ft_print_hex(unsigned int num, const char format);

void			ft_put_ptr(uintptr_t num);

int				ft_print_ptr(unsigned long long ptr);

int				ft_print_u(unsigned int n);

int				check_type(char ch);

unsigned int	ft_print_di(int d);

unsigned int	ft_print_str(char *str);

unsigned int	ft_amin(va_list vl, const char format);

int				ft_printf(const char *format, ...);

char			*ft_strjoin3(const char *s1, const char *s2, const char *s3);

#endif
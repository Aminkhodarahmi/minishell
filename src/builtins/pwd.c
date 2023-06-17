/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:28:00 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/17 17:45:43 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_pwd(void)
{
	char	*s;

	s = NULL;
	s = getcwd(s, 256);
	ft_printf("%s\n", s);
	free(s);
	}
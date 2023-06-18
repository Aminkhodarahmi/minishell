/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:51:52 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/17 17:43:40 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// \ = SIGQUIT
// c = SIGINT
// d = EOF
void	im_handler(int sn)
{
	if (sn == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 1);
	if (sn == SIGINT)
		ft_putchar_fd('\n', 1);
}

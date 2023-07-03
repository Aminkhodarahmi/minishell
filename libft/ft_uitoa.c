/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:37:46 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/15 19:00:45 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//lengh of the number
int	ft_len_num(unsigned	int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

//unsigned int to ascci
char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_len_num(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		--len;
		num[len] = n % 10 + 48;
		n = n / 10;
	}
	return (num);
}

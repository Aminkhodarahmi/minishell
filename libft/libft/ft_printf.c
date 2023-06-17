/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:37:02 by akhodara          #+#    #+#             */
/*   Updated: 2023/06/15 18:53:09 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//check the type of input and return a digit
int	check_type(char ch)
{
	if (ch == 'c' || ch == 'C')
		return (1);
	if (ch == 's' || ch == 'S')
		return (2);
	if (ch == 'p' || ch == 'P')
		return (3);
	if (ch == 'd' || ch == 'D')
		return (4);
	if (ch == 'i' || ch == 'I')
		return (5);
	if (ch == 'u' || ch == 'U')
		return (6);
	if (ch == 'x')
		return (7);
	if (ch == 'X')
		return (8);
	if (ch == '%')
		return (9);
	else
		return (0);
}

//print %d and %i
unsigned int	ft_print_di(int d)
{
	char			*str_arg;
	unsigned int	len;

	str_arg = ft_itoa(d);
	ft_putstr_fd(str_arg, 1);
	len = ft_strlen(str_arg);
	free(str_arg);
	return (len);
}

//print %s
unsigned int	ft_print_str(char *str)
{
	unsigned int	len;

	len = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		len += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		len += ft_strlen(str);
	}
	return (len);
}

//it the main function witch manage what should be print
unsigned int	ft_amin(va_list vl, const char format)
{
	unsigned int	len_res;

	len_res = 0;
	if (check_type(format) == 1)
	{
		ft_putchar_fd(va_arg(vl, int), 1);
		len_res++;
	}
	else if (check_type(format) == 4 || check_type(format) == 5)
		len_res += ft_print_di(va_arg(vl, int));
	else if (check_type(format) == 2)
		len_res += ft_print_str(va_arg(vl, char *));
	else if (check_type(format) == 3)
		len_res += ft_print_ptr(va_arg(vl, unsigned long long));
	else if (check_type(format) == 6)
		len_res += ft_print_u(va_arg(vl, unsigned int));
	else if (check_type(format) == 7 || check_type(format) == 8)
		len_res += ft_print_hex(va_arg(vl, int), format);
	else if (check_type(format) == 9)
	{
		write(1, "%", 1);
		len_res++;
	}
	return (len_res);
}

//ft_printf function
int	ft_printf(const char *format, ...)
{
	va_list			vl;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	va_start(vl, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_amin(vl, format[i]);
		}
		else
		{
			write(1, &format[i], 1);
			len ++;
		}
		i++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarras <dacarras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:38:57 by dacarras          #+#    #+#             */
/*   Updated: 2024/11/10 20:34:06 by dacarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_filter(char const c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == 'd')
		count += ft_putnbr(va_arg(args, int));
	if (c == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count += ft_unsignednbr(va_arg(args, unsigned int));
	if (c == '%')
		count += ft_putchar('%');
	if (c == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), c);
	if (c == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), c);
	if (c == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	return (count);
}

int	ft_printf(char const *text, ...)
{
	va_list	args;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] == '%')
		{
			i++;
			res += ft_filter(text[i], args);
		}
		else
			res += ft_putchar(text[i]);
		i++;
	}
	va_end(args);
	return (res);
}

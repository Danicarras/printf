/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarras <dacarras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:05:45 by dacarras          #+#    #+#             */
/*   Updated: 2024/11/10 20:34:34 by dacarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long n, char c)
{
	unsigned long long	res;

	res = 0;
	if (n >= 16)
		res += ft_print_hex(n / 16, c);
	if (c == 'x')
		ft_putchar("0123456789abcdef"[n % 16]);
	if (c == 'X')
		ft_putchar("0123456789ABCDEF"[n % 16]);
	res++;
	return (res);
}

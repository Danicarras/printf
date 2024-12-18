/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarras <dacarras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:40:10 by dacarras          #+#    #+#             */
/*   Updated: 2024/11/10 20:34:45 by dacarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	neg;
	int	res;
	int	i;

	i = 0;
	if (n == -2147483648)
		i += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		neg = n * -1;
		i += write(1, "-", 1);
		i += ft_putnbr(neg);
	}
	else if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		res = n + 48;
		i += write(1, &res, 1);
	}
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_unsignednbr(unsigned int n)
{
	int	res;
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		res = n + 48;
		i += write(1, &res, 1);
	}
	return (i);
}

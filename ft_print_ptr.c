/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarras <dacarras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:42:09 by dacarras          #+#    #+#             */
/*   Updated: 2024/11/10 20:14:45 by dacarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long c)
{
	int		res;
	char	*mem;

	if (!c)
		return (ft_putstr("(nil)"));
	mem = "0x";
	res = 0;
	res += ft_putstr(mem);
	res += ft_print_hex(c, 'x');
	return (res);
}

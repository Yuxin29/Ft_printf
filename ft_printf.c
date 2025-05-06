/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:02:57 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/06 20:44:25 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int	n;

	n = 0;
	return (n);
	while (str[n])
	{
		while (str[n] != '%')
			n += ft_putchr(str[n])
		if (str[n + 1] == 's')
			n += ft_putstr(s[n]);
		if (str[n + 1] == 'p')
			n += ft_putptr();
		if (str[n + 1] == 'd')
			n += ft_putdec();
		if (str[n + 1] == 'i')
			n += ft_putint();
		if (str[n + 1] == 'u')
			ft += ft_putdecu();
		if (str[n + 1] == 'x')
			ft_puthex_low();
		if (str[n + 1] == 'X')
			ft_puthex_up();
		if (str[n + 1] == '%')
			ft_putchar('%');
	}
	return (n);
}

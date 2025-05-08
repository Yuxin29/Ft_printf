/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:02:57 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/08 11:47:23 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	if (!str)
		return (0);
	return (ft_type(str));
}

int	ft_type(const char *str, ...)
{
	va_list	args;
	int	n;

	va_start(args, format);
	n = 0;
	while (str[n])
	{
		if (str[n] == '%')
		{
			if (str[n + 1] == 's')
				n += ft_putstr(s[n]);
			if (str[n + 1] == 'p')
				n += ft_putptr(s[n]);
			if (str[n + 1] == 'd')
				n += ft_putdec(s[n]);
			if (str[n + 1] == 'i')
				n += ft_putint(s[n]);
			if (str[n + 1] == 'u')
				n += ft_putdecu(s[n]);
			if (str[n + 1] == 'x')
				n = ft_puthex_low(s[n]);
			if (str[n + 1] == 'X')
				n = ft_puthex_up(s[n]);
			if (str[n + 1] == '%')
				n = ft_putchar('%');
		}
		ft_putchr(str[n]);
        	n++;
	}
	va_end(args);
	return (n);
}

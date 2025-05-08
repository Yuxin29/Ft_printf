/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:02:57 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/08 17:51:00 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	if (!str)
		return (0);
	ca_start(args, str);
	result = ft_type(str);
	va_end(args);
	return (result);
}

int	ft_type(const char *str)
{
	int		n;
	int		re_value;

	n = 0;
	re_value = 0;
	while (str[n])
	{
		if (str[n] == '%' && str[n + 1])
		{
			n++;
			if (str[n] == 's')
				re_value += ft_putstr(va_arg(args, char *));
			if (str[n] == 'p')
				re_value += ft_putptr(va_arg(args, void *));
			if (str[n] == 'd')
				re_value += ft_putdec(va_arg(args, int));
			if (str[n] == 'i')
				re_value += ft_putint(va_arg(args, int));
			if (str[n] == 'u')
				re_value += ft_putdecu(va_arg(args, unsigned int));
			if (str[n] == 'x')
				re_value += ft_puthex_low(va_arg(args, unsigned int));
			if (str[n] == 'X')
				re_value += ft_puthex_up(va_arg(args, unsigned int));
			if (str[n] == '%')
				re_value += ft_putchar('%');
		}
		re_value += ft_putchr(str[n]);
       	n++;
	}
	return (re_value);
}

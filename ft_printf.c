/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:02:57 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/09 13:34:05 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_type(const char *str, va_list args)
{
	int		n = 0;
	int		re_value = 0;

	while (str[n])
	{
		if (str[n] == '%' && str[n + 1])
		{
			n++;
			if (str[n] == 's')
				re_value += ft_putstr(va_arg(args, char *));
		/*	else if (str[n] == 'p')
				re_value += ft_putptr(va_arg(args, void *));
		*/	else if (str[n] == 'd')
				re_value += ft_putdec(va_arg(args, int));
			else if (str[n] == 'i')
				re_value += ft_putint(va_arg(args, int));
		/*	else if (str[n] == 'u')
				re_value += ft_putdecu(va_arg(args, unsigned int));
			else if (str[n] == 'x')
				re_value += ft_puthexlower(va_arg(args, unsigned int));
			else if (str[n] == 'X')
				re_value += ft_puthexupper(va_arg(args, unsigned int));
		*/	else if (str[n] == '%')
				re_value += ft_putchar('%');
		}
		else
			re_value += ft_putchar(str[n]);
		n++;
	}
	return (re_value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	if (!str)
		return (0);
	va_start(args, str);
	result = ft_type(str, args);
	va_end(args);
	return (result);
}

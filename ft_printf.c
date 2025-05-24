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

#include "ft_printf.h"

static int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd')
		return (ft_putdec(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putint(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putdecu(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexlower(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_puthexupper(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_type(const char *str, va_list args)
{
	int		re_value;
	int		check;

	re_value = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 0)
				return (-1);
			check = ft_format(*str, args);
			if (check == -1)
				return (-1);
			re_value += check;
		}
		else
		{
			if (ft_putchar(*str) == -1)
				return (-1);
			re_value += 1;
		}
		str++;
	}
	return (re_value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	if (!str)
		return (-1);
	va_start(args, str);
	result = ft_type(str, args);
	va_end(args);
	return (result);
}

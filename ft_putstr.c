/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:08:34 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/10 15:34:17 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;
	int	check;

	check = 0;
	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		check = ft_putchar(*s);
		if (check == -1)
			return (-1);
		count += check;
		s++;
	}
	return (count);
}

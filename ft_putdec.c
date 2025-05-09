/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:22:39 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/08 12:34:29 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c);
int	ft_putstr(char *s);

int	ft_putdec(int i)
{
	int	count;

	count = 0;
	if (i == -2147483648)
		return (ft_putstr("-2147483648"));
	if (i < 0)
	{
		i = -i;
		count += ft_putchar('-');
	}
	while (i >= 1)
	{
		count += ft_putchar((i % 10) + '0');
		i = i / 10;
	}
	return (count);
}

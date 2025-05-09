/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:16:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/09 13:38:40 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c);
int	ft_putstr(char *s);

int	ft_putint(int i)
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

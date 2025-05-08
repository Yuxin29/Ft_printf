/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:16:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/08 15:58:48 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);

int	ft_putint(i)
{
	int	count;

	count = 0;
	if (n_int == -2147483648)
	{	
		ft_putstr("-2147483648");
		count = 12;
		return (count);
	}
	if (i < 0)
	{
		i = -i;
		i += ft_putchar('-');
	}
	if (i >= 10)
		count += ft_putint(i / 10);
	count += ft_putchar((i % 10) + '0');
	return (count);
}

int	main(void)
{
	int	tes1;
	int	tes2;

	tes1 = ft_putint(122);
	write(1, "\n", 1);
	tes2 = ft_putint(-2147483648);
	write(1, "\n", 1);
	printf("%d\n", tes1);
	printf("%d\n", tes2);
	return (0);
}

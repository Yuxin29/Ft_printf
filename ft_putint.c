/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:16:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/08 14:01:41 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char	c);
int	ft_putstr(char *s);

int	ft_putint(int n_int)
{
	char	c;
	int		i;

	if (n_int == -2147483648)
	{	
		ft_putstr("-2147483648");
		return (12);
	}
	i = 0;
	if (n_int < 0)
	{
		n_int = -n_int;
		i += ft_putchar('-');
	}
	while (n_int > 1)
	{
		c = (n_int / 10) + '0';
		i += ft_putchar(c);
		n_int = n_int / 10;
	}
	return (i);	
}

#include <stdio.h>
int	main(void)
{
	int	tes1;
	int	tes2;

	tes1 = ft_putint(555);
	write(1, "\n", 1);
	tes2 = ft_putint(-2147483648);
	write(1, "\n", 1);
	printf("%d\n", tes1);
	printf("%d\n", tes2);
	return (0);
}

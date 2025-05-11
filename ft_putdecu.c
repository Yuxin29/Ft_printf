/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:43:47 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/09 11:44:59 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdecu(unsigned int i)
{
	int	count;
	int	check;

	count = 0;
	if (i == 0)
	{
		check = ft_putchar('0');
		if (check == -1)
			return (-1);
		return (check);
	}
	if (i >= 10)
	{
		check = ft_putdecu(i / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = ft_putchar((i % 10) + '0');
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}

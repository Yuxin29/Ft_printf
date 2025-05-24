/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:16:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/10 19:11:49 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_positive_char(unsigned int n)
{
	int		count;
	int		n_temp;
	char	*nbr;

	n_temp = n;
	count = 0;
	while (n_temp >= 1)
	{
		n_temp /= 10;
		count++;
	}
	nbr = malloc(sizeof(char) * (count + 1));
	if (!nbr)
		return (NULL);
	nbr[count] = '\0';
	while (count > 0)
	{
		nbr[count - 1] = (n % 10) + '0';
		n = n / 10;
		count--;
	}
	return (nbr);
}

static int	ft_special(int i)
{
	if (i == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (11);
	}
	if (i == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int	ft_putint(int i)
{
	int		count;
	char	*nbr;
	int		check;

	count = 0;
	check = 0;
	if (i == 0 || i == -2147483648)
		return (ft_special(i));
	if (i < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count += 1;
		i = -i;
	}
	nbr = get_positive_char(i);
	if (!nbr)
		return (-1);
	check = ft_putstr(nbr);
	free (nbr);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}

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

int	ft_putint(int i)
{
	int		count;
	char	*nbr;

	count = 0;
	if (i == -2147483648)
		return (ft_putstr("-2147483648"));
	if (i == 0)
		return (ft_putchar('0'));
	if (i < 0)
	{
		count += ft_putchar('-');
		i = -i;
	}
	nbr = get_positive_char(i);
	count += ft_putstr(nbr);
	free (nbr);
	return (count);
}

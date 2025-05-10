/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:45:11 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/10 18:29:02 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_posi_hex(unsigned int n)
{
	int				count;
	unsigned int	n_temp;
	char			*nbr;

	n_temp = n;
	count = 0;
	while (n_temp >= 1)
	{
		n_temp /= 16;
		count++;
	}
	nbr = malloc(sizeof(char) * (count + 1));
	if (!nbr)
		return (NULL);
	nbr[count] = '\0';
	while (n > 0)
	{
		count--;
		if ((n % 16) >= 10)
			nbr[count] = (n % 16) - 10 + 'a';
		else
			nbr[count] = (n % 16) + '0';
		n = n / 16;
	}
	return (nbr);
}

int	ft_puthexlower(unsigned int i)
{
	int		count;
	char	*trans;

	if (i == 0)
		return (ft_putchar('0'));
	trans = get_posi_hex(i);
	count = ft_putstr(trans);
	free (trans);
	return (count);
}

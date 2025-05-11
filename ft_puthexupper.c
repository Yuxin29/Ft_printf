/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:58:39 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/10 18:32:18 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_zero(void)
{
	char		*nbr;

	nbr = malloc(sizeof(char) * 2);
	if (!nbr)
		return (NULL);
	nbr[0] = '0';
	nbr[1] = '\0';
	return (nbr);
}

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
			nbr[count] = (n % 16) - 10 + 'A';
		else
			nbr[count] = (n % 16) + '0';
		n = n / 16;
	}
	return (nbr);
}

int	ft_puthexupper(unsigned int i)
{
	int		count;
	char	*trans;

	if (i == 0)
	{
		trans = get_zero();
		if (!trans)
			return (-1);
		count = ft_putstr(trans);
		free (trans);
		if (count == -1)
			return (-1);
		return (count);
	}
	trans = get_posi_hex(i);
	if (!trans)
		return (-1);
	count = ft_putstr(trans);
	free (trans);
	if (count == -1)
		return (-1);
	return (count);
}

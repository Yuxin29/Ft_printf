/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:02:39 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/10 19:55:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %p The void * pointer argument has to be printed in hexadecimal format

#include "ft_printf.h"

static char	*get_posi_hex(unsigned long n)
{
	int				count;
	unsigned long	n_temp;
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

unsigned long	puthexlower(unsigned long i)
{
	int		count;
	char	*trans;

	trans = get_posi_hex(i);
	count = ft_putstr(trans);
	free (trans);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;
	int				check;

	check = 0;
	if (!ptr)
	{
		if (ft_putstr("(nil)") == -1)
			return (-1);
		return (5);
	}
	address = (unsigned long)ptr;
	if (address == 0)
	{
		if (ft_putstr("0x0") == -1)
			return (-1);
		return (3);
	}
	count = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	check = puthexlower(address);
	if (check == -1)
		return (-1);
	return (2 + check);
}

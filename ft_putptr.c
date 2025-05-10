/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:02:39 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/10 17:09:36 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %p The void * pointer argument has to be printed in hexadecimal format

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

int	puthexlower(unsigned int i)
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

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	if (address == 0)
		return (write(1, "0x0", 3));
	count = 0;
	count += ft_putstr("0x");
	count += puthexlower(address);
	return (count);
}

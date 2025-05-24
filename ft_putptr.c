/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:02:39 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/12 18:42:55 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %p The void * pointer argument has to be printed in hexadecimal format

#include "ft_printf.h"

static char	*get_zero(void)
{
	char	*nbr;

	nbr = malloc(sizeof(char) * 2);
	if (!nbr)
		return (NULL);
	nbr[0] = '0';
	nbr[1] = '\0';
	return (nbr);
}

static int	get_length(uintptr_t n)
{
	int	count;

	count = 0;
	while (n >= 1)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static char	*get_posi_hex(uintptr_t n)
{
	int		count;
	char	*nbr;

	if (n == 0)
		return (get_zero());
	count = get_length(n);
	nbr = malloc(sizeof(char) * (count + 1));
	if (!nbr)
		return (NULL);
	nbr[count] = '\0';
	while (n > 0)
	{
		if ((n % 16) >= 10)
			nbr[--count] = (n % 16) - 10 + 'a';
		else
			nbr[--count] = (n % 16) + '0';
		n = n / 16;
	}
	return (nbr);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	address;
	int			count;
	char		*trans;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (uintptr_t)ptr;
	if (ft_putstr("0x") == -1)
		return (-1);
	trans = get_posi_hex(address);
	if (!trans)
		return (-1);
	count = ft_putstr(trans);
	free (trans);
	if (count == -1)
		return (-1);
	return (2 + count);
}

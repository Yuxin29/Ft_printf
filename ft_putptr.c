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

static void	ft_reverse(char *s)
{
	int		t;
	int		r;
	char	temp;

	r = 0;
	t = 0;
	while (s[t])
		t++;
	t--;
	while (r <= t)
	{
		temp = s[t];
		s[t] = s[r];
		s[r] = temp;
		r++;
		t--;
	}
}

static char	*ft_transfer(unsigned long i)
{
	char	*buffer;
	int		index;

	buffer = malloc(sizeof(char) * 17);
	if (!buffer)
		return (NULL);
	index = 0;
	while (i >= 1)
	{
		if ((i % 16) >= 10)
			buffer[index] = ((i % 16) - 10) + 'a';
		else
			buffer[index] = (i % 16) + '0';
		i = i / 16;
		index += 1;
	}
	buffer[index] = '\0';
	ft_reverse(buffer);
	return (buffer);
}

static int	puthexlower(unsigned long i)
{
	int		count;
	char	*trans;

	if (i == 0)
		return (ft_putchar('0'));
	trans = ft_transfer(i);
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

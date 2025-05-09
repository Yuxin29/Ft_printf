/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:02:39 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/08 12:21:13 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %p The void * pointer argument has to be printed in hexadecimal format

#include "ft_printf.h"
#include <stdio.h>

static char	ft_numtoalpha(int nbr)
{
	char	c;

	if (nbr >= 10)
		c = (nbr - 10) + 'a';
	else
		c = nbr + '0';
	return (c);
}

static void	ft_reverse(char *s)
{
	int		t;
	int		r;
	char	temp;

	r = 0;
	t = 0;
	while (s[t])
		t++;
	t -= 1;
	while (r <= t / 2)
	{
		temp = s[t];
		s[r] = s[t - r];
		s[t - r] = temp;
		r++;
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
		buffer[index] = ft_numtoalpha(i % 16);
		i = i / 16;
		index += 1;	
	}
	ft_reverse(buffer);
	buffer[index] = '\0';
	return (buffer);
}

int	ft_putptr(void *ptr)
{
	unsigned long 	address;
	char		*addr;
	int	count;

	address = (unsigned long)ptr;
	if (address == 0)
		return (write(1, "0x0", 3));
	addr = ft_transfer(address);
	count = ft_putstr(addr);
	free (addr);
	return (count);
}

/*
int	main(void)
{
	char	*test;
	
	test = "seven";
	printf("%s\n", test);
	printf("%p\n", &test);
	ft_putptr(&test);
	return (0);
}
*/

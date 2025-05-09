/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:58:39 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/09 11:59:28 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	ft_numtoalpha(int nbr)
{
	char	c;
	
	if (nbr >= 10)
		c = (nbr - 10) + 'A';
	else
		c = nbr + '0';
	return (c);
}

static void ft_reverse(char *s)
{
	int	t;
	int	r;
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

static char *ft_transfer(unsigned int i)
{
	char	*buffer;
	int	index;
	
	buffer = malloc(sizeof(char) * 17);
	if (!buffer)
		return (NULL);
	index = 0;
	while (i >= 1)
	{
		buffer[index] = ft_numtoalpha(i % 16);
		i = i / 16;
		index++;		
	}
	ft_reverse(buffer);
	buffer[index] = '\0';
	return (buffer);
}

int	ft_puthexupper(unsigned int i)
{
	int count;
	char	*trans;
	
	trans = ft_transfer(i);
	count = ft_putstr(trans);
	free (trans);
	return (count);
}

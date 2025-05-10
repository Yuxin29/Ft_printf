/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:45:11 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/09 16:05:40 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*ft_transfer(unsigned int i)
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

int	ft_puthexlower(unsigned int i)
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

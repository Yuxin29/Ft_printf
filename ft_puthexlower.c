/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:45:11 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/09 11:46:14 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char *ft_transfer(unsigned int i)
{
	char	*buffer;
	int	index;
	
	buffer = malloc(sizeof(char) * 17);
	if (!buffer)
		return (NULL);
	index = 0;
	while (i > 1)
	{
		buffer[index] = i % 16;
		i = i / 16;
		index++;		
	}
	buffer[index] = '\n';
	return (buffer);
}

int	ft_puthexlower(unsigned int i)
{
	int count;
	char	*trans;
	
	trans = ft_transfer(i);
	count = ft_putchar(*trans);
	free (trans);
	return (count);
}

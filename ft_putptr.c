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

//• %p The void * pointer argument has to be printed in hexadecimal format

#include "libftprintf.h"

int	ft_putptr(void *ptr)
{
	char		buffer[16];
	unsigned long *address;

	address = (unsigned long char)ptr;
	if (address == 0)
		return (write(1, "0x0", 3));
	while (*address)
	{
		*buffer = *address;
		address++;
		buffer++;
	}
	ft_putstr(1, buffer, 16);
	return (16);
}

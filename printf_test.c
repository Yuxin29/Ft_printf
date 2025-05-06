/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:53:50 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/06 20:02:16 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char	*ptr;

	ptr = "test";
	printf("%c\n", 'a');
	printf("%s\n", "aa");
	printf("%p\n", ptr);
	printf("%d\n", 999);
	printf("%i\n", -22);
	printf("%u\n", 33);
	printf("%x\n", 255);
	printf("%X\n", 255);
	printf("%%\n");
	return (0);
}

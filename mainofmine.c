/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainofmine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:53:50 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/09 13:31:40 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	char	*ptr;

	ptr = "test";
	printf("%c\n", 'a');
	printf("%s\n", "aa");
	printf("%p\n", &ptr);
	printf("%d\n", 999);
	printf("%i\n", -22);
	printf("%u\n", 33);
	printf("%x\n", 255);
	printf("%X\n", 255);
	printf("%%\n");
	printf("cspdiuxX");
	printf("Age: %d\n", 25);
    	printf("Height: %d\n", 163);
    	printf("Grade: %c\n", 'A');
	printf(NULL);
	ft_printf("ss\n");
	ft_printf("%i\n", 33);
	ft_printf("%d\n", 33);
	ft_printf("%u\n", 33);
	ft_printf("%x\n", 255);
	return (0);
}

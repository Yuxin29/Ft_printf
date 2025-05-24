/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:26:52 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/08 18:01:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr);
int	ft_putint(int i);
int	ft_putdec(int i);
int	ft_putdecu(unsigned int i);
int	ft_puthexlower(unsigned int i);
int	ft_puthexupper(unsigned int i);

#endif

/* ************************************************************************** 
 macros: used to define new_datas: 
		object-like, function-like, variadic like macros
//va        variable arguments
//va_list   a type of iterating arguments
//va_start  initializes the argument list
//va_arg    get variable argument and retrieve the next arg in the list
//va_end    end variable and clean up
** ************************************************************************ */

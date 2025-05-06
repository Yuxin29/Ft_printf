/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:26:52 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/06 20:16:01 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> //handling variable arguements

//main ft
int	ft_printf(const char *, ...);

//helper ft
int	ft_putchar(char	c);
int	ft_putstr(char *s);
int	ft_putint(int n_int);

//va_start
//va_arg
//va_copy
//va_end

#endif

/* ************************************************************************** **
 macros: used to define new_datas: 
		object-like, function-like, variadic like macros

** ************************************************************************** */

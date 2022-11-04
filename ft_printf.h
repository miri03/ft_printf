/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:58:25 by meharit           #+#    #+#             */
/*   Updated: 2022/11/04 02:36:49 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//#include "libft/libft.h"
#include <stdarg.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
int		ft_putchar_fd(char c, int fd, int *count);
int		ft_printf(const char* s, ...);
# endif

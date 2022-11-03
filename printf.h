/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:58:25 by meharit           #+#    #+#             */
/*   Updated: 2022/11/03 09:13:50 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//#include "libft/libft.h"
#include <stdarg.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
int		ft_putchar_fd(char c, int fd, int *count);

# endif

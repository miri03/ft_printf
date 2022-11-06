/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:58:25 by meharit           #+#    #+#             */
/*   Updated: 2022/11/06 13:54:45 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include<unistd.h>

void	to_hex(unsigned long d, char c, int *count);
void	ft_putnbr_fd(int n, int *count);
int		is_unsigned(unsigned int d, int *i);
void	ft_putstr_fd(char *s, int *count);
int		ft_putchar_fd(char c, int *count);
int		ft_printf(const char *s, ...);
void	to_hex(unsigned long d, char c, int *count);
void	ft_unsignbr(unsigned int n, int *count);
int		is_decimal(int dec, int *i);
int		is_string(char *s, int *i);
int		is_char(char c, int *i);
int		is_pointer(unsigned long d, char c, int *i);
void	ft_put(va_list ptr, char c, int *i, int *count);
size_t	ft_strlen(const char *s);


#endif

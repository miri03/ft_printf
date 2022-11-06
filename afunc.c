/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:46:51 by meharit           #+#    #+#             */
/*   Updated: 2022/11/06 13:55:05 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_unsigned(unsigned int d, int *i)
{
	int	count;

	count = 0;
	*i = *i + 1;
	ft_unsignbr(d, &count);
	return (count);
}

void	to_hex(unsigned long d, char c, int *count)
{
	char	*base;
	char	*up_base;

	base = "0123456789abcdef";
	up_base = "0123456789ABCDEF";
	if (d >= 16)
		to_hex(d / 16, c, count);
	if (c == 'X')
		ft_putchar_fd(up_base[d % 16], count);
	else
		ft_putchar_fd(base[d % 16], count);
}

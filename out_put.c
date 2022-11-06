/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:28:21 by meharit           #+#    #+#             */
/*   Updated: 2022/11/06 13:57:37 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_unsignbr(unsigned int n, int *count)
{
	if (n >= 10)
		ft_unsignbr(n / 10, count);
	ft_putchar_fd(n % 10 + '0', count);
}

void	ft_putnbr_fd(int n, int *count)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", count);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', count);
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, count);
		ft_putchar_fd(n % 10 + '0', count);
	}
}

void	ft_putstr_fd(char *s, int *count)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", count);
		return ;
	}
	write(1, s, ft_strlen(s));
	*count = *count + ft_strlen(s);
}

int	ft_putchar_fd(char c, int *count)
{
	*count = *count + 1;
	write(1, &c, 1);
	return (*count);
}

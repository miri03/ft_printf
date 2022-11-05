/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:28:21 by meharit           #+#    #+#             */
/*   Updated: 2022/11/05 06:19:36 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// remove fd

#include"ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd, count);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd, count);
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd, count);
		ft_putchar_fd(n % 10 + '0', fd, count);
	}
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1, count);
		return ;
	}
	write(fd, s, ft_strlen(s));
	*count = *count + ft_strlen(s);
}

int	ft_putchar_fd(char c, int fd,int *count)
{
		*count = *count + 1;
		write(fd, &c, 1);
	//	printf("[in]%d\n", *count);
	return (*count);
}

void	to_hex(unsigned long d, char c, int *count)
{
//	printf("[in]%u		%u\n", d, d % 16);
	char base[] = "0123456789abcdef";
	char BASE[] = "0123456789ABCDEF";
	if (d >= 16)
		to_hex(d / 16, c,count);
	//ft_putstr_fd("0x", 1, count);
	if (c == 'X')
		ft_putchar_fd(BASE[d % 16], 1, count);
	else
		ft_putchar_fd(base[d % 16], 1, count);
}

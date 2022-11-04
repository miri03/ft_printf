/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:31:48 by meharit           #+#    #+#             */
/*   Updated: 2022/11/04 03:14:28 by meharit          ###   ########.fr       */
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


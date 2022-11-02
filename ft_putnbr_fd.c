/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:34:25 by meharit           #+#    #+#             */
/*   Updated: 2022/11/02 12:02:42 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include"libft.h"
#include "printf.h"
int	ft_putnbr_fd(int n, int fd)
{
	int count;

	count = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
			count++;
		}
		if (n >= 10)
		{
			count++;
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + '0', fd);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:34:25 by meharit           #+#    #+#             */
/*   Updated: 2022/11/02 14:19:54 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd, count);
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
			*count = *count + 1;
			ft_putnbr_fd(n / 10, fd, count);
		}
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

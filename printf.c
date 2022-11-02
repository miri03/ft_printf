/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:57:41 by meharit           #+#    #+#             */
/*   Updated: 2022/11/02 07:08:54 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"
#include<stdio.h>
int	ft_printf(const char *str, ...)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	va_list ptr;
	va_start (ptr, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
		while (str[i] && str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				ft_putchar_fd(str[i], 1);
				count++;
			}
			else
				ft_putchar_fd(str[i], 1);
				count++;
			i++;
		}
	}
	va_end(ptr);
	return (count);
}

int main()
{
	int i = printf("%%kb%%%js%\n");
	printf("%d",i);
}

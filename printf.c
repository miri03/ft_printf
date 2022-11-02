/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:57:41 by meharit           #+#    #+#             */
/*   Updated: 2022/11/02 14:26:56 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"
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
			{
				if (str[i] == 'd')
				{
					ft_putnbr_fd(va_arg(ptr, int), 1, &count);
					i++; //fucked up line
					count++; // the new fucked up line
				}
				if (str[i] == 's')
				{
				//	printf("first\n");
					ft_putstr_fd(va_arg(ptr, char *), 1, &count);
					i++;
					printf("in =%d",count);
					//count++; // the new fucked up line
				}
			// re	printf("\nafterr:");
				ft_putchar_fd(str[i], 1);
				count++;
			}
			i++;
		}
	}
	va_end(ptr);
	return (count);
}

#include<stdio.h>
int main()
{
	int a = 443644;
	int i = ft_printf("%s","0xA");
	printf("\n%d",i);
}

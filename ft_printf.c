/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:28:35 by meharit           #+#    #+#             */
/*   Updated: 2022/11/05 10:47:54 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int	is_decimal(int dec, int *i)
{
	int count;

	count = 0;
	*i = *i + 1;
	ft_putnbr_fd(dec, 1, &count);
	return (count);
}

int	is_string(char *s, int *i)
{
	int	count;

	count = 0;
	*i = *i + 1;
	ft_putstr_fd(s, 1,&count);
	return (count);
}

int	is_pointer(unsigned long d, char c , int *i)
{
	int	count;

	count = 0;
	*i = *i + 1;
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1, &count);
		to_hex(d, c,&count);
	}
	if (c == 'x' || c == 'X')
		to_hex((unsigned int)d, c, &count);
	return (count);
}

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
			count = ft_putchar_fd(str[i], 1, &count);
			i++;
		}
		while (str[i] && str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				count = ft_putchar_fd(str[i], 1, &count);
				i++; //try to remove it
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				count += is_decimal(va_arg(ptr, int), &i);
			}
			else if (str[i] == 's')
			{
				count += is_string(va_arg(ptr, char *), &i);
			}
			else if (str[i] == 'c')
			{
				count = ft_putchar_fd((char)va_arg(ptr, int), 1,&count);
				i++;
			}
			else if (str[i] == 'p' || str[i] == 'x' || str[i] == 'X')
				count += is_pointer((unsigned long)va_arg(ptr, void *), str[i], &i);
		}

	}
	va_end(ptr);
	return (count);
}
/*
#include<limits.h>
int main()
{
//	int	i = -1337; 
	printf("%llu\n", (unsigned long long)INT_MAX);
	int d = ft_printf(" %p \n", INT_MIN);
	int a = printf(" %p \n", INT_MIN);
	printf("mine = %d//sys = %d",d, a);
}
*/

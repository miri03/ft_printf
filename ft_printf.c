/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:57:41 by meharit           #+#    #+#             */
/*   Updated: 2022/11/04 03:21:15 by meharit          ###   ########.fr       */
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

/*
int	is_unsigned(unsigned int u, int *i)
{
	int	count;

	count = 0;
	*i =  *i + 1;
	ft_putnbr


// -2 -> 

*/
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
		//	printf("[count1]%d\n",count);
			i++;
		}
		while (str[i] && str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				count = ft_putchar_fd(str[i], 1, &count);
			//	printf("[count2]%d\n",count);
				i++; //try to remove it
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				count += is_decimal(va_arg(ptr, int), &i);
		//		printf("[count3]%d\n",count);
			}
			else if (str[i] == 's')
			{
			//	printf("[count4]%d\n",count);
				count += is_string(va_arg(ptr, char *), &i);
			}
			else if (str[i] == 'c')
			{
				count = ft_putchar_fd((char)va_arg(ptr, int), 1,&count);
		//		printf("[count1]%d\n",count);
				i++;
			}
		}

	}
	va_end(ptr);
	return (count);
}
#include<limits.h>
int main()
{
	int i = 0;
//	int i = ft_printf(" %s ", NULL);
	int a = printf(" %u ", -2);
	printf("mine = %d//sys = %d",i, a);
}
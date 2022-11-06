/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:28:35 by meharit           #+#    #+#             */
/*   Updated: 2022/11/06 14:24:47 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	is_string(char *s, int *i)
{
	int	count;

	count = 0;
	*i = *i + 1;
	ft_putstr_fd(s, &count);
	return (count);
}

int	is_char(char c, int *i)
{
	int	count;

	count = 0;
	*i = *i + 1;
	ft_putchar_fd(c, &count);
	return (count);
}

int	is_pointer(unsigned long d, char c, int *i)
{
	int	count;

	count = 0;
	*i = *i + 1;
	if (c == 'p')
	{
		ft_putstr_fd("0x", &count);
		to_hex(d, c, &count);
	}
	if (c == 'x' || c == 'X')
		to_hex((unsigned int)d, c, &count);
	return (count);
}

void	ft_output(va_list ptr, char c, int *i, int *count)
{
	if (c == '%')
		*count = *count + is_char(c, i);
	else if (c == 'd' || c == 'i')
		*count = *count + is_decimal(va_arg(ptr, int), i);
	else if (c == 's')
		*count = *count + is_string(va_arg(ptr, char *), i);
	else if (c == 'c')
		*count = *count + is_char((char)va_arg(ptr, int), i);
	else if (c == 'p' || c == 'x' || c == 'X')
		*count = *count + is_pointer((unsigned long)va_arg(ptr, void *), c, i);
	else if (c == 'u')
		*count = *count + is_unsigned(va_arg(ptr, unsigned int), i);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	ptr;

	count = 0;
	i = 0;
	va_start (ptr, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			count += is_char(str[i], &i);
		while (str[i] && str[i] == '%')
		{
			i++;
			if (str[i] == '%' || str[i] == 'd' || str[i] == 'i'
				|| str[i] == 's' || str[i] == 'c' || str[i] == 'p'
				|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
				ft_output(ptr, str[i], &i, &count);
		}
	}
	va_end(ptr);
	return (count);
}

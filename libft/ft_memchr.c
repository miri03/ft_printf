/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:09:43 by meharit           #+#    #+#             */
/*   Updated: 2022/10/28 21:15:16 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	p;
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	p = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == p)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

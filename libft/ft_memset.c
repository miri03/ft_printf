/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:37:25 by meharit           #+#    #+#             */
/*   Updated: 2022/10/28 21:58:17 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	q;
	char			*ptr;
	size_t			i;

	i = 0;
	ptr = (char *)b;
	q = (unsigned char) c;
	while (len > i)
	{
		ptr[i] = q;
		i++;
	}
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:27:47 by meharit           #+#    #+#             */
/*   Updated: 2022/10/28 21:56:12 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			*((char *)(dst + (len - 1))) = *((char *)(src + (len - 1)));
			len--;
		}
	}
	while (i < len)
	{
		*((char *)(dst + i)) = *((char *)(src + i));
		i++;
	}
	return (dst);
}

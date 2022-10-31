/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:12:11 by meharit           #+#    #+#             */
/*   Updated: 2022/10/28 22:24:25 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	len;

	j = 0;
	len = 0;
	while (len < dstsize && dst[len])
		len++;
	if (len == dstsize)
		return (len + ft_strlen(src));
	while (src[j] != '\0' && (len + 1 + j) < dstsize)
	{
		dst[len + j] = src[j];
		j++;
	}
	if (len < dstsize)
		dst[len + j] = '\0';
	return (len + ft_strlen(src));
}

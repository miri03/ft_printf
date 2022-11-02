/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:36:35 by meharit           #+#    #+#             */
/*   Updated: 2022/11/02 14:26:26 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (s != NULL && fd >= 0)
	{
		printf("len =%zu\n",ft_strlen(s));
		write(fd, "12345", ft_strlen(s));
	}
	*count = *count + ft_strlen(s);
}

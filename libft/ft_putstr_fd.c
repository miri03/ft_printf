/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:36:35 by meharit           #+#    #+#             */
/*   Updated: 2022/11/03 03:23:54 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
	*count = *count + ft_strlen(s);
}

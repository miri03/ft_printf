/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:19:48 by meharit           #+#    #+#             */
/*   Updated: 2022/10/29 20:10:46 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*alloc(char const *str, char const *set)
{
	int		i;
	int		size;
	int		len;
	char	*ptr;

	len = ft_strlen(str) - 1;
	size = 0;
	i = 0;
	while (str[i] && isinset(str[i], set))
	{
		size++;
		i++;
	}
	while (str[i] && isinset(str[len], set))
	{
		size++;
		len--;
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) - size + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		len;
	int		start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == 0)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	start = 0;
	ptr = alloc(s1, set);
	if (ptr == NULL)
		return (NULL);
	while (isinset(s1[start], set) && s1[start])
		start++;
	while (isinset(s1[len - 1], set) && s1[start])
		len--;
	i = 0;
	while (start < len)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

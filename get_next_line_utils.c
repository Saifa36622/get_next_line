/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeethon <smeethon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:01:25 by smeethon          #+#    #+#             */
/*   Updated: 2022/12/28 22:13:42 by smeethon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*x;
	int		y;

	y = 0;
	if (!s1 || !s2)
		return (NULL);
	x = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!x)
		return (NULL);
	while (*s1)
	{
		x[y++] = *(char *)s1;
		s1++;
	}
	while (*s2)
	{
		x[y++] = *(char *)s2;
		s2++;
	}
	x[y] = '\0';
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
    if ((char)c == '\0')
		return ((char *)s);
    while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// char    *ft_strchr(const char *s, int c)
// {
//     while (*s != (char)c && *s)
//         s++;
//     if (*s == (char)c)
//         return ((char *)s);
//     return (NULL);
// }
// by P earth

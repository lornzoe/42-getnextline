/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:09:28 by lyanga            #+#    #+#             */
/*   Updated: 2025/07/08 13:21:08 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	if (*s == '\0')
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*temp;
	char	*itr;
	size_t	len;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	itr = result;
	temp = (char *)s1;
	while (*temp)
		*itr++ = *temp++;
	temp = (char *)s2;
	while (*temp)
		*itr++ = *temp++;
	*itr = 0;
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*temp;

	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	temp = dest;
	while (*s)
	{
		*temp = *s;
		temp++;
		s++;
	}
	*temp = 0;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*i;

	i = (char *)s;
	while (*i)
	{
		if (*i == (char)c)
			return (i);
		i++;
	}
	if (*i == (char)c)
		return (i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	itr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	itr = 0;
	while (itr < len)
	{
		dest[itr] = s[start + itr];
		itr++;
	}
	dest[itr] = '\0';
	return (dest);
}

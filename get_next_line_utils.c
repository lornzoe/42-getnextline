/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:09:28 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/08 03:09:05 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:01:29 by lyanga            #+#    #+#             */
/*   Updated: 2025/05/07 00:47:29 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;
	size_t			totalsize;
	size_t			limit;

	limit = -1;
	if (!nmemb || !size)
		return (malloc(0));
	if (limit / nmemb < size)
		return (NULL);
	totalsize = nmemb * size;
	temp = malloc(totalsize);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < totalsize)
		temp[i++] = 0;
	return (temp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

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
		return ft_strdup(s2);
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

	dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	temp = dest;
	while (*s)
	{
		*temp = *s;
		temp++;
		s++;
	}
	*temp = *s;
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = (unsigned char *)src;
	if (d <= s)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	itr;

	if (size == 0)
		return (ft_strlen(src));
	itr = 0;
	while (itr < (size - 1) && src[itr] != '\0')
	{
		dst[itr] = src[itr];
		itr++;
	}
	dst[itr] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*src;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		return (ft_calloc(1, sizeof(char)));
	l -= start;
	if (len < l)
		l = len;
	dest = ft_calloc(l + 1, sizeof(char));
	if (!dest)
		return (NULL);
	src = (char *)s;
	src += start;
	ft_strlcpy(dest, src, l + 1);
	return (dest);
}

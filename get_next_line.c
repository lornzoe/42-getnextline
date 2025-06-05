/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:57:02 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/05 10:06:31 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

char	*reallocate_space(char *buffer, size_t currlimit, size_t newlimit)
{
	char	*newbuffer;
	size_t	itr;

	if (!buffer )
		return NULL;
	newbuffer = ft_calloc(newlimit, sizeof(char));
	if (!newbuffer)
		return NULL;
	itr = 0;
	while (itr < currlimit)
		newbuffer[itr] = buffer[itr++];
	free(buffer);
	return newbuffer;
}
char	*add_to_dest(char *src, char *dest, size_t size, size_t start)
{
	static size_t	total;
	size_t			limit;
	size_t			newlimit;

	limit = (total / BUFFER_SIZE + 1) * BUFFER_SIZE;
	if ((start + size) > limit) // make room for null term
	{
		newlimit = limit;
		while (newlimit < start + size)
			newlimit += BUFFER_SIZE;
		dest = reallocate_space(dest, limit, newlimit);
	}
	total += size;
	while (size)
	{
		dest[start + size] = src[size];
		size--;
		start++;
	}
	dest[start] = '\0';
	return (dest);
}


char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE];
	size_t	totalbytesread;
	size_t	bytesread;

	line = ft_calloc(BUFFER_SIZE, sizeof(char));
	totalbytesread = 0;
	bytesread = BUFFER_SIZE;
	while (bytesread == BUFFER_SIZE)
	{
		bytesread = read(fd, line, BUFFER_SIZE);
		if (bytesread == BUFFER_SIZE) // the whole thing was not captured
			line = add_to_dest(buffer, line, bytesread, totalbytesread);
		totalbytesread += bytesread;
		if (bytesread > 0 && buffer[bytesread - 1] == '\n')
		{
			buffer[bytesread - 1] = '\0';
			break;
		}
	}
	if (totalbytesread != 0)
		line = add_to_dest(buffer, line, bytesread, totalbytesread);
	if (totalbytesread == 0)
	{
		printf("something happened \n");
		free(line);
		line = NULL;
	}
	return (line);

}

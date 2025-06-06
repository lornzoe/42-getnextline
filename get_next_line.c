/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:57:02 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/08 01:42:12 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"

char	*clean_buffer(char *buffer)
{
	size_t size = 0;
	while (buffer[size] != '\0')
	{
		buffer[size] = '\0';
		size++;
	}
	return buffer;
}

char	*check_buffer(char *buffer)
{
	char *nextline;
	char *nextstart;

	nextstart = ft_strchr(buffer, '\n');
	if (!nextstart)
		return (NULL);
	nextstart += 1;
	nextline = ft_substr(buffer, 0, nextstart - buffer);
	int n = ft_strlen(buffer) - ft_strlen(nextline);
	ft_memmove(buffer, nextstart, n);
	while (buffer[n] != '\0')
	{
		buffer[n] = '\0';
		n++;
	}
	return nextline;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*bufferline;
	char	*line;
	size_t	totalbytesread;
	ssize_t	bytesread;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > LONG_MAX)
		return (NULL);

	if (ft_strlen(buffer) != 0)
	{
		line = check_buffer(buffer);
		if (line)
			return line;
		line = ft_strdup(buffer);
		clean_buffer(buffer);
	}
	while (read(fd, buffer, BUFFER_SIZE))
	{
		if (!line)
		{
			line = check_buffer(buffer);
			if (line)
				return line;
			line = ft_strdup(buffer);
			clean_buffer(buffer);
			if (ft_strchr(line, '\n'))
				return line;
		}
		else // line already exists 
		{
			bufferline = check_buffer(buffer);
			if (bufferline) // if the buffer has a endl
				return ft_strjoin(line, bufferline);
			line = ft_strjoin (line, buffer);
			clean_buffer(buffer);
		}
	}
	return NULL;
}

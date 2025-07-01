/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:57:02 by lyanga            #+#    #+#             */
/*   Updated: 2025/07/01 10:37:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

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
	char	*temp;
	char	*bufferline;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
		
	line = NULL;
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
			{
				temp = line;
				line = ft_strjoin(line, bufferline);
				free(temp);
				free(bufferline);
				return (line);
			}
			temp = line;
			line = ft_strjoin (temp, buffer);
			free(temp);
			clean_buffer(buffer);
		}
	}
	return line;
}

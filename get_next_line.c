/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:57:02 by lyanga            #+#    #+#             */
/*   Updated: 2025/07/01 17:43:18 by lyanga           ###   ########.fr       */
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
	*nextstart = '\0';
	return nextline;
}

int	get_initial_line(char **line, char *buffer)
{
	*line = check_buffer(buffer);
	if (*line)
		return 1;
	*line = ft_strdup(buffer);
	clean_buffer(buffer);
	return 0;
}

int extend_line(char **line, char *buffer)
{
	char	*temp;
	char	*bufferline;

	bufferline = check_buffer(buffer);
	if (bufferline) // if the buffer has a endl
	{
		temp = *line;
		*line = ft_strjoin(*line, bufferline);
		free(temp);
		free(bufferline);
		return (1);
	}
	temp = *line;
	*line = ft_strjoin(temp, buffer);
	free(temp);
	clean_buffer(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (ft_strlen(buffer) != 0 && get_initial_line(&line, buffer))
		return (line);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (!line)
		{
			if (get_initial_line(&line, buffer) || ft_strchr(line, '\n'))
				return line;
		}
		else if (extend_line(&line, buffer))
			return line;
	}
	return line;
}

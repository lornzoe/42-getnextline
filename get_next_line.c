/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:57:02 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/05 20:54:19 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

char	*check_buffer(char *buffer)
{
	char *nextline;
	char *nextstart;

	nextstart = ft_strchr(buffer, '\n');
	if (!nextstart)
		return (NULL);
	nextstart += 1;
	nextline = ft_substr(buffer, 0, nextstart - buffer);
	// memmove up the rest of the str from nextstart
	// fill the moved space with null terms
	return nextline;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;
	size_t	totalbytesread;
	ssize_t	bytesread;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > LONG_MAX)
		return (NULL);
	line = NULL;
	totalbytesread = 0;
	bytesread = BUFFER_SIZE;
	printf("bytes read: %zu\n", bytesread);
	while (bytesread == BUFFER_SIZE)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesread] = '\0';
		printf("buffer: %s\n", buffer);
		printf("bytes read: %d\n", bytesread);

		if (bytesread == BUFFER_SIZE) // the whole thing was not captured
			line = ft_strjoin(line, buffer);
		totalbytesread += bytesread;
		if (bytesread > 0 && bytesread != BUFFER_SIZE)
			break ;
	}
	if (totalbytesread > 0)
		line = ft_strjoin(line, buffer);
	printf("ttoal bytes read: %d \n", totalbytesread);
	printf("resulting line: \n%s--\n", line);
	return (line);

}

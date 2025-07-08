/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:57:02 by lyanga            #+#    #+#             */
/*   Updated: 2025/07/08 00:24:28 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*check_buffer(char *buffer)
{
	char	*nextline;
	char	*nextstart;
	size_t	n;
	size_t	i;
	char	*temp;

	nextstart = ft_strchr(buffer, '\n');
	if (!nextstart)
		return (NULL);
	nextstart += 1;
	nextline = ft_substr(buffer, 0, nextstart - buffer);
	n = ft_strlen(buffer) - ft_strlen(nextline);
	i = n;
	temp = buffer;
	while (i-- > 0)
		*temp++ = *nextstart++;
	buffer[n] = '\0';
	return (nextline);
}

static int	get_initial_line(char **line, char *buffer)
{
	*line = check_buffer(buffer);
	if (*line)
		return (1);
	*line = ft_strdup(buffer);
	buffer[0] = '\0';
	return (0);
}

static int	extend_line(char **line, char *buffer)
{
	char	*temp;
	char	*bufferline;

	bufferline = check_buffer(buffer);
	if (bufferline)
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
	buffer[0] = '\0';
	return (0);
}

static int	read_constrain_buffer(int fd, char *buffer, int *rval)
{
	int	readval;

	readval = read(fd, buffer, BUFFER_SIZE);
	if (readval >= 0)
		buffer[readval] = '\0';
	*rval = readval;
	return (readval);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_LIMIT];
	char		*line;
	int			readval;

	if (fd < 0 || fd >= FD_LIMIT || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
		
	line = NULL;
	if (ft_strlen(buffer[fd]) != 0 && get_initial_line(&line, buffer[fd]))
		return (line);
	while (read_constrain_buffer(fd, buffer[fd], &readval) > 0)
	{
		if (!line)
		{
			if (get_initial_line(&line, buffer[fd]))
				break ;
		}
		else if (extend_line(&line, buffer[fd]))
			break ;
	}
	if (readval == 0 || readval == -1)
		free(buffer[fd]);
	return (line);
}

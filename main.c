/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:04:26 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/08 01:43:35 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	// int fd = STDIN_FILENO;
	printf("-----getnextline\n>> %s\n", get_next_line(fd));
	printf("-----getnextline\n>> %s\n", get_next_line(fd));
	printf("-----getnextline\n>> %s\n", get_next_line(fd));
	printf("-----getnextline\n>> %s\n", get_next_line(fd));
	printf("-----getnextline\n>> %s\n", get_next_line(fd));
	printf("-----getnextline\n>> %s\n", get_next_line(fd));

	// line = get_next_line(fd);
	// printf("-----getnextline\n%s", line);
	// free(line);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:04:26 by lyanga            #+#    #+#             */
/*   Updated: 2025/06/05 19:33:34 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char* line;
	int fd = open("test.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	line = get_next_line(fd);
	printf("----- becomes\n%s", line);
	free(line);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:02:09 by lyanga            #+#    #+#             */
/*   Updated: 2025/07/07 10:02:35 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// unistd for read()
# include <unistd.h>
// stdlib for malloc() and free();
# include <stdlib.h>
// default BUFFER_SIZE val if it's not defined at compile
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_LIMIT
#  define FD_LIMIT 1024
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

#endif
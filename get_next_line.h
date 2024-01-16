/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmorea <julmorea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:12:11 by julmorea          #+#    #+#             */
/*   Updated: 2024/01/16 12:16:28 by julmorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*erase_old_line(char *line);
char	*write_buffer(char *line);
char	*read_file(int fd, char *line);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstlen);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#endif
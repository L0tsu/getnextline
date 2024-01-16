/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmorea <julmorea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:25:17 by julmorea          #+#    #+#             */
/*   Updated: 2024/01/16 12:22:44 by julmorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*erase_old_line(char *line)
{
	int		b;
	int		i;
	char	*buffer;

	b = 0;
	while (line[b] && line[b] != '\n')
		b++;
	if (!line[b])
	{
		free(line);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * ft_strlen(line) - b + 1);
	if (!buffer)
		return (NULL);
	b++;
	i = 0;
	while (line[b])
		buffer[i++] = line[b++];
	buffer[i] = '\0';
	free(line);
	return (buffer);
}

char	*write_buffer(char *line)
{
	int		byte_count;
	char	*new_line;

	byte_count = 0;
	if (!line[byte_count])
		return (NULL);
	while (line[byte_count] && line[byte_count] != '\n')
		byte_count++;
	new_line = malloc(sizeof(char) * byte_count + 2);
	if (!new_line)
		return (NULL);
	byte_count = 0;
	while (line[byte_count] && line[byte_count] != '\n')
	{
		new_line[byte_count] = line[byte_count];
		byte_count++;
	}
	if (line[byte_count] == '\n')
	{
		new_line[byte_count] = line[byte_count];
		byte_count++;
	}
	new_line[byte_count] = '\0';
	return (new_line);
}

char	*read_file(int fd, char *line)
{
	int		byte_count;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	byte_count = 1;
	while (!ft_strchr(line, '\n') && byte_count != 0)
	{
		byte_count = read(fd, buff, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte_count] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_file(fd, line);
	if (!line)
		return (NULL);
	buff = write_buffer(line);
	line = erase_old_line(line);
	return (buff);
}

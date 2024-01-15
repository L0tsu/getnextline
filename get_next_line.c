/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmorea <julmorea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:25:17 by julmorea          #+#    #+#             */
/*   Updated: 2024/01/15 15:28:21 by julmorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delete_last_line(char *line)
{
	int	i;
	int	d;
	char	*deletedbytes;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	deletedbytes = malloc(sizeof(char) *(ft_strlen(line) - i + 1));
	if (!deletedbytes)
		return (NULL);
	i++;
	d = 0;
	while (line[i])
		deletedbytes[d++] = line[i++];
	deletedbytes[d] = '\0';
	free(line);
	return (deletedbytes);
}

char	*write_file(char *line)
{
	int		counter;
	char	*newline;
	
	counter = 0;
	if (!line[counter])
		return(NULL);
	while (line[counter] && line[counter] != '\n')
		counter++;
	newline = malloc(sizeof(char) + counter);
	if (!newline)
		return(NULL);
	counter = 0;
	while (line[counter] && line[counter] != '\n')
	{
		newline[counter] = line[counter];
		counter++;
	}
	if (line[counter] == '\n')
	{
		newline[counter] = line[counter];
		counter++;
	}
	newline[counter] = '\0';
	return(newline);
}

char	*read_file(int fd, char *line)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return(NULL);
		}
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char *line;
	char *read_write;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_file(fd, line);
	if (!line)
		return (NULL);
	read_write = write_file(line);
	line = delete_last_line(line);
	return (read_write);
}
// int main ()
// {
// 	int fd = open("txt.txt", BUFFER_SIZE, O_RDONLY);
// 	char *buff = get_next_line(fd);
// 	printf("%s", buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// }
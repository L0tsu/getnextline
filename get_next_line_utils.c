/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmorea <julmorea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:34:57 by julmorea          #+#    #+#             */
/*   Updated: 2024/01/15 15:28:30 by julmorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstlen)
{
	size_t	i;

	i = 0;
	if (!dstlen || !dst)
		return (ft_strlen(src));
	while (i < dstlen - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*conc;
	size_t	i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	conc = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!conc)
		return (conc);
	i = ft_strlen(s1);
	ft_strlcpy(conc, s1, i + 1);
	ft_strlcpy(conc + i, s2, (ft_strlen(s2) + 1));
	free(s1);
	return (conc);
}

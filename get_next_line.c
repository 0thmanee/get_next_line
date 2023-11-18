/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:25:45 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/18 17:53:36 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *total_str, char *buffer)
{
	char	*s3;
	int		total_len;
	
	if (!total_str)
	{
		total_str = (char *)malloc(1);
		if (!total_str)
			return (NULL);
		total_str[0] = '\0';
	}
	total_len = ft_strlen(total_str) + ft_strlen(buffer);
	s3 = (char *)malloc(total_len + 1);
	if (!s3)
		return (NULL);
	ft_strcpy(s3, total_str);
	ft_strcpy(s3 + ft_strlen(total_str), buffer);
	free(total_str);
	return (s3);
}

char	*read_file(char *total_str, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = NULL;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(total_str), NULL);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(total_str), NULL);
		buffer[bytes] = '\0';
		total_str = ft_strjoin(total_str, buffer);
		if (!total_str)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
        	break;
	}
	free(buffer);
	return (total_str);
}

char	*extract_line(char *total_str)
{
	char	*line;
	int		len;
	int		i;

	if (!total_str)
		return (NULL);
	len = 0;
	while (total_str[len] && total_str[len] != '\n')
		len++;
	if (total_str[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = total_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_total(char *total_str)
{
	char	*new_t;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (total_str[i] && total_str[i] != '\n')
		i++;
	if (total_str[i] == '\n')
	{
		i++;
		while (total_str[i])
		{
			i++;
			len++;
		}
		new_t = (char *)malloc(len + 1);
		if (!new_t)
			return (NULL);
		ft_strcpy(new_t, total_str + i - len);
		free(total_str);
		return (new_t);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*total_str;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	total_str = read_file(total_str, fd);
	if (!total_str)
		return (NULL);
	line = extract_line(total_str);
	if (!line)
		return (NULL);
	total_str = new_total(total_str);
	if (!total_str)
		return (NULL);
	return (line);
}

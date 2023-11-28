/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:42:30 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/29 00:37:44 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *buffer, int c)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *total_str, char *buffer)
{
	char	*s3;
	size_t	total_len;

	if (!total_str)
	{
		total_str = (char *)malloc(1);
		if (!total_str)
			return (free(buffer), NULL);
		total_str[0] = '\0';
	}
	total_len = ft_strlen(total_str) + ft_strlen(buffer);
	s3 = (char *)malloc(total_len + 1);
	if (!s3)
		return (free_total(&total_str), free(buffer), NULL);
	ft_strcpy(s3, total_str);
	ft_strcpy(s3 + ft_strlen(total_str), buffer);
	free_total(&total_str);
	return (s3);
}

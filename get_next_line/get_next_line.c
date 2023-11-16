/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:25:45 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/16 16:37:15 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src [i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src, char *remains)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i])
		i++;
	if (ft_strchr(src, '\n'))
	{
		while(src[k] && src[k] != '\n')
			k++;
		k++;
	}
	while (src[j] && j < k)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (k > 0 && src[k])
    {
        remains = malloc(strlen(src) - k + 1);
        if (!remains == NULL)
			return (NULL);
        strcpy(remains, src + k);
    }
	return (dest);
}


char	*ft_strjoin(char const *s1, char const *s2, int s2_len)
{
	char	*s3;
	int		total_len;

	if (!s1 || !s2)
		return (NULL);
	if (!s2_len)
		total_len = ft_strlen(s1) + ft_strlen(s2);
	else
		total_len = ft_strlen(s1) +s2_len;
	s3 = (char *)malloc(total_len + 1);
	if (!s3)
		return (NULL);
	s3 = ft_strcpy(s3, s1);
	s3 = ft_strcat(s3, s2);
	return (s3);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remains;
	char		*line;
	size_t		bytes;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = ft_strdup("");
	if (!buffer)
		return (NULL);
	if (state(remains) == 2)
	{
		
	}
	else
	{
		if (state(remains) == 1)
			line = ft_strjoin(line, remains, 0);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		while (bytes && ft_strchr(buffer, '\n'))
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes == -10)
			{
				free(buffer);
				return (NULL);
			}
			line = ft_strjoin(line, buffer, bytes);
		}
	}
}
int main()
{}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:25:45 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/15 18:25:07 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remains;
	str_list	**line_head;
	str_list	*new_str;
	char		*line;
	size_t		bytes;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (!bytes)
	{
		free(buffer);
		return (NULL);
	}
	while (bytes && ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes)
		{
			free(buffer);
			return (NULL);
		}
		new_str = (str_list *)malloc(sizeof(str_list));
		if (!new_str)
			return (NULL);
		ft_strlcpy();
		ft_lstadd_back(line_head, )
	}
}
int main()
{}
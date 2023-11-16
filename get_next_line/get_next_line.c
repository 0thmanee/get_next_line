/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:25:45 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/16 15:14:34 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remains;
	str_list	**line_head;
	str_list	*new_str;
	size_t		bytes;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (state(remains) == 2)
	{
		
	}
	else
	{
		if (state(remains) == 1)
		{
			new_str = (str_list *)malloc(sizeof(str_list));
			if (!new_str)
				return (NULL);
			new_str->buff_str = ft_strdup(remains, 0, 0);
			ft_lstadd_back(line_head, new_str);
		}
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
			new_str = (str_list *)malloc(sizeof(str_list));
			if (!new_str)
				return (NULL);
			new_str->buff_str = ft_strdup(buffer, 1, bytes);
			ft_lstadd_back(line_head, new_str);
		}
		ft_strjoin(line_head, remains);
	}
}
int main()
{}
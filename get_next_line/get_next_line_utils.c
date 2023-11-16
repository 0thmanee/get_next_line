/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:18:09 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/16 14:40:19 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_lstadd_back(str_list **lst, str_list *new)
{
	str_list	*curr;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

char	*ft_strdup(const char *str,int mode, int len)
{
	char	*dest;
	size_t	srclen;
	size_t	i;
	
	if (!mode)
	{
		while (str[len])
			len++;
	}
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	state(char *str)
{
	int	state;
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (ft_strchr(str, '\n'))
		return (2);
	return (1);
}

int	joined_len(str_list **line_head, int *rem_len)
{
	str_list	*curr;
	int			i;
	int			len;

	curr = *line_head;
	while (curr->next)
	{
		i = 0;
		while (curr->buff_str[i])
			i++;
		len += i;
		curr = curr->next;
	}
	i = 0;
	while (curr->buff_str[i] != '\n')
		i++;
	len += ++i;
	while (curr->buff_str[i++])
		(*rem_len)++;
	return (len);
}
char	*ft_strjoin(str_list **line_head, char *remains)
{
	str_list	*curr;
	char		*str;
	int			i;
	int			len;
	int			rem_len;

	if (!line_head)
		return (NULL);
	len = joined_len(line_head, &rem_len);
	str = (char *)malloc((len + 1));
}
/*  */
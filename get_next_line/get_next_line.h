/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:25:24 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/16 15:14:38 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct str_list
{
	char			*buff_str;
	struct str_list	*next;
}	str_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strchr(char *str, char c);
void	ft_lstadd_back(str_list **lst, str_list *new);
char	*ft_strdup(const char *str,int mode, int len);

#endif
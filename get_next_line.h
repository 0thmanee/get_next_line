/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:25:24 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/18 17:39:56 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*new_total(char *total_str);
char	*extract_line(char *total_str);
char	*read_file(char *total_str, int fd);
char	*ft_strjoin(char *total_str, char *buffer);
char	*ft_strcpy(char *dest, char *src);
int		ft_strchr(char *buffer, int c);
size_t	ft_strlen(const char *s);

#endif
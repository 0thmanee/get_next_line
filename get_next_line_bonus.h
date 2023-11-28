/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:27:30 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/28 20:53:13 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_data
{
	char	*total_str;
	int		end_file;
}	t_data;

char	*get_next_line(int fd);
char	*new_total(t_data *total_data);
char	*extract_line(char *total_str);
char	*read_file(char *total_str, int fd);
char	*ft_strjoin(char *total_str, char *buffer);
void	ft_strcpy(char *dest, char *src);
int		ft_strchr(char *buffer, int c);
size_t	ft_strlen(const char *s);
void	free_total(char **total_str);

#endif
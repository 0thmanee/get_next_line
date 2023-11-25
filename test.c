#include "get_next_line.h"

int	ft_strchr(char *buffer, int c)
{
	int	i;

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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	srclen;
	size_t	i;

	if (!str)
		return (NULL);
	srclen = ft_strlen(str);
	dest = (char *)malloc(srclen + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *total_str, char *buffer)
{
	char	*s3;
	int		total_len;

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
		return (free_total(total_str), free(buffer), NULL);
	ft_strcpy(s3, total_str);
	ft_strcpy(s3 + ft_strlen(total_str), buffer);
	free_total(total_str);
	return (s3);
}

char	*read_file(char *total_str, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_total(total_str), NULL);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free_total(total_str), free(buffer), NULL);
		buffer[bytes] = '\0';
		if (bytes)
		{
			total_str = ft_strjoin(total_str, buffer);
			if (!total_str)
				return (free(buffer), NULL);
			if (ft_strchr(buffer, '\n'))
				break ;
		}
	}
	free(buffer);
	return (total_str);
}

char	*extract_line(char *total_str)
{
	char	*line;
	int		len;
	int		i;

	if (!total_str || !total_str[0])
		return (NULL);
	len = 0;
	while (total_str[len] && total_str[len] != '\n')
		len++;
	if (total_str[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (free_total(total_str), NULL);
	i = 0;
	while (total_str[i] && i < len)
	{
		line[i] = total_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_total(t_data *total_data)
{
	char	*new_t;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (total_data->total_str[i] && total_data->total_str[i] != '\n')
		i++;
	while (total_data->total_str[i++])
		len++;
	if (len)
	{
		new_t = (char *)malloc(len + 1);
		if (!new_t)
			return (free_total(total_data->total_str), NULL);
		ft_strcpy(new_t, total_data->total_str + i - len);
		free_total(total_data->total_str);
		return (new_t);
	}
	else
	{
		total_data->end_file = 1;
		return (total_data->total_str);
	}
}

void	free_total(char *total_str)
{
	if (total_str)
	{
		free(total_str);
		total_str = NULL;
	}
	
}

char	*get_next_line(int fd)
{
	static t_data	total_data;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (total_data.end_file != 1)
	{
		total_data.total_str = read_file(total_data.total_str, fd);
		if (!total_data.total_str)
			return (NULL);
		line = extract_line(total_data.total_str);
		if (!line)
			return (free_total(total_data.total_str), NULL);
		total_data.total_str = new_total(&total_data);
		if (!total_data.total_str)
			return (free(line), NULL);
		return (line);
	}
	else
		return (free_total(total_data.total_str), NULL);
}

int	main(void)
{
	char	*line;
	int		fd;
	int	i;
	// atexit(f);

	fd = open("1.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (i++ < 10)
	{
		printf("%d ==> (%s)\n", i,line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int	i;
	// atexit(f);

	fd = open("1.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		printf("%d ==> (%s)\n", i,line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

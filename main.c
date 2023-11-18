#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int i = 1;
	
	// atexit(f);

	fd = open("1.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%d==>%s", i,line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

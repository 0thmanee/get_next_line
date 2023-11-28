#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int	i;
	// atexit(f);

	fd = open("1.txt", O_RDONLY);
	line = get_next_line(24523);
	printf("%s", line);
	i = 0;
	while (line)
	{
		printf("==> (%s)", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

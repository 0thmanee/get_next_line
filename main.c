#include "get_next_line.h"

void func(int i)
{
	i++;
}

int	main(void)
{
	char	*line;
	int		fd;
	int i = 1;
	
	// atexit(f);

	fd = open("1.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	func(i);

	while (i++ < 10)
	{
		printf("%d ==> (%s)\n", i,line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

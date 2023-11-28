#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int i = 0;

	close(1);
	close(2);
	close(3);
    int fd1 = open("1.txt", O_CREAT | O_RDWR, 0666);
    char *str = "Hi this is a new\ninput\ninside of you bitch\n";
    write(fd1, str, ft_strlen(str));
	close(fd1);
	fd1 = open("1.txt", O_RDWR, 0666);
    int fd2 = open("2.txt", O_RDONLY);
    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);

    while (i < 5)
    {
        printf("(1) - (%s)\n", line1);
        printf("(2) - (%s)\n", line2);
        free(line1);
        free(line2);
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        i++;
    }

    // Close the opened files
    close(fd1);
    close(fd2);

    return 0;
}


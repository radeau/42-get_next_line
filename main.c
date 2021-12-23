#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
        int fd;
        char *line;

        line = malloc(1 *sizeof(char));

        if (argc == 2)
        {
                fd = open(argv[1], O_RDONLY);
                while (line != NULL)
                {
                        free(line);
                        line = get_next_line(fd);
                        if (line == NULL)
                                exit(1);
			printf("%s", line);
                }
		if (fd == 0)
		{
			while ((line = get_next_line(0)) != NULL)
      				printf("Next line -> %s", line);
		}
                close(fd);
        }

	if (argc < 2)
	{
		while ((line = get_next_line(0)) != NULL)
		{
      			printf("Next line -> %s", line);
		}
	}
        return 0;
}

/*
char *line;
while ((line = get_next_line(0)) != NULL)
      printf("Next line -> %s", line);
*/

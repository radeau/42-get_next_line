#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

/*
int	main(int ac, char **av)
{
  --ac && (ac = open(av[1], O_RDONLY));
  while (*av = get_next_line(ac))
    {
      puts(*av);
      free(*av);
    }
  return (0);
}
*/

int main()
{
	int fd01, fd02, fd03;
	fd01 = open("files/file1", O_RDONLY);
	fd02 = open("files/file2", O_RDONLY);
	fd03 = open("files/file3", O_RDONLY);

	//FD 01 first line
	printf("FD01 | First Line = %s", get_next_line(fd01));
	//FD02 second line
/*	printf("FD02 | First Line = %s", get_next_line(fd02));
	//FD03 third line
	printf("FD03 | First Line = %s", get_next_line(fd03));
	//FD01 second Line
	printf("FD01 | Second Line = %s", get_next_line(fd01));
        //FD02 second line
	printf("FD02 | Second Line = %s", get_next_line(fd02));
	//FD03 second Line
        printf("FD03 | Second Line = %s", get_next_line(fd03));
        //FD 01 third line
	printf("FD01 | Third Line = %s", get_next_line(fd01));
	//FD02 third line
	printf("FD02 | Third Line = %s", get_next_line(fd02));
	//FD03 third line
	printf("FD03 | Third Line = %s", get_next_line(fd03));
        
   */     return (0);
}

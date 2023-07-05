#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int     main(void)
{
        int fd = open ("Hola.txt", O_RDONLY);
        if (fd == -1)
                return (1);
//	while (1)
//	{
		printf("%s \n", get_next_line(fd));
//	}
	close(fd);
        return (0);
}

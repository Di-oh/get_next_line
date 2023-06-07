#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int     main(void)
{
        int fd = open ("Hola.txt", O_RDONLY);
	char buf[10];
	ssize_t nr_bytes;

        if (fd == -1)
                return (1);

	buf = get_next_line(fd);
	close(fd);
        return (0);
}

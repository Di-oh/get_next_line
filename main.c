#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int     main(void)
{
        int fd = open ("Hola.txt", O_RDONLY);

        if (fd == -1)
                return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line = 1)
			return (NULL);
		printf("%s", line);
		free(line);
	}
	close(fd);
        return (0);
}

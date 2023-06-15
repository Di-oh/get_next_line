#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int     main(void)
{
        int fd = open ("Hola.txt", O_RDONLY);
	char *line;
	int datos;

	datos = 0;
        if (fd == -1)
                return (1);
	while (datos == 0)
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

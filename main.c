#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *str1;
        size_t  len_s1;
        size_t  len_s2;

        len_s1 = strlen(s1);
        len_s2 = strlen(s2);
        str1 = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
        if (str1 == NULL)
                return (NULL);
        strlcpy(str1, s1, (len_s1 + 1));
        strlcat(str1, s2, (len_s1 + len_s2 + 1));
        return (str1);
}

char *leer_y_guardar(int fd)
{
        char    buf[BUFFERSIZE];
        int     nr_chars;
        char    *str;
        int i;

        buf = NULL;
        nr_chars = read(fd, buf, 10);
        str = ft_strjoin(str, buf);
        printf("%s \n", str);
	return (str);
}

char *get_next_line(int fd)
{
        char *str;

        str = leer_y_guardar(fd);
//      buscar_y_restar(str);
        return (str);
}

int     main(void)
{
        int fd = open ("Hola.txt", O_RDONLY);
	char *line = NULL;
        if (fd == -1)
                return (1);
	while (1)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
        return (0);
}

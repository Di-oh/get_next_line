int     leer_y_guardar(fd);
{
        char    buf[5];
        int     nr_chars;
        char    *str;
        int i;

        nr_chars = read(fd, buf, BUFFERSIZE);
        str = ft_strjoin(str, buf);

        if (nr_chars != BUFFERSIZE)
                return (1);
        else
                return (0);
}
void buscar_y_restar();
{

        while (str[i] != '\n' && str[i] != '\0')

                i++;
        str = ft_substr(str, 0, i);
}

char *get_next_line(int fd)
{

 	leer_y_guardar(fd);
	buscar_y_restar();
	return (NULL);
}

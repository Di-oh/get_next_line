char	*leer_y_guardar(fd);
{
        char    buf[BUFFERSIZE];
        int     nr_chars;
        char    *str;
        int i;
	
	buf = NULL;
        nr_chars = read(fd, buf, 10);
        str = ft_strjoin(str, buf);
	printf("%s \n", str);
        if (nr_chars != 10)
                return (1);
        else
                return (0);
}
/*
void buscar_y_restar(char *str);
{

        while (str[i] != '\n' && str[i] != '\0')
                i++;
        str = ft_substr(str, 0, i);
}
*/
char *get_next_line(int fd)
{
	char *str;

 	str = leer_y_guardar(fd);
//	buscar_y_restar(str);
	free(str);
	return (str);
}

char	*leer_y_guardar(fd);
{
        char    buf[BUFFERSIZE];
        int     *stra;
        char    *str;
        int i;
	
		buf = NULL;
        nr_chars = read(fd, buf, 10);
        str = ft_strjoin(str, buf);
		stra = ft_strchr(str, "\n");
		printf("%s \n", str);
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
	static char *str;

 	str = leer_y_guardar(fd);
//	buscar_y_restar(str);
	free(str);
	return (str);
}

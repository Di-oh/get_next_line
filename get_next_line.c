char *get_next_line(int fd)
{
	static char *str;
	int	nr_caracter;
 	
	while(1)
	{
		leer_y_guardar(fd);
	} 
	return (NULL);
}

void	leer_y_guardar(fd);
{
	char	*buf;
	int	nr_caracter;
	t_list	*list;
	t_list	*cont_fd;
	t_list	*new_nodo;
	t_list	*new_content;
	static char *str;
	int i;

	letras = read(fd, buf, BUFFERSIZE);

	str = ft_strjoin(str, buf); 
	while (str[i] != '$' && str[i] != '\0')
		i++;
	new_content = ft_substr(str, 0, i);
	new_nodo = ft_lstnew(new_content);
	if (!new_nodo)
	{
		ft_lstclear(&cont_fd, del)
		free(new_content);
		return (NULL);
	}	
	ft_lstadd_back(&cont_fd, new_nodo);
                list = list->next;

	ft_strlcpy(str, ft_strrchr(str, '$'), ft_strlen(str));
}
char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *str1;
        size_t  len_s1;
        size_t  len_s2;

        len_s1 = ft_strlen(s1);
        len_s2 = ft_strlen(s2);
        str1 = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
        if (str1 == NULL)
                return (NULL);
        ft_strlcpy(str1, s1, (len_s1 + 1));
        ft_strlcat(str1, s2, (len_s1 + len_s2 + 1));
        return (str1);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char                    *str;
        unsigned int    len_s;
        size_t                  i;

        i = 0;
        if (!s || len == 0)
                return (ft_strdup(""));
        len_s = ft_strlen(s);
        if (start + len == len_s + 1)
                return (ft_strdup(s + start));
        if (len > len_s + 1)
                len = len_s - start;
        if (len_s <= start)
                return (ft_strdup(""));
        str = (char *)malloc(sizeof(char) * (len + 1));
        if (str == NULL)
                return (NULL);
        s += start;
        while (i <= (len - 1))
        {
                str[i] = s[i];
                i++;
        }
        str[i] = '\0';
        return (str);
}


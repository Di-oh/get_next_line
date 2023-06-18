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
 
t_list  *ft_lstnew(void *content)
{
        struct s_list   *list;

        list = malloc(sizeof(struct s_list));
        if (list == NULL)
                return (list);
        list -> content = content;
        list -> next = NULL;
        return (list);
}


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t  ft_strlen(const char    *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
        char    *str1;
        size_t  i;
        size_t  j;
	
//	printf("%s\n", s1);
//	printf("%s\n", s2);
	if (s1 == "")
	{
		s1 = malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return(NULL);
		s1[0] = '\0';
	}
        str1 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (str1 == NULL)
                return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			str1[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		str1[i++] = s2[j++];
	//printf("%s\n", str1);
	str1[ft_strlen(s1) + ft_strlen(s2)] = '\0';
//	if (s1 != NULL)
//		free(s1);
        return (str1);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			s += i;
			return ((char *)s);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		s += i;
		return ((char *)s);
	}
	return (NULL);
}

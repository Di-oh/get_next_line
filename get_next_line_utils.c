#include <stddef.h>
#include <stdlib.h>
size_t  ft_strlen(const char    *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        unsigned int    i;

        i = 0;
        if (dstsize == 0)
                return (ft_strlen(src));
        while ((i < (dstsize - 1)) && (src[i] != '\0'))
        {
                dst[i] = src[i];
                i++;
        }
                dst[i] = '\0';
        return (ft_strlen(src));
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
        unsigned int    i;
        unsigned int    len_dst;
        unsigned int    len_src;
        size_t                  ret;

        i = 0;
        len_dst = ft_strlen(dst);
        len_src = ft_strlen(src);
        if (len_dst < dstsize)
                ret = (len_src + len_dst);
        else
                ret = (len_src + dstsize);
        while ((src[i]) && (len_dst + 1 < dstsize))
        {
                dst[len_dst] = src[i];
                i++;
                len_dst++;
        }
        dst[len_dst] = '\0';
        return (ret);
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

char    *ft_strdup(const char *s)
{
        char    *str;
        int             i;
        int             len;

        i = 0;
        len = ft_strlen(s);
        str = malloc(sizeof(char) * (len + 1));
        if (str == NULL)
                return (NULL);
        while (i < len)
        {
                str[i] = s[i];
                i++;
        }
        str[i] = '\0';
        return (str);
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

void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *b;
	size_t	i;
	unsigned char *pt;
	
	i = 0;
        b = malloc(size * nmemb);
        if (b == NULL)
                return (b);
	pt = (unsigned char *)b;
	while (i < size)
		pt[i++] = 0;
        return (b);
}

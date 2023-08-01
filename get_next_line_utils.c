/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:01:27 by dionmart          #+#    #+#             */
/*   Updated: 2023/08/01 11:12:25 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen_gnl(char *str, int op)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (op == 1)
		while (str[i])
			i++;
	else 
		while (str[i] && str[i] != '\n')
			i++;
	return (i);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str1;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	str1 = malloc(sizeof(char) * 
			(ft_strlen_gnl(s1, 1) + ft_strlen_gnl(s2, 1) + 1));
	if (str1 == NULL)
		return (ft_free(&s1));
	i = -1;
	if (s1)
		while (s1[++i])
			str1[i] = s1[i];
	j = 0;
	while (s2[j])
		str1[i++] = s2[j++];
	str1[i] = '\0';
	free(s1);
	return (str1);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
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

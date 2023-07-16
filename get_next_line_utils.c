/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:01:27 by dionmart          #+#    #+#             */
/*   Updated: 2023/07/16 20:02:14 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str1;
	size_t	i;
	size_t	j;

	s1 = ft_check_str(s1);
	if(!s1)
		return NULL;
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
	str1[i] = '\0';
	return (str1);
}

char	*ft_check_str(char *s1)
{
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	return (s1);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

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

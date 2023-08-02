/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:58:41 by dionmart          #+#    #+#             */
/*   Updated: 2023/08/02 13:01:47 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(char *str, int op)
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

char	*gnl_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
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
	str1 = malloc(sizeof(char) 
			* (gnl_strlen(s1, 1) + gnl_strlen(s2, 1) + 1));
	if (str1 == NULL)
		return (gnl_free(&s1));
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

char	*gnl_strchr(const char *s, int c)
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

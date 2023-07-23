/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:16:00 by dionmart          #+#    #+#             */
/*   Updated: 2023/07/23 20:58:05 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *str)
{
	int		nr_char;
	char	*buff;

	nr_char = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (ft_free(&str));
	buff[0] = '\0';
	while (!ft_strchr(buff, '\n') && nr_char > 0)
	{
		nr_char = read(fd, buff, BUFFER_SIZE);
		if (nr_char == -1)
		{
			free(buff);
			return (ft_free(&str));
		}
		buff[nr_char] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	buff = NULL;
	return (str);
}

char	*write_line(char *str)
{
	char	*str2;
	int		n;
	int		i;

	if (str[0] == '\0')
		return (NULL);
	n = 0;
	i = ft_strlen(str);
	if (str[i] == '\0')
		str2 = malloc(sizeof(char) * (i + 1));
	else 
		str2 = malloc(sizeof(char) * (i + 2));
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		str2[i++] = '\n';
	str2[i] = '\0';
	return (str2);
}

char	*clean_storage(char *str)
{
	char	*new_storage;
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (ft_free(&str));
	new_storage = malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	if (new_storage == NULL)
		return (ft_free(&str));
	i++;
	while (str[i] != '\0')
		new_storage[n++] = str[i++];
	new_storage[n] = '\0';
	free(str);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*str2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str || (str && ft_strchr(str, '\n')))
		str = read_and_save(fd, str);
	if (!str)
		return (NULL);
	str2 = write_line(str);
	if (!str2)
		return (ft_free(&str));
	str = clean_storage(str);
	return (str2);
}
/*
int	main(void)
{
        int fd = open ("lines_around_10.txt", O_RDONLY);
        if (fd == -1)
                return (1);
//      while (1)
//      {
        	printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
                printf("%s", get_next_line(fd));
                printf("%s", get_next_line(fd));
//      }
        close(fd);
	return (0);
}*/

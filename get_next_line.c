/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:16:00 by dionmart          #+#    #+#             */
/*   Updated: 2023/07/16 20:44:45 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *str)
{
	int		nr_char;
	char	*buff;

	nr_char = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
	{
		free(str);
		return (NULL);
	}
	buff[0] = '\0';
	while (!ft_strchr(buff, '\n') && nr_char > 0)
	{
		nr_char = read(fd, buff, BUFFER_SIZE);
		if (nr_char < -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		if (nr_char > 0)
		{
			buff[nr_char] = '\0';
			str = ft_strjoin(str, buff);
		}
	}
	free(buff);
	return (str);
}

char	*write_line(char *str)
{
	char	*str2;
	int		n;
	int		i;

	n = 0;
	i = ft_strlen(str);
	str2 = malloc(sizeof(char) * i);
	if (str2 == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	if(str[i] == '\n')
	{
//i		str2[i] = '\n';
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char 	*clean_storage(char *str)
{
	char	*new_storage;
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if(str[i] == '\0')
	{
		free(str);
		return NULL;
	}
	new_storage = malloc(sizeof(char) * (ft_strlen(str) - i)  + 1);
	if (new_storage == NULL)
	{
		free(str);
		return(NULL);
	}
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

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	str = read_and_save(fd, str);
	if(!str)
		return (NULL);
	str2 = write_line(str);
	if(!str2)
	{
		free(str);
		return (NULL);
	}
	str = clean_storage(str);
	return (str2);
}

int	main(void)
{
        int fd = open ("Hola.txt", O_RDONLY);
        if (fd == -1)
                return (1);
//      while (1)
//      {
        	printf("%s \n", get_next_line(fd));
		printf("%s \n", get_next_line(fd));
                printf("%s \n", get_next_line(fd));
                printf("%s \n", get_next_line(fd));
//      }
        close(fd);
	return (0);
}

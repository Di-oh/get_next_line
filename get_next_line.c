/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:16:00 by dionmart          #+#    #+#             */
/*   Updated: 2023/08/01 13:14:08 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *storage)
{
	int		nr_char;
	char	*buff;

	nr_char = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (ft_free(&storage));
	buff[0] = '\0';
	while (!(ft_strchr(buff, '\n')) && nr_char > 0)
	{
		nr_char = read(fd, buff, BUFFER_SIZE);
		if (nr_char == -1)
		{
			free(buff);
			return (ft_free(&storage));
		}
		buff[nr_char] = '\0';
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	buff = NULL;
	return (storage);
}

char	*write_line(char *storage)
{
	char	*line;
	int		i;

	if (storage[0] == '\0')
		return (NULL);
	i = ft_strlen_gnl(storage, 0);
	if (storage[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else 
		line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (!storage)
		return (NULL);
	i = ft_strlen_gnl(storage, 0);
	if (storage[i] == '\0')
		return (ft_free(&storage));
	new_storage = malloc(sizeof(char) * ((ft_strlen_gnl(storage, 1) - i) + 1));
	if (new_storage == NULL)
		return (ft_free(&storage));
	i++;
	while (storage[i] != '\0')
		new_storage[n++] = storage[i++];
	new_storage[n] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*temp_ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n')))
		storage = read_and_save(fd, storage);
	if (!storage)
		return (NULL);
	temp_ln = write_line(storage);
	if (!temp_ln)
		return (ft_free(&storage));
	storage = clean_storage(storage);
	return (temp_ln);
}

int	main(void)
{
       // int fd = open ("variable_nls.txt", O_RDONLY);
       //int fd = open ("Hola.txt", O_RDONLY);
//        int fd = open ("lines_around_10.txt", O_RDONLY);
        int fd = open ("", O_RDONLY);
        if (fd == -1)
                return (1);
	    while (1)
	   	{
        	printf("%s", get_next_line(fd));
		}
        close(fd);
	return (0);
}

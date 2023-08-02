/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:32 by dionmart          #+#    #+#             */
/*   Updated: 2023/08/02 13:00:05 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_save(int fd, char *storage)
{
	int		nr_char;
	char	*buff;

	nr_char = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (gnl_free(&storage));
	buff[0] = '\0';
	while (!(gnl_strchr(buff, '\n')) && nr_char > 0)
	{
		nr_char = read(fd, buff, BUFFER_SIZE);
		if (nr_char == -1)
		{
			free(buff);
			return (gnl_free(&storage));
		}
		buff[nr_char] = '\0';
		storage = gnl_strjoin(storage, buff);
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
	i = gnl_strlen(storage, 0);
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
	i = gnl_strlen(storage, 0);
	if (storage[i] == '\0')
		return (gnl_free(&storage));
	new_storage = malloc(sizeof(char) * ((gnl_strlen(storage, 1) - i) + 1));
	if (new_storage == NULL)
		return (gnl_free(&storage));
	i++;
	while (storage[i] != '\0')
		new_storage[n++] = storage[i++];
	new_storage[n] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*temp_ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd] || (storage[fd] && !gnl_strchr(storage[fd], '\n')))
		storage[fd] = read_and_save(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	temp_ln = write_line(storage[fd]);
	if (!temp_ln)
		return (gnl_free(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (temp_ln);
}
/*
int	main(void)
{
	int n;
	n = 0;
//	int fd1 = open ("variable_nls.txt", O_RDONLY);
    int fd2 = open ("Hola.txt", O_RDONLY);
    int fd1 = open ("lines_around_10.txt", O_RDONLY);
//        int fd = open ("", O_RDONLY);
        if (fd1 == -1 || fd2 == -1)
                return (1);
	    while (n < 10)
	   	{
        	printf("%s", get_next_line(fd1));
        	printf("%s", get_next_line(fd2));
			n++;
		}
        close(fd1);
        close(fd2);
	return (0);
}*/

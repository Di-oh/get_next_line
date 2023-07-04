/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:16:00 by dionmart          #+#    #+#             */
/*   Updated: 2023/06/20 12:51:47 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

char	*leer_y_guardar(int fd, char *str)	
{
	int nr_char;
	char *buff;

	nr_char = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	while (!ft_strchr(str, '\n') && nr_char != 0)
	{
		nr_char = read(fd, buff, BUFFER_SIZE);
		if (nr_char != -1)
		{
			free(buff);
			free(str);
			return(NULL);
		}
		buff[nr_char] = '\0';
		str = ft_strjoin(str, buff);
		printf("%s", str);
	}
	free(buff);
	buff = NULL;
	return (str);
	printf("%d\n", ft_strchr(str,'\n'));

	return (str);
}

char *get_next_line(int fd)
{
        char *str;
        str = leer_y_guardar(fd, str);
        return (str);
}

int	main(void)
{
	int fd = open ("Hola.txt", O_RDONLY);
	if (fd == -1)
                return (1);

	printf("%s \n", get_next_line(fd));
	close(fd);
	return (0);
}

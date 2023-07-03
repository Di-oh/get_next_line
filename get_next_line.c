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
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	while (ft_strchr(str, '\n') == NULL && nr_char != 0)
	{
		nr_char = read(fd, buff, BUFFER_SIZE);
		if (nr_char != -1)
		{
			free(str);
			return(NULL);
		}
		str = ft_strjoin(str, str2);
		if (str == NULL)
	        {
        	    free(str);
		    return(NULL);
		}
		printf("%s", str);
	}
	printf("%d\n", ft_strchr(str,'\n'));

	return (str);
}

char *get_next_line(int fd)
{
        static char *str;
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

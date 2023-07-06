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
#include "get_next_line.h"
#include<stdio.h>

char	*read_and_save(int fd, char *str)	
{
	int nr_char;
	char *buff;
	int i;

	i = 0;
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
		if (nr_char < -1)
		{
			free(buff);
			free(str);
			return(NULL);
		}
		buff[nr_char] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	buff = NULL;
	return (str);
}
char *separar(char *str)
{
	char *str2;
	int	n;
	char	c;
	
	n = 0;
	str2 =malloc(sizeof(char) * nr_char);
	if (str2 == NULL)
	{
		free(str);
		free(str2);
		return(NULL);
	}
	while (str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i++] = '\0';
	while (str[i] != '\0')
	{
		str[n] = str[i];  
		n++;
		i++;
	}
	return (str2);
}

char *get_next_line(int fd)
{
        static char *str = "";
	char str2;

        str = read_and_save(fd, str);
	str2 = separar(str);
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
//      }
        close(fd);
	return (0);
}

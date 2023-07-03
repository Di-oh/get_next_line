<<<<<<< HEAD
char	*leer_y_guardar(fd);
{
        char    *buf;
        int     nr_chars;
        int i;
	
	buf = NULL;
        nr_chars = read(fd, buf, BUFFERSIZE);
        str = ft_strjoin(str, buf);
	printf("%s \n", str);
        if (nr_chars != 10)
                return (1);
        else
                return (0);
}
/*
void buscar_y_restar(char *str);
{
=======
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
>>>>>>> ae3330212a792dce3abc303e609902c7cbce655d

char *get_next_line(int fd)
{
	static char *str;
<<<<<<< HEAD

 	str = leer_y_guardar(fd);
	if (strchar()	
//	buscar_y_restar(str);
	free(str);
	return (str);
=======
	int nr_char;
	char *print_str
	int flag;

	str = ft_calloc(BUFFERSIZE + 1, sizeof(char ));
	if (str != -1)
	{
		free(str);
		return (NULL);
	}
	while (flag == 0)
	{
		nr_char = read(fd, str, BUFFERSIZE);
		if (nr_char != -1)
		{
			free(str);
			return(NULL);
		}
		print_str = ft_strjoin(str, print_str);
		printf("%s", print_str);
		if (print_str != -1)
        {
            free(print_str);
            return(NULL);
        }
		if (ft_strchr(print_str, '\n')  !=  NULL)
			flag = 1;
		
	}

	return (print_str);
}

int	main(void)
{


	return (0);
>>>>>>> ae3330212a792dce3abc303e609902c7cbce655d
}

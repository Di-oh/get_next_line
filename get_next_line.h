/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:03:41 by dionmart          #+#    #+#             */
/*   Updated: 2023/06/19 19:04:44 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdarg.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<string.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif 
size_t	ft_strlen(char *s);
char	*ft_strchr(const char *s1, int c);
char	*ft_strjoin(char *s1, char *s2);
char    *leer_y_guardar(int fd, char *str);
char 	*get_next_line(int fd);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:03:41 by dionmart          #+#    #+#             */
/*   Updated: 2023/07/23 19:51:45 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif 

size_t	ft_strlen_gnl(char *s, int op);
char	*ft_free(char **s1);
char	*ft_strchr(const char *s1, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*read_and_save(int fd, char *str);
char	*write_line(char *str);
char	*ft_check_str(char *s1);
char	*get_next_line(int fd);
#endif

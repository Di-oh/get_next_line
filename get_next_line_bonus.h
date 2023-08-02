/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:57:27 by dionmart          #+#    #+#             */
/*   Updated: 2023/08/02 12:58:15 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	gnl_strlen(char *s, int op);
char	*gnl_free(char **s1);
char	*gnl_strchr(const char *s1, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*read_and_save(int fd, char *str);
char	*write_line(char *str);
char	*get_next_line(int fd);
#endif

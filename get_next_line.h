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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif 
char *get_next_line(int fd);
#endif

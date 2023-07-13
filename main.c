/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:13:31 by dionmart          #+#    #+#             */
/*   Updated: 2023/07/13 19:13:29 by dionmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
        int fd = open ("Hola.txt", O_RDONLY);
        if (fd == -1)
                return (1);
        printf("%s \n", get_next_line(fd));
		printf("%s \n", get_next_line(fd));
        printf("%s \n", get_next_line(fd));
        printf("%s \n", get_next_line(fd));
        close(fd);
	return (0);
}

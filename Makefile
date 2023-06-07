 **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dionmart <dionmart@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 11:18:56 by dionmart          #+#    #+#              #
#    Updated: 2023/06/06 18:06:47 by dionmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    = libftpri.a
HEADER  = get_next_line.h

SRC     = get_next_line.c get_next_line_utils.c

OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Metodo Implicito:
#regla patron $< substituir los nombre del output, $@ los del input
%.o: %.c $(HEADER)
        @$(CC) $(CFLAGS) -c $< -o $@


# Mis metodos:
all:$(NAME)

$(NAME): $(OBJS)
        @ar rcs $(NAME) $(OBJS) 

clean:
        @rm -rf $(OBJS) 

fclean: clean
        @rm -f $(NAME)

re: fclean all


# Regla phony
.PHONY: re fclean clean all














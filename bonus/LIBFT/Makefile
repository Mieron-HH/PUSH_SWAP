# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 20:36:14 by mhaileye          #+#    #+#              #
#    Updated: 2023/04/10 20:54:50 by mhaileye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
mandatory = ft_atoi.c \
			ft_calloc.c\
			ft_memcpy.c \
			ft_memset.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c

M_OBJS = ${mandatory:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar -rcs
INCS = .

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I{INCS}

all: ${NAME}

${NAME}: ${M_OBJS}
	$(LIBC) $(NAME) ${M_OBJS}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o

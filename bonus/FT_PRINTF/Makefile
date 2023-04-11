# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 16:11:45 by mhaileye          #+#    #+#              #
#    Updated: 2023/01/23 16:11:45 by mhaileye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
mandatory =	ft_printf.c \
			ft_validate_type.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_puterr.c

bonus = \

M_OBJS = ${mandatory:.c=.o}
B_OBJS = ${bonus:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar -rcs
INCS = .
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I{INCS}

all: ${NAME}

${NAME}: ${M_OBJS}
	$(LIBC) $(NAME) ${M_OBJS}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o

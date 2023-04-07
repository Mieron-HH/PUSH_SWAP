NAME = push_swap.a

CFILES = 	main.c \
		push_swap_utils.c \
		sort_algorithm.c \
		sort_functions.c \
		stack_a_instructs.c \
		stack_b_instructs.c \
		stack_ab_instructs.c \
		utilities_1.c \
		utilities_2.c \
		utilities_3.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = ${CFILES:.c=.o}
LIBC = ar -rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	cd LIBFT && make
	cd FT_PRINTF && make
	# ar -x LIBFT/libft.a
	# ar -x FT_PRINTF/libftprintf.a
	find . -name "*.o" | xargs $(LIBC) $(NAME)
	cd LIBFT && make fclean
	cd FT_PRINTF && make fclean
	rm -f __.*

clean:
	rm -f *.o

fclean: clean libftFclean ft_printfFclean
	rm -f $(NAME)

libftFclean:
	cd LIBFT && make fclean

ft_printfFclean:
	cd FT_PRINTF && make fclean

re:
	fclean all

.PHONY: fclean clean re all

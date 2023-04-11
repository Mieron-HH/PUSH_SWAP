NAME = push_swap.a
B_NAME = checker.a

CFILES = 	main.c \
		push_swap_utils.c \
		sort_algorithm.c \
		sort_functions.c \
		stack_a_moves.c \
		stack_b_moves.c \
		stack_ab_moves.c \
		utilities_1.c \
		utilities_2.c \
		utilities_3.c

B_CFILES = 	bonus/main.c \
		bonus/checker_a_moves.c \
		bonus/checker_b_moves.c \
		bonus/checker_ab_moves.c \
		bonus/checker_utils_1.c \
		bonus/checker_utils_2.c \
		bonus/checker_utils_3.c \
		bonus/parser.c \
		bonus/parser_util.c \
		bonus/GNL/get_next_line.c \
		bonus/GNL/get_next_line_utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = ${CFILES:.c=.o}
B_OBJECTS = ${B_CFILES:.c=.o}
LIBC = ar -rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	cd LIBFT && make
	cd FT_PRINTF && make
	find . -name "*.o" -type f -not -path "./bonus/*.o" | xargs $(LIBC) $(NAME)
	gcc $(NAME) -o push_swap

bonus: $(B_OBJECTS)
	cd bonus/LIBFT && make
	cd bonus/FT_PRINTF && make
	cd bonus && find . -type f -name "*.o" | xargs $(LIBC) $(B_NAME)
	cd bonus && gcc $(B_NAME) -o checker
	cd bonus && mv checker ../

clean:
	rm -f *.o

fclean: clean libftFclean ft_printfFclean
	rm -f $(NAME)
	rm -f push_swap

libftFclean:
	cd LIBFT && make fclean

ft_printfFclean:
	cd FT_PRINTF && make fclean

bfclean: bclean
	cd bonus && rm -f $(B_NAME)
	rm -f checker

bclean:
	cd bonus/LIBFT && make fclean
	cd bonus/FT_PRINTF && make fclean
	cd bonus/GNL && rm -f *.o
	cd bonus && rm -f *.o

re: fclean all

bre: bfclean bonus

.PHONY: fclean clean re all bonus

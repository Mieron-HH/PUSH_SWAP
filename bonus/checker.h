/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:31:22 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/12 12:48:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include	<unistd.h>
# include	<stdio.h>
# include	<limits.h>
# include	"LIBFT/libft.h"
# include	"FT_PRINTF/ft_printf.h"
# include	"GNL/get_next_line.h"

typedef struct t_Stack
{
	int				num;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct t_Stack	*next;
}	t_Stack;

int			is_stack_valid(t_Stack **stack, int argc, char **argv);
int			validate_input(char *s[], int size);
t_Stack		*extract_stack(char *s[], int start, int end);
t_Stack		*init_node(char *s);

int			push_to_b(t_Stack **a, t_Stack **b, int print);
int			push_to_a(t_Stack **b, t_Stack **a, int print);
int			rotate_a(t_Stack **a, int print);
int			rotate_b(t_Stack **b, int print);
int			r_rotate_a(t_Stack **a, int print);
int			r_rotate_b(t_Stack **b, int print);
int			swap_a(t_Stack **a, int print);
int			swap_b(t_Stack **b, int print);
int			r_rotate_all(t_Stack **a, t_Stack **b, int print);
int			rotate_all(t_Stack **a, t_Stack **b, int print);
int			swap_all(t_Stack **a, t_Stack **b, int print);

int			is_sorted(t_Stack *stack, int order);
int			has_duplicate(t_Stack **stack);
int			pre_atoi(char *s, int *num);
int			compare_atoi(char *s, int num, int sign_found, int leading_os);
t_Stack		*get_tail(t_Stack *stack);

void		parse_moves(char *str, t_Stack **a, t_Stack **b);
char		**validate_moves(char *str);
int			are_moves_valid(char **moves);
void		perform_moves(char **moves, t_Stack **a, t_Stack **b);
int			first_set_of_moves(char *move, t_Stack **a, t_Stack **b);
int			second_set_of_moves(char *move, t_Stack **a, t_Stack **b);

int			free_array(char **arry);
int			free_stack(t_Stack **stack);
int			ft_arrlen(char **str);

#endif

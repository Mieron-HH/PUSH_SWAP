/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:35:20 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/04 19:56:40 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	is_sorted(t_Stack *stack, int order)
{
	while (stack && stack->next)
	{
		if (order == 1 && stack->num > stack->next->num)
			return (0);
		if (order == -1 && stack->num < stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sort_three(t_Stack **stack)
{
	t_Stack	*s_h;
	t_Stack	*s_t;
	int		size;

	size = get_size(*stack);
	if (size > 3 || size <= 1)
		return (0);
	while (!is_sorted(*stack, 1))
	{
		s_h = *stack;
		s_t = get_tail(*stack);
		if (s_h->num > s_h->next->num && s_h->num > s_t->num
			&& rotate_a(stack, 1))
			continue ;
		else if (s_h->num > s_h->next->num && s_h->num < s_t->num
			&& swap_a(stack, 1))
			continue ;
		r_rotate_a(stack, 1);
	}
	return (1);
}

int	sort_two(t_Stack **stack, int order)
{
	t_Stack	*s_h;

	if (stack == NULL || get_size(*stack) < 2)
		return (0);
	s_h = *stack;
	if (order == 1 && s_h->num > s_h->next->num)
		swap_a(stack, 1);
	if (order == -1 && s_h->num < s_h->next->num)
		swap_b(stack, 1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:31:47 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/04 19:56:12 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_Stack **a, t_Stack **b)
{
	int	size;

	size = get_size(*a);
	if (size == 2 && !is_sorted(*a, 1))
		sort_two(a, 1);
	else if (size == 3)
		sort_three(a);
	else
		begin_sort(a, b);
}

void	begin_sort(t_Stack **a, t_Stack **b)
{
	push_until_three(a, b);
	sort_three(a);
	while (*b)
	{
		assign_target_position(a, b);
		calculate_all_cost(a, b);
		calculate_lowest_cost(a, b);
	}
	if (!is_sorted(*a, 1))
		shift_stack(a);
}

void	reset_position(t_Stack **stack)
{
	t_Stack	*iterate;
	int		i;

	iterate = *stack;
	i = 0;
	while (iterate)
	{
		iterate->pos = i;
		iterate = iterate->next;
		i++;
	}
}

void	assign_target_position(t_Stack **a, t_Stack **b)
{
	t_Stack	*iterate;
	int		t_pos;

	reset_position(a);
	reset_position(b);
	iterate = *b;
	t_pos = 0;
	while (iterate)
	{
		t_pos = locate_target(a, iterate->index, t_pos, INT_MAX);
		iterate->target_pos = t_pos;
		iterate = iterate->next;
	}
}

int	locate_target(t_Stack **a, int b_index, int t_pos, int t_index)
{
	t_Stack	*iterate;

	iterate = *a;
	while (iterate)
	{
		if (iterate->index > b_index && iterate->index < t_index)
		{
			t_index = iterate->index;
			t_pos = iterate->pos;
		}
		iterate = iterate->next;
	}
	if (t_index != INT_MAX)
		return (t_pos);
	iterate = *a;
	while (iterate)
	{
		if (iterate->index < t_index)
		{
			t_index = iterate->index;
			t_pos = iterate->pos;
		}
		iterate = iterate->next;
	}
	return (t_pos);
}

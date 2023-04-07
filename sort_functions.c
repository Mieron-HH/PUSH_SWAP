/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:31:38 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/04 19:57:50 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	calculate_all_cost(t_Stack **a, t_Stack **b)
{
	t_Stack	*iterate;
	int		size_a;
	int		size_b;

	iterate = *b;
	size_a = get_size(*a);
	size_b = get_size(*b);
	while (iterate)
	{
		iterate->cost_b = iterate->pos;
		if (iterate->pos > size_b / 2)
			iterate->cost_b = (size_b - iterate->pos) * -1;
		iterate->cost_a = iterate->target_pos;
		if (iterate->target_pos > size_a / 2)
			iterate->cost_a = (size_a - iterate->target_pos) * -1;
		iterate = iterate->next;
	}
}

void	calculate_lowest_cost(t_Stack **a, t_Stack **b)
{
	t_Stack	*iterate;
	int		lowest;
	int		cost_a;
	int		cost_b;

	iterate = *b;
	lowest = INT_MAX;
	while (iterate)
	{
		if (abs(iterate->cost_a) + abs(iterate->cost_b) < abs(lowest))
		{
			cost_a = iterate->cost_a;
			cost_b = iterate->cost_b;
			lowest = abs(iterate->cost_a) + abs(iterate->cost_b);
		}
		iterate = iterate->next;
	}
	move_lowest_cost(a, b, cost_a, cost_b);
}

void	move_lowest_cost(t_Stack **a, t_Stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rotate_all(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_a < 0)
	{
		r_rotate_all(a, b);
		cost_a++;
		cost_b++;
	}
	check_cost_to_rotate(a, 'a', cost_a);
	check_cost_to_rotate(b, 'b', cost_b);
	push_to_a(b, a, 1);
}

void	check_cost_to_rotate(t_Stack **stack, char stck, int cost)
{
	while (cost > 0)
	{
		if (stck == 'a')
			rotate_a(stack, 1);
		else
			rotate_b(stack, 1);
		cost--;
	}
	while (cost < 0)
	{
		if (stck == 'a')
			r_rotate_a(stack, 1);
		else
			r_rotate_b(stack, 1);
		cost++;
	}
}

int	abs(int num)
{
	if (num >= 0)
		return (num);
	return (num * -1);
}

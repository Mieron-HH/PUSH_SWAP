/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:22:20 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/08 02:37:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	assign_index(t_Stack *stack_a, int size)
{
	t_Stack	*ptr;
	t_Stack	*highest;
	int		num;

	while (--size > 0)
	{
		ptr = stack_a;
		num = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->num == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->num > num && ptr->index == 0)
			{
				num = ptr->num;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

void	push_until_three(t_Stack **a, t_Stack **b)
{
	int	mid;
	int	head_found;
	int	head_num;

	while (get_size(*a) > 3)
	{
		head_found = 0;
		head_num = 0;
		mid = get_mid_point(*a);
		while (!head_found && (*a)->num != head_num)
		{
			if ((*a)->num >= mid)
			{
				if (!head_found)
				{
					head_found = 1;
					head_num = (*a)->num;
				}
				rotate_a(a, 1);
				continue ;
			}
			push_to_b(a, b, 1);
		}
	}
}

void	shift_stack(t_Stack **stack)
{
	int	lowest_pos;
	int	size;

	lowest_pos = get_lowest_index_pos(stack);
	size = get_size(*stack);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			r_rotate_a(stack, 1);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(stack, 1);
			lowest_pos--;
		}
	}
}

int	get_lowest_index_pos(t_Stack **stack)
{
	t_Stack	*iterate;
	int		lowest_index;
	int		pos;

	reset_position(stack);
	iterate = *stack;
	lowest_index = INT_MAX;
	while (iterate)
	{
		if (iterate->index < lowest_index)
		{
			lowest_index = iterate->index;
			pos = iterate->pos;
		}
		iterate = iterate->next;
	}
	return (pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:31:43 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/11 17:10:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	has_duplicate(struct t_Stack **stack)
{
	t_Stack	*iterate;
	t_Stack	*tmp;
	t_Stack	*head;
	t_Stack	*last;
	char		*itoa;

	itoa = ft_itoa((*stack)->num);
	head = init_node(itoa);
	if (!head && free_up(&itoa))
		return (-1);
	last = head;
	iterate = (*stack)->next;
	while (iterate && free_up(&itoa))
	{
		tmp = head;
		while (tmp && tmp->num != iterate->num)
			tmp = tmp->next;
		if (tmp && tmp->num == iterate->num)
			return (free_stack(&head) * free_stack(stack) * 0 + 1);
		itoa = ft_itoa(iterate->num);
		last->next = init_node(itoa);
		last = last->next;
		iterate = iterate->next;
	}
	return (free_stack(&head) * free_up(&itoa) * 0);
}

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
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_size(*a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*a)->index <= stack_size / 2)
		{
			push_to_b(a, b, 1);
			pushed++;
		}
		else
			rotate_a(a, 1);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		push_to_b(a, b, 1);
		pushed++;
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

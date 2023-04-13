/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:42:54 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/13 16:47:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

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
		return (1);
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

t_Stack	*get_tail(t_Stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

int	get_size(t_Stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 1;
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	free_stack(t_Stack **stack)
{
	t_Stack	*tmp;

	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	return (1);
}

int	check_leak(char *str, int do_free)
{
	if (do_free)
		free_up(&str);
	return (1);
}

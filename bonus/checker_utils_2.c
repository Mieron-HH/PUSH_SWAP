/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:42:54 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 20:42:24 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

int	has_duplicate(struct t_Stack *stack)
{
	t_Stack	*tmp;
	t_Stack	*head;
	t_Stack	*last;

	head = init_node(ft_itoa(stack->num));
	if (!head)
		return (-1);
	last = head;
	stack = stack->next;
	while (stack)
	{
		tmp = head;
		while (tmp && tmp->num != stack->num)
			tmp = tmp->next;
		if (tmp && tmp->num == stack->num)
			return (free_stack(&head) * 0 + 1);
		last->next = init_node(ft_itoa(stack->num));
		last = last->next;
		stack = stack->next;
	}
	return (free_stack(&head) * 0);
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

void	print_stack(t_Stack *stack)
{
	if (stack != NULL)
	{
		ft_printf("|||   ");
		while (stack)
		{
			ft_printf("%d   ", stack->num);
			stack = stack->next;
		}
		ft_printf("|||\n");
	}
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

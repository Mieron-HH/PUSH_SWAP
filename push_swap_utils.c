/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:32:15 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/04 19:29:33 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	validate_input(char *s[], int size)
{
	int	i;
	int	j;
	int	sign_found;

	if (!s)
		return (-1);
	i = 0;
	while (++i < size)
	{
		j = -1;
		sign_found = 0;
		while (s[i][++j])
		{
			if (sign_found && (s[i][j] == '-' || s[i][j] == '+'))
				return (-1);
			if (s[i][j] == '-' || s[i][j] == '+')
				sign_found++;
			else if (s[i][j] < '0' || s[i][j] > '9')
				return (-1);
		}
	}
	return (1);
}

t_Stack	*extract_stack(char *s[], int start, int end)
{
	t_Stack	*head;
	t_Stack	*current;
	t_Stack	*node;

	if (s == NULL)
		return (NULL);
	head = NULL;
	while (++start < end)
	{
		node = init_node(ft_atoi(s[start]));
		if (!node && free_stack(&head))
			return (NULL);
		if (head == NULL)
		{
			head = node;
			current = head;
			continue ;
		}
		current->next = node;
		current = current->next;
	}
	return (head);
}

int	has_duplicate(struct t_Stack *stack)
{
	t_Stack	*tmp;
	t_Stack	*head;
	t_Stack	*last;

	head = init_node(stack->num);
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
		last->next = init_node(stack->num);
		last = last->next;
		stack = stack->next;
	}
	return (free_stack(&head) * 0);
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

t_Stack	*init_node(int num)
{
	t_Stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = 0;
	node->pos = -1;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

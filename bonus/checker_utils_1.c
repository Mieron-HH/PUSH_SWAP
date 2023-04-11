/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:35:19 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/09 21:39:30 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

int	validate_digit(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '-' || *s == '+')
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	extract_from_string(t_Stack **stack, char *s)
{
	t_Stack	*tail;
	t_Stack	*node;

	if (ft_strlen(s) == 0 && free_stack(stack))
		return (0);
	if (!validate_digit(s) && free_stack(stack))
		return (0);
	node = init_node(s);
	if (!node && free_stack(stack))
		return (0);
	if (*stack == NULL)
	{
		*stack = node;
		return (1);
	}
	tail = get_tail(*stack);
	tail->next = node;
	return (1);
}

int	extract_from_string_array(t_Stack **stack, char *s)
{
	t_Stack	*current;
	t_Stack	*node;
	char	**digits;

	current = get_tail(*stack);
	digits = ft_split(s, ' ');
	while (*digits)
	{
		if (!validate_digit(*digits) && free_stack(stack))
			return (0);
		node = init_node(*digits);
		if (!node && free_stack(stack))
			return (0);
		if (*stack == NULL)
		{
			*stack = node;
			current = *stack;
			digits++;
			continue ;
		}
		current->next = node;
		current = current->next;
		digits++;
	}
	return (1);
}

t_Stack	*extract_stack(char *s[], int start, int end)
{
	t_Stack	*head;

	if (s == NULL)
		return (NULL);
	head = NULL;
	while (++start < end)
	{
		if (ft_strnstr(s[start], " ", ft_strlen(s[start])))
		{
			if (!extract_from_string_array(&head, s[start]))
				return (NULL);
			continue ;
		}
		if (!extract_from_string(&head, s[start]))
			return (NULL);
	}
	return (head);
}

t_Stack	*init_node(char *s)
{
	t_Stack	*node;
	int		num;

	if (!pre_atoi(s, &num))
		return (NULL);
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

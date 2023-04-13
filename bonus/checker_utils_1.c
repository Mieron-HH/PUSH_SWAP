/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:35:19 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/13 15:55:05 by codespace        ###   ########.fr       */
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
		*stack = node;
	else
	{
		tail = get_tail(*stack);
		tail->next = node;
	}
	return (1);
}

int	extract_from_string_array(t_Stack **stack, char *s)
{
	t_Stack	*current;
	t_Stack	*node;
	char	**digits;
	int		i;

	i = -1;
	current = get_tail(*stack);
	digits = ft_split(s, ' ');
	while (++i < ft_arrlen(digits))
	{
		if (!validate_digit(digits[i]) && free_stack(stack))
			return (free_array(digits) * 0);
		node = init_node(digits[i]);
		if (!node && free_stack(stack))
			return (free_array(digits) * 0);
		if (*stack == NULL)
		{
			*stack = node;
			current = *stack;
			continue ;
		}
		current->next = node;
		current = current->next;
	}
	free_array(digits);
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
			if (!extract_from_string_array(&head, s[start])
				&& free_stack(&head))
				return (NULL);
			continue ;
		}
		if (!extract_from_string(&head, s[start]) && free_stack(&head))
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

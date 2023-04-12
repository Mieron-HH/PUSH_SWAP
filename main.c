/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:30:04 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/12 12:33:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = extract_stack(argv, 0, argc);
	if (!stack_a && ft_printf("%E", "Error\n"))
		return (0);
	if (has_duplicate(&stack_a) && ft_printf("%E", "Error\n"))
		return (0);
	if (is_sorted(stack_a, 1) && free_stack(&stack_a))
		return (0);
	assign_index(stack_a, get_size(stack_a) + 1);
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
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

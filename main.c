/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:10:01 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/04 20:35:08 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	if (argc <= 2)
	{
		if (argc == 2)
			ft_printf(argv[1]);
		return (0);
	}
	if (validate_input(argv, argc) == -1)
		return (ft_printf("Please provide integers only! :/\n") * 0);
	stack_b = NULL;
	stack_a = extract_stack(argv, 0, argc);
	if (!stack_a)
		return (ft_printf("Couldn't extract integers! :/\n") * 0);
	if (has_duplicate(stack_a))
		return (ft_printf("Duplicates found! :/\n") * 0);
	if (is_sorted(stack_a, 1))
		return (ft_printf("It's already sorted fam! :|\n") * 0);
	assign_index(stack_a, get_size(stack_a) + 1);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:26:37 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 22:25:48 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	char	*line;
	char	*moves;

	if (argc == 1)
		return (0);
	stack_a = extract_stack(argv, 0, argc);
	if (!stack_a && ft_printf("%E", "Error\n"))
		return (0);
	if (has_duplicate(stack_a) && ft_printf("%E", "Error\n"))
		return (0);
	stack_b = NULL;
	moves = ft_strdup("");
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		moves = ft_strjoin(moves, line);
		free((void *) line);
		line = get_next_line(STDIN_FILENO);
	}
	parse_moves(moves, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:32:19 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/13 15:42:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

void	perform_moves(char **moves, t_Stack **a, t_Stack **b)
{
	int i;

	i = -1;
	while (moves[++i])
	{
		if (first_set_of_moves(moves[i], a, b))
			continue ;
		if (second_set_of_moves(moves[i], a, b))
			continue ;
		break ;
	}
	if (is_sorted(*a, 1) && *b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	first_set_of_moves(char *move, t_Stack **a, t_Stack **b)
{
	if (ft_strncmp(move, "sa", ft_strlen(move)) == 0 && swap_a(a, 0))
		return (1);
	if (ft_strncmp(move, "sb", ft_strlen(move)) == 0 && swap_b(b, 0))
		return (1);
	if (ft_strncmp(move, "ra", ft_strlen(move)) == 0 && rotate_a(a, 0))
		return (1);
	if (ft_strncmp(move, "rb", ft_strlen(move)) == 0 && rotate_b(b, 0))
		return (1);
	if (ft_strncmp(move, "pa", ft_strlen(move)) == 0 && push_to_a(b, a, 0))
		return (1);
	if (ft_strncmp(move, "pb", ft_strlen(move)) == 0 && push_to_b(a, b, 0))
		return (1);
	return (0);
}

int	second_set_of_moves(char *move, t_Stack **a, t_Stack **b)
{
	if (ft_strncmp(move, "rra", 3) == 0 && r_rotate_a(a, 0))
		return (1);
	if (ft_strncmp(move, "rrb", 3) == 0 && r_rotate_b(b, 0))
		return (1);
	if (ft_strncmp(move, "ss", ft_strlen(move)) == 0 && swap_all(a, b, 0))
		return (1);
	if (ft_strncmp(move, "rr", ft_strlen(move)) == 0 && rotate_all(a, b, 0))
		return (1);
	if (ft_strncmp(move, "rrr", 3) == 0 && r_rotate_all(a, b, 0))
		return (1);
	return (0);
}

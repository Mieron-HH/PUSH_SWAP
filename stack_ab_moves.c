/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:30:57 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/13 16:46:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	rotate_all(struct t_Stack **a, struct t_Stack **b)
{
	if (rotate_a(a, 0) + rotate_b(b, 0) == 2)
		return (ft_printf("rr\n") * 0 + 1);
	return (0);
}

int	r_rotate_all(struct t_Stack **a, struct t_Stack **b)
{
	if (r_rotate_a(a, 0) + r_rotate_b(b, 0) == 2)
		return (ft_printf("rrr\n") * 0 + 1);
	return (0);
}

int	swap_all(struct t_Stack **a, struct t_Stack **b)
{
	if (swap_a(a, 0) * swap_b(b, 0) == 2)
		return (ft_printf("ss\n") * 0 + 1);
	return (0);
}

int	check_leak(char *str, int do_free)
{
	if (do_free)
		free_up(&str);
	return (1);
}

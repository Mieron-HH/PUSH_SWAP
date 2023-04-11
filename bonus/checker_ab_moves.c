/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ab_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:41:54 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 20:02:51 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

int	rotate_all(struct t_Stack **a, struct t_Stack **b, int print)
{
	if (rotate_a(a, 0) + rotate_b(b, 0) == 2)
	{
		if (print)
			ft_printf("rr\n");
		return (1);
	}
	return (0);
}

int	r_rotate_all(struct t_Stack **a, struct t_Stack **b, int print)
{
	if (r_rotate_a(a, 0) + r_rotate_b(b, 0) == 2)
	{
		if (print)
			ft_printf("rrr\n");
		return (1);
	}
	return (0);
}

int	swap_all(struct t_Stack **a, struct t_Stack **b, int print)
{
	if (swap_a(a, 0) * swap_b(b, 0) == 2)
	{
		if (print)
			ft_printf("ss\n");
		return (1);
	}
	return (0);
}

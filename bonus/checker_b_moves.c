/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_b_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:40:56 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 20:14:58 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

int	swap_b(struct t_Stack **b, int print)
{
	t_Stack	*first;
	t_Stack	*second;
	int		tmp;

	if (*b == NULL || (*b)->next == NULL)
		return (0);
	first = *b;
	second = (*b)->next;
	tmp = first->num;
	first->num = second->num;
	second->num = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	if (print)
		ft_printf("sb\n");
	return (1);
}

int	push_to_b(struct t_Stack **a, struct t_Stack **b, int print)
{
	t_Stack	*head;

	if (*a == NULL)
		return (0);
	head = *a;
	*a = (*a)->next;
	if (*b == NULL)
	{
		*b = head;
		(*b)->next = NULL;
	}
	else
	{
		head->next = *b;
		*b = head;
	}
	if (print)
		ft_printf("pb\n");
	return (1);
}

int	rotate_b(struct t_Stack **b, int print)
{
	t_Stack	*first;
	t_Stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return (0);
	first = *b;
	last = *b;
	*b = (*b)->next;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
	if (print)
		ft_printf("rb\n");
	return (1);
}

int	r_rotate_b(struct t_Stack **b, int print)
{
	t_Stack	*last;
	t_Stack	*first;

	if (*b == NULL || (*b)->next == NULL)
		return (0);
	last = *b;
	while (last->next->next)
		last = last->next;
	first = last->next;
	first->next = *b;
	*b = first;
	last->next = NULL;
	if (print)
		ft_printf("rrb\n");
	return (1);
}

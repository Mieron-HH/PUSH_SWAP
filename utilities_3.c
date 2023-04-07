/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:29:57 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/04 18:29:57 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	get_mid_point(t_Stack *stack)
{
	int	sum;
	int	size;

	sum = 0;
	size = 0;
	while (stack)
	{
		size++;
		sum += stack->num;
		stack = stack->next;
	}
	if (sum % size == 0)
		return (sum / size);
	return (sum / size + 1);
}

t_Stack	*get_tail(t_Stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_Stack	*get_before_tail(t_Stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

int	get_size(t_Stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 1;
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	print_stack(t_Stack *stack)
{
	if (stack != NULL)
	{
		ft_printf("| ");
		while (stack)
		{
			ft_printf("%d ", stack->num);
			stack = stack->next;
		}
		ft_printf("|\n");
	}
}

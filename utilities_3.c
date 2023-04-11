/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:31:54 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/11 16:38:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_Stack	*get_tail(t_Stack *stack)
{
	while (stack && stack->next)
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

int	ft_arrlen(char **str)
{
	int len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	free_up(char **str)
{
	free((void *) *str);
	*str = NULL;
	return (1);
}

void	print_stack(t_Stack *stack)
{
	if (stack != NULL)
	{
		ft_printf("|||");
		while (stack)
		{
			ft_printf("%d ", stack->num);
			stack = stack->next;
		}
		ft_printf("|||\n");
	}
}

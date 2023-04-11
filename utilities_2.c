/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:31:49 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/11 15:42:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	is_sorted(t_Stack *stack, int order)
{
	while (stack && stack->next)
	{
		if (order == 1 && stack->num > stack->next->num)
			return (0);
		if (order == -1 && stack->num < stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sort_three(t_Stack **stack)
{
	t_Stack	*s_h;
	t_Stack	*s_t;
	int		size;

	size = get_size(*stack);
	if (size > 3 || size <= 1)
		return (0);
	while (!is_sorted(*stack, 1))
	{
		s_h = *stack;
		s_t = get_tail(*stack);
		if (s_h->num > s_h->next->num && s_h->num > s_t->num
			&& rotate_a(stack, 1))
			continue ;
		else if (s_h->num > s_h->next->num && s_h->num < s_t->num
			&& swap_a(stack, 1))
			continue ;
		r_rotate_a(stack, 1);
	}
	return (1);
}

int	sort_two(t_Stack **stack, int order)
{
	t_Stack	*s_h;

	if (stack == NULL || get_size(*stack) != 2)
		return (0);
	s_h = *stack;
	if (order == 1 && s_h->num > s_h->next->num)
		swap_a(stack, 1);
	if (order == -1 && s_h->num < s_h->next->num)
		swap_b(stack, 1);
	return (1);
}

int	pre_atoi(char *s, int *num)
{
	int	i;
	int	sign;
	int	len;

	i = 0;
	sign = 0;
	len = ft_strlen(s);
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		sign++;
	while (s[sign + i] && s[sign + i] == '0')
		i++;
	if (len - sign - i > 10)
		return (0);
	if (i > 0 && !s[sign + i])
		*num = 0;
	else if (s[sign + i] < '0' || s[sign + i] > '9')
		return (0);
	*num = ft_atoi(s);
	if (!compare_atoi(s, *num, sign, i) && free_up(&s))
		return (0);
	return (1);
}

int	compare_atoi(char *s, int num, int sign_found, int leading_os)
{
	char	*itoa;
	int	l_os_found;
	int	joined;

	l_os_found = 0;
	joined = 0;
	if (leading_os > 0)
		l_os_found++;
	leading_os++;
	if (sign_found > 0)
		s++;
	while (--leading_os > 0)
		s++;
	if (ft_strlen(s) == 0 && l_os_found && ++joined)
		s = ft_strjoin("\0", "0");
	else if (sign_found && ++joined)
		s = ft_strjoin("-", s);
	itoa = ft_itoa(num);
	if (s && ft_strncmp(itoa, s, ft_strlen(s)) == 0 && free_up(&itoa))
	{
		joined = joined && free_up(&s);
		return (1);
	}
	joined = joined && free_up(&s);
	free_up((void *) itoa);
	return (0);
}

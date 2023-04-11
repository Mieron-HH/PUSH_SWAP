/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:03:13 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 22:28:02 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

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
	if (!compare_atoi(s, *num, sign, i))
		return (0);
	return (1);
}

int	compare_atoi(char *s, int num, int sign_found, int leading_os)
{
	int	l_os_found;

	l_os_found = 0;
	if (leading_os > 0)
		l_os_found++;
	leading_os++;
	if (sign_found > 0)
		s++;
	while (--leading_os > 0)
		s++;
	if (ft_strlen(s) == 0 && l_os_found)
		s = ft_strjoin("\0", "0");
	else if (sign_found)
		s = ft_strjoin("-", s);
	if (ft_strncmp(ft_itoa(num), s, ft_strlen(s)) == 0)
		return (1);
	return (0);
}

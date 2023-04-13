/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:03:13 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/13 16:14:30 by codespace        ###   ########.fr       */
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
	char	*itoa;
	int		l_os_found;
	int		joined;

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
		s = ft_strjoin("\0", "0", 0);
	else if (sign_found && ++joined)
		s = ft_strjoin("-", s, 0);
	itoa = ft_itoa(num);
	if (s && ft_strncmp(itoa, s, ft_strlen(s)) == 0 && free_up(&itoa))
	{
		joined = joined && free_up(&s);
		return (1);
	}
	if (joined)
		free_up(&s);
	free_up(&itoa);
	return (0);
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

int	free_array(char **arry)
{
	int	len;
	int	i;

	len = ft_arrlen(arry);
	if (len == 0)
	{
		free(arry);
		return (0);
	}
	i = -1;
	while (++i < len)
		free_up(&(arry[i]));
	free(arry);
	return (1);
}


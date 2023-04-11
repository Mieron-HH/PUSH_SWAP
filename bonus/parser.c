/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:59:48 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 20:45:47 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

void	parse_moves(char *str, t_Stack **a, t_Stack **b)
{
	char	**moves;

	if (!str && ft_printf("%E\n", "Error"))
		return ;
	moves = validate_moves(str);
	if (moves == NULL && ft_printf("%E\n", "Error"))
		return ;
	perform_moves(moves, a, b);
}

char	**validate_moves(char *str)
{
	char	**moves;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	str = ft_strtrim(str, " ");
	while (str[++i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
	}
	moves = ft_split(str, ' ');
	if (moves == NULL)
		return (NULL);
	if (!are_moves_valid(moves))
		return (NULL);
	return (moves);
}

int	are_moves_valid(char **moves)
{
	moves--;
	while (*(++moves))
	{
		if (ft_strncmp(*moves, "sa", 2) == 0
			|| ft_strncmp(*moves, "sb", 2) == 0)
			continue ;
		if (ft_strncmp(*moves, "ss", 2) == 0)
			continue ;
		if (ft_strncmp(*moves, "ra", 2) == 0
			|| ft_strncmp(*moves, "rb", 2) == 0)
			continue ;
		if (ft_strncmp(*moves, "rr", 2) == 0)
			continue ;
		if (ft_strncmp(*moves, "pa", 2) == 0
			|| ft_strncmp(*moves, "pb", 2) == 0)
			continue ;
		if (ft_strncmp(*moves, "rra", 3) == 0
			|| ft_strncmp(*moves, "rrb", 3) == 0)
			continue ;
		if (ft_strncmp(*moves, "rrr", 3) == 0)
			continue ;
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:59:48 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/13 12:28:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

void	parse_moves(char *str, t_Stack **a, t_Stack **b)
{
	char	**moves;

	if (!str && ft_printf("%E\n", "Error"))
		return ;
	moves = validate_moves(str);
	if (moves == NULL)
		ft_printf("%E\n", "Error");
	else
		perform_moves(moves, a, b);
	free_stack(a);
	free_stack(b);
	free_array(moves);
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
	free_up(&str);
	if (moves == NULL)
		return (NULL);
	if (!are_moves_valid(moves) && free_array(moves))
		return (NULL);
	return (moves);
}

int	are_moves_valid(char **moves)
{
	moves--;
	while (*(++moves))
	{
		if (ft_strncmp(*moves, "sa", (int) ft_strlen(*moves)) == 0
			|| ft_strncmp(*moves, "sb", (int) ft_strlen(*moves)) == 0)
			continue ;
		if (ft_strncmp(*moves, "ss", (int) ft_strlen(*moves)) == 0)
			continue ;
		if (ft_strncmp(*moves, "ra", (int) ft_strlen(*moves)) == 0
			|| ft_strncmp(*moves, "rb", (int) ft_strlen(*moves)) == 0)
			continue ;
		if (ft_strncmp(*moves, "rr", (int) ft_strlen(*moves)) == 0)
			continue ;
		if (ft_strncmp(*moves, "pa", (int) ft_strlen(*moves)) == 0
			|| ft_strncmp(*moves, "pb", (int) ft_strlen(*moves)) == 0)
			continue ;
		if (ft_strncmp(*moves, "rra", (int) ft_strlen(*moves)) == 0
			|| ft_strncmp(*moves, "rrb", (int) ft_strlen(*moves)) == 0)
			continue ;
		if (ft_strncmp(*moves, "rrr", (int) ft_strlen(*moves)) == 0)
			continue ;
		return (0);
	}
	return (1);
}

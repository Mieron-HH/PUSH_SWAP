/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:33:19 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/08 21:36:48 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_puterr(const char *s)
{
	int	count;

	if (!s)
	{
		write(2, "(null)", 6);
		return (6);
	}
	count = 0;
	while (*s)
	{
		write(2, &(*s), 1);
		count++;
		s++;
	}
	return (count);
}

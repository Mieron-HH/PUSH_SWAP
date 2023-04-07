/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:21:55 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/23 16:21:55 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_validate(va_list args, char type)
{
	if (type == '\0')
		return (0);
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(args, char const *)));
	if (type == 'p')
		return (ft_putpointer(va_arg(args, unsigned long long)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (type == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (type == 'x')
		return (ft_puthex(va_arg(args, unsigned long), LOWER_HEX));
	if (type == 'X')
		return (ft_puthex(va_arg(args, unsigned long), UPPER_HEX));
	return (0);
}

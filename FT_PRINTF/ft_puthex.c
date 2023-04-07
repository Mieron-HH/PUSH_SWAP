/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:05:15 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/27 15:42:53 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

unsigned int	ft_hex_pow(unsigned int n)
{
	unsigned int	pow;

	pow = 1;
	n /= 16;
	while (n > 0)
	{
		pow *= 16;
		n /= 16;
	}
	return (pow);
}

int	ft_check_hex_zeros(unsigned int num)
{
	unsigned int	denom;
	int				count;
	unsigned int	remainder;

	if (num < 16)
		return (0);
	denom = ft_hex_pow(num);
	count = 0;
	while (denom > 15)
	{
		remainder = num / denom;
		if ((remainder * 16) != (num / (denom / 16)))
			return (count);
		count += ft_putchar('0');
		denom /= 16;
	}
	return (count);
}

int	ft_puthex(unsigned int p, char const *HEX)
{
	int				count;
	unsigned int	remainder;

	count = 0;
	if (p == 0)
		count += ft_putchar('0');
	while (p > 0)
	{
		remainder = p / ft_hex_pow(p);
		count += ft_putchar(HEX[remainder]);
		count += ft_check_hex_zeros(p);
		p %= ft_hex_pow(p);
	}
	return (count);
}

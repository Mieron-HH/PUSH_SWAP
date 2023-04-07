/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:05:15 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/27 15:45:34 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

unsigned long long	ft_pointer_pow(unsigned long long n)
{
	unsigned long long	pow;

	pow = 1;
	n /= 16;
	while (n > 0)
	{
		pow *= 16;
		n /= 16;
	}
	return (pow);
}

int	ft_check_pointer_zeros(unsigned long long num)
{
	unsigned long long	denom;
	int					count;
	unsigned long long	remainder;

	if (num < 16)
		return (0);
	denom = ft_pointer_pow(num);
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

int	ft_putpointer(unsigned long long p)
{
	int					count;
	unsigned long long	remainder;

	count = 0;
	count += ft_putstr("0x");
	if (p == 0)
		count += ft_putchar('0');
	while (p > 0)
	{
		remainder = p / ft_pointer_pow(p);
		count += ft_putchar(LOWER_HEX[remainder]);
		count += ft_check_pointer_zeros(p);
		p %= ft_pointer_pow(p);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:36:40 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/26 21:10:21 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

unsigned int	ft_unsigned_pow(unsigned int num)
{
	int	pow;

	pow = 1;
	num /= 10;
	while (num > 0)
	{
		pow *= 10;
		num /= 10;
	}
	return (pow);
}

int	ft_check_unsigned_zeros(int num)
{
	unsigned int	denom;
	int				count;
	unsigned int	remainder;

	if (num <= 9)
		return (0);
	denom = ft_unsigned_pow(num);
	count = 0;
	while (denom > 1)
	{
		remainder = num / denom;
		if ((remainder * 10) != (num / (denom / 10)))
			return (count);
		count += ft_putchar('0');
		denom /= 10;
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int				count;
	unsigned int	remainder;

	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	while (n > 0)
	{
		remainder = n / ft_unsigned_pow(n);
		count += ft_putchar('0' + remainder);
		count += ft_check_unsigned_zeros(n);
		n %= ft_unsigned_pow(n);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:21:41 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/23 16:21:41 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_pow(int num)
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

int	ft_check_zeros(int num)
{
	int	denom;
	int	count;
	int	remainder;

	if (num <= 9)
		return (0);
	denom = ft_pow(num);
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

int	ft_putnbr(int n)
{
	int	count;
	int	remainder;

	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	if (n == -2147483648)
	{
		n = 147483648;
		count += ft_putstr("-2");
	}
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	while (n > 0)
	{
		remainder = n / ft_pow(n);
		count += ft_putchar('0' + remainder);
		count += ft_check_zeros(n);
		n %= ft_pow(n);
	}
	return (count);
}

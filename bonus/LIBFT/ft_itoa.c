/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:58:49 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/09 18:09:28 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_power(int n)
{
	int	i;

	i = 1;
	while (n-- > 0)
		i *= 10;
	return (i);
}

int	ft_digit_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_serialize(char *number, int n, int edge_case)
{
	int	i;
	int	len;

	i = 0;
	len = ft_digit_count(n);
	if (edge_case == 2)
	{
		number[i++] = '-';
		number[i++] = '2';
	}
	if (edge_case == 1)
		number[i++] = '-';
	if (n == 0)
	{
		number[0] = '0';
		return (number);
	}
	while (len > 0)
	{
		number[i++] = '0' + (n / ft_power(--len));
		n = n % ft_power(len);
	}
	number[i] = '\0';
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		edge_case;

	edge_case = 0;
	if (n == -2147483648)
	{
		n = 147483648;
		edge_case = 2;
	}
	if (n < 0)
	{
		edge_case = 1;
		n *= -1;
	}
	number = ft_calloc(ft_digit_count(n) + edge_case + 1, sizeof(char));
	if (number == NULL)
		return (NULL);
	return (ft_serialize(number, n, edge_case));
}

// int	main(void)
// {
// 	char *number = ft_itoa(NULL);
// 	printf("number = %s\n", number);
// 	return (0);
// }

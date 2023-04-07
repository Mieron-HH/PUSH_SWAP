/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:58:41 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/13 13:58:41 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_atoi(const char *str)
{
	long long int	sign;
	long long int	result;
	size_t			i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - 48);
	return (result * sign);
}

// int main()
// {
// 	int val;
// 	char str[20] = "  \t \n21474836489223";
// 	val = ft_atoi(str);
// 	printf("String value = %s, Int value = %d\n", str, val);

// 	char str2[20] = "tutorialspoint.com";
// 	val = ft_atoi(str2);
// 	printf("String value = %s, Int value = %d\n", str2, val);

// 	return (0);
// }

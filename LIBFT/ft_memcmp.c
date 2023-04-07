/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:42:43 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/13 14:42:43 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	if (n == 0)
		return (0);
	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	while (*cpy1 == *cpy2 && n-- > 1)
	{
		cpy1++;
		cpy2++;
	}
	return (*cpy1 - *cpy2);
}

// int main(void)
// {
// 	char str1[15];
// 	char str2[15];
// 	int ret;

// 	memcpy(str1, "atoms\0\0\0\0", 10);
// 	memcpy(str2, "atoms\0abc", 10);

// 	ret = ft_memcmp(str1, str2, 10);
// 	printf("ret = %d\n", ret);
// 	if (ret > 0)
// 	{
// 		printf("str2 is less than str1");
// 	}
// 	else if (ret < 0)
// 	{
// 		printf("str1 is less than str2");
// 	}
// 	else
// 	{
// 		printf("str1 is equal to str2");
// 	}

// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:41:54 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/13 14:41:54 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && n-- > 0)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// int main(void)
// {
// 	char str1[15];
// 	char str2[15];
// 	int ret;

// 	strcpy(str1, "test\200");
// 	strcpy(str2, "test\0");

// 	ret = ft_strncmp(str1, str2, 6);
// 	printf("ret = %d\n", ret);
// 	if (ret < 0)
// 	{
// 		printf("str1 is less than str2");
// 	}
// 	else if (ret > 0)
// 	{
// 		printf("str2 is less than str1");
// 	}
// 	else
// 	{
// 		printf("str1 is equal to str2");
// 	}

// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:42:06 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/13 14:42:06 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	const char str[] = "http://wwwtutorialspointcom";
// 	const char ch = '.';
// 	char *ret;

// 	ret = ft_memchr(str, ch, strlen(str));

// 	printf("String after |%c| is - |%s|\n", ch, ret);

// 	return (0);
// }

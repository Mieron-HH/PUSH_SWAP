/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:30:37 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/13 22:36:34 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				step;
	unsigned char	*dest;
	unsigned char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	step = 1;
	if (dst > src)
	{
		dest = (unsigned char *)(dst + len - 1);
		source = (unsigned char *)(src + len - 1);
		step = -1;
	}
	while (len-- > 0)
	{
		*dest = *source;
		dest += step;
		source += step;
	}
	return (dst);
}

// int main(void)
// {
// 	char str1[50] = "Mieron";
// 	char str2[50] = "Mieron";
// 	ft_memmove(str1, str1 + 1, 4);
// 	memmove(str2, str2 + 1, 4);
// 	printf("Custom in = %s\n", str1);
// 	printf("Built in = %s\n", str2);
// }
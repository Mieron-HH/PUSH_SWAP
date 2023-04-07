/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:04:38 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/16 18:04:20 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	count;

	if (dstsize == 0)
		return (ft_strlen(src));
	count = dstsize;
	dst_size = 0;
	while (*dst != '\0' && count-- != 0 && dst_size++ < dstsize)
		dst++;
	if (dst_size == dstsize)
		return (dstsize + ft_strlen(src));
	count = dstsize - dst_size;
	src_size = 0;
	while (src[src_size] != '\0')
	{
		if (count > 1)
		{
			*dst++ = src[src_size];
			count--;
		}
		src_size++;
	}
	*dst = '\0';
	return (dst_size + src_size);
}

// int	main(void)
// {
// 	char b[0xF] = "nyan !";

// 	size_t ret = ft_strlcat(((void *)0), b, 0);
// 	printf("ret = %d, result = %s\n", (int)ret, b);
// 	return (0);
// }
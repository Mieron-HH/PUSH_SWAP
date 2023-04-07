/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:07:49 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/18 23:01:55 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	s_len;

	if (s == NULL)
		return (NULL);
	s_len = (unsigned int)ft_strlen(s);
	if ((int)(s_len - start) < 0)
		substr = ft_calloc(1, sizeof(char));
	else if ((int)len > (int)(s_len - start))
		substr = ft_calloc((s_len - start + 1), sizeof(char));
	else
		substr = ft_calloc((len + 1), sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len && (start + i < s_len))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char *s = ft_substr("1", 42, 42000000);
// 	printf("result = %s\n", s);
// 	printf("bool = %d, s = %s\n", strcmp(s, ""), s);
// 	return (0);
// }
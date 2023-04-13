/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:01:43 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/13 12:15:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	<stdio.h>
#include	<string.h>

int	ft_find_char(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char *str, char const *set)
{
	char	*result;
	size_t	start;
	size_t	len;
	size_t	i;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	start = 0;
	while ((start < len) && ft_find_char(str[start], set) == 1)
		start++;
	while (len > start && ft_find_char(str[len - 1], set) == 1)
		len--;
	result = malloc((len - start + 1) * sizeof(char));
	if (result == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (start < len)
		result[i++] = str[start++];
	result[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char *str = ft_strtrim("   xxxtripouille", " x");
// 	printf("result = %s\n", str);
// 	printf("here = %d\n", strcmp(str, ""));
// 	printf("-----------------------------\n");
// 	char *str2 = ft_strtrim("   xxx   xxx", " x");
// 	printf("result = %s\n", str2);
// 	printf("here = %d\n", strcmp(str2, ""));
// 	printf("-----------------------------\n");
// 	char *str3 = ft_strtrim(NULL, "\n\t");
// 	printf("result = %s\n", str3);
// 	printf("here = %d\n", !str3);
// 	printf("----------------------------\n");
// 	printf("len of (NULL) = %d\n", (int)ft_strlen(NULL));
// 	return(0);
// }

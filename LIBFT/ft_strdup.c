/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:28:28 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/16 18:00:09 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*cpy;

	len = 0;
	while (s1[len] != '\0')
		len++;
	cpy = malloc((len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		cpy[len] = s1[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}

// int main()
// {
// 	char source[] = "GeeksForGeeks";

// 	// A copy of source is created dynamically
// 	// and pointer to copy is returned.
// 	char* target1 = strdup(source);
// 	char* target2 = ft_strdup(source);

// 	printf("target 1 = %s\n", target1);
// 	printf("target 2 = %s\n", target2);
// 	return 0;
// }
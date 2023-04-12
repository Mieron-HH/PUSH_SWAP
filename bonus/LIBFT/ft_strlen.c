/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:19:33 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/12 12:24:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// int main () {
// 	char str[50];
// 	int len;

// 	strcpy(str, "This is tutorialspoint.com");

// 	len = ft_strlen(str);
// 	printf("Length of |%s| is |%d|\n", str, len);

// 	return(0);
// }

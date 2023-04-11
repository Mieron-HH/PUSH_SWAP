/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:19:33 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/17 18:29:39 by mhaileye         ###   ########.fr       */
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
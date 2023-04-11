/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:26:24 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/16 16:15:28 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	<limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (count >= SIZE_MAX)
		return (NULL);
	array = malloc(count * size);
	if (!(array))
		return (NULL);
	ft_memset(array, 0, count * size);
	return ((void *)array);
}

// int main(void)
// {
// 	int* custom_array1 = ft_calloc(5, sizeof(int));
//     int* built_array1 = calloc(5, sizeof(int));
//     printf("custom array - 5: ");
//     for (size_t i = 0; i < 5; ++i) {
//         printf("%d ", custom_array1[i]);
//     }
//     putchar('\n');
//     printf("built array - 5: ");
//     for (size_t i = 0; i < 5; ++i) {
//         printf("%d ", built_array1[i]);
//     }
//     putchar('\n');
//     char* custom_array2 = ft_calloc(5, sizeof(char));
//     char* built_array2 = calloc(5, sizeof(char));
//     printf("custom array - 5: ");
//     for (size_t i = 0; i < 5; ++i) {
//         printf("%d ", custom_array2[i]);
//     }
//     putchar('\n');
//     printf("built array - 5: ");
//     for (size_t i = 0; i < 5; ++i) {
//         printf("%d ", built_array2[i]);
//     }
//     putchar('\n');
// }
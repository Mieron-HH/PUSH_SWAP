/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:41:41 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/17 17:15:06 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s);
	while (len >= 0)
	{
		if (s[len--] == (char)c)
			return ((char *)&s[len + 1]);
	}
	return (NULL);
}

// int main (void)
// {
//    const char str[] = "tripouille";
//    const char ch = 'e';
//    char *ret;
//    ret = ft_strrchr(str, ch);
//    int bool = ft_strrchr(str, 't' + 256) == str;
//    printf("String after |%c| is - |%s|\n", ch, ret);
//    printf("bool = %d\n", bool);
//    return(0);
// }
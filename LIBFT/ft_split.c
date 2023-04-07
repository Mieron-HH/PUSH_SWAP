/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:47:35 by mhaileye          #+#    #+#             */
/*   Updated: 2023/01/18 16:06:10 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

int	ft_is_delimiter(char c, char delimiter)
{
	return (c == delimiter);
}

int	ft_word_count(char const *s, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_is_delimiter(s[i], delimiter))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && !ft_is_delimiter(s[i], delimiter))
			i++;
	}
	return (count);
}

int	ft_word_len(char const *s, char delimiter)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && !ft_is_delimiter(s[i], delimiter))
		i++;
	return (i);
}

char	*ft_word(char const *s, char delimiter)
{
	char	*word;
	int		len;
	int		i;

	len = ft_word_len(s, delimiter);
	word = ft_calloc(len + 1, sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**strings;
	int		i;

	if (s == NULL)
		return (NULL);
	word_count = ft_word_count(s, c);
	strings = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (strings == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && ft_is_delimiter(*s, c))
			s++;
		if (*s != '\0')
			strings[i++] = ft_word(s, c);
		while (*s != '\0' && !ft_is_delimiter(*s, c))
			s++;
	}
	strings[i] = NULL;
	return (strings);
}

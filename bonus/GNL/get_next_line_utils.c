/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:15:21 by mhaileye          #+#    #+#             */
/*   Updated: 2023/02/07 14:58:04 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	str_len(char *s)
{
	int	len;

	if (s == NULL && free_up(&s))
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	new_line_found(char *s)
{
	if (!str_len(s))
		return (1);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int	free_up(char **str)
{
	free((void *)*str);
	*str = NULL;
	return (1);
}

char	*remove_line(char *buffer)
{
	char	*updated;
	int		size;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	size = str_len(buffer + i);
	if (size == 0 && free_up(&buffer))
		return (NULL);
	updated = (char *) malloc((size + 1) * sizeof(char));
	if (!updated && free_up(&buffer))
		return (NULL);
	j = 0;
	while (j < size)
	{
		updated[j] = buffer[j + i];
		j++;
	}
	free_up(&buffer);
	updated[j] = '\0';
	return (updated);
}

char	*copy_next_line(char *buffer)
{
	char	*next_line;
	int		size;
	int		i;

	size = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	next_line = (char *) malloc((size + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		next_line[i] = buffer[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

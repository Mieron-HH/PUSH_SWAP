/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:04:51 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 22:23:21 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*concat_buffer(char *s1, char *s2, int size_read, int static_size)
{
	char	*concat;
	int		i;
	int		j;

	concat = (char *) malloc((size_read + static_size + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	i = 0;
	while (i < static_size)
	{
		concat[i] = s1[i];
		i++;
	}
	free_up(&s1);
	j = 0;
	while (j < size_read)
	{
		concat[i + j] = s2[j];
		j++;
	}
	free_up(&s2);
	concat[i + j] = '\0';
	return (concat);
}

char	*read_from_file(int fd, char *data, int static_size)
{
	char		*concat;
	char		*buffer;
	ssize_t		size;

	buffer = (char *) malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free_up(&data);
		return (NULL);
	}
	size = read(fd, buffer, BUFFER_SIZE);
	if (size <= (ssize_t)0 && free_up(&buffer))
		return (data);
	buffer[size] = '\0';
	concat = concat_buffer(data, buffer, size, static_size);
	return (concat);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*next_line;
	int			static_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	data = read_from_file(fd, data, str_len(data));
	if (!str_len(data))
		return (NULL);
	static_size = str_len(data);
	while (!new_line_found(data))
	{
		data = read_from_file(fd, data, static_size);
		if (static_size == str_len(data))
			break ;
		static_size = str_len(data);
	}
	next_line = copy_next_line(data);
	data = remove_line(data);
	return (next_line);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*line;

// 	printf("buffer_size = %d\n", BUFFER_SIZE);

// 	fd = open("test1.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free((void *) line);
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free((void *)line);
// 	close(fd);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:03:12 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 22:22:55 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<limits.h>

char	*get_next_line(int fd);
char	*read_from_file(int fd, char *data, int static_size);
int		new_line_found(char *s);
char	*concat_buffer(char *concat, char *s1, int size_read, int static_size);
char	*remove_line(char *s);
int		str_len(char *s);
char	*copy_next_line(char *buffer);
int		free_up(char **str);

#endif

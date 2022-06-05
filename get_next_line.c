/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:05:03 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/06/06 01:01:10 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//remove this before submit
#include <stdio.h>
//To do \
//Done 1 - Main file -> open some file - call gnl to see what happens on the //function \
//Done 2 - Use GDB so I can focus what's in debbuing whatever I`m going to write \
//3 - Think on how function should behave \
//		1 -> it has to read the file limiting the buffer size \
//		if there aren't a new line on the oupt
//			it should read again and concat
//		if there's a new line it should read the pointer and concat till the newline and include
//		2 -> it has to read the file till reaches at a newline \
//		3 ->  \
//4 -


char	*get_buffer(int fd, char *ptr)
{
	size_t	len;
	int		i;

	len = ft_strlen(ptr);
	ptr = malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = read(fd, ptr, BUFFER_SIZE);  //i is the number of bytes read
	if(!ft_strchr(ptr, '\n'))
		get_buffer(fd, ptr);
		ft_strlcpy(ptr, get_buffer(fd, ptr), len + 9 );
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*accumulator;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder == NULL)
		remainder = ft_strdup("");
	accumulator = ft_strdup(remainder);
	line = get_buffer(fd, line);

	free(remainder);
	remainder = NULL;
	if (ft_strlen(accumulator == 0)
	{
		free(accumulator);
		return (NULL);
	}
	return (line);
}

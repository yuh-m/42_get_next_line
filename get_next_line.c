/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:05:03 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/05/21 23:51:03 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
char	*find_line(int fd, char *ptr)
{
	//char	*get_line;
	int		i;
	ptr = malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = read(fd, ptr, BUFFER_SIZE); //i is the number of bytes read
	//get_line =
	//printf("\n i = %d || \n", i );
	i = i+i;
	return (ptr);
}

char	*get_next_line(int fd)
{
	//static	int *iptr;
	//int			i; //receives the function read - it depends on BUFFER_SIZE ; fd and the content on that was allocatted within the buffer size
	static char	*leftover;
	char		*this_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftover == NULL)
		leftover = ft_strdup("");
	this_line = ft_strdup(leftover);
	this_line = find_line(fd, this_line);
	//printf("LEFTOVER = %s ||", leftover);

	return (this_line);
}

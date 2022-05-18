/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:05:03 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/05/19 01:30:09 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	int *iptr;
	int			i; //receives the function read - it depends on BUFFER_SIZE ; fd and the content on that was allocatted within the buffer size
	char		*ptr;

	int			buffer_size; //this variable needs to be declared when compiling all the program
	
}

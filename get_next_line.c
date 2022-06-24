/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:05:03 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/06/24 16:08:43 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//remove this before submit
#include <stdio.h>


char	*split_on_newline (const char *line_builder)
{
	int		i;
	int		first_line_lenght;
	char	*first_line;

	i = 0;
	first_line_lenght = 0;
	while (line_builder[first_line_lenght] != '\n')
		first_line_lenght++;
	first_line = (char *)malloc((first_line_lenght + 2) * sizeof(char));
	if (!first_line)
		return (NULL);
	while (i <= first_line_lenght)
	{
		first_line[i] = line_builder[i];
		i++;
	}
	first_line[i] = '\0';
	return (first_line);
}


char	*get_first_line	(char **line_builder,char **remainder_previous_buffer, \
		char *newline_char_location)
{
	char	*ptr_aux;

	ptr_aux = *remainder_previous_buffer;
	*remainder_previous_buffer = ft_strdup(newline_char_location + 1);
	free(ptr_aux);
	ptr_aux = split_on_newline(*line_builder);
	free(*line_builder);
	return (ptr_aux);
}

/*
char	split_line(char **line_builder, char **remainder_previous_buffer, \
char *newline_char_location)
{
	char *next_line;

	next_line = ft_strdup("");
	//next_line = *remainder_previous_buffer;
	//free(next_line); the order of when the memory is being free it doesn`t matter on this case, also next_line jsut need to be an empy memory
	//remainder_previous_buffer = ft_strdup(newline_char_location + 1); added to gnl
	//free(next_line);
	next_line = get_first_line(*line_builder)
	free(*line_builder);
	return(next_line);

} */

void	join_buffer_into_line(char **line_builder, char *buffer)
{
	char	*ptr_line_builder;

	ptr_line_builder = *line_builder;
	*line_builder = ft_strjoin(*line_builder, buffer);
	free(ptr_line_builder);
}

void	*manager_buffer(char **line_builder, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((bytes_read == BUFFER_SIZE) && \
	(ft_strchr(*line_builder, '\n') == NULL))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		join_buffer_into_line(line_builder, buffer);
	}
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder_previous_buffer;
	char		*line_builder;
	char		*newline_char_location;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder_previous_buffer == NULL)
		remainder_previous_buffer = ft_strdup("");
	line_builder = ft_strdup(remainder_previous_buffer);
	manager_buffer(&line_builder, fd);
	newline_char_location = ft_strchr(line_builder, '\n');
	if (newline_char_location != NULL)
		return get_first_line(&line_builder, &remainder_previous_buffer, \
		newline_char_location);
	free(remainder_previous_buffer);
	remainder_previous_buffer = NULL;
	if (ft_strlen(line_builder) == 0)
	{
		free(line_builder);
		return (NULL);
	}
	return (line_builder);
}
 //functin to free memory from variables

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:05:03 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/06/22 05:20:50 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//remove this before submit
#include <stdio.h>

char	*get_first_line(const char *line_builder)
{
	char	*first_line;
	int		line_builder_lenght;
	int		i;

	i = 0;
	line_builder_lenght = ft_strlen(line_builder);
	first_line = (char *)malloc((line_builder_lenght + 2) * sizeof(char));
	if (!first_line)
		return (NULL);
	ft_strlcpy(first_line, line_builder, line_builder_lenght);
	return (first_line);
}

/*
char	split_line(char **line_builder, char **remainder_previous_buffer, \
char *newline_char_location)
{
	char *next_line;

	next_line = ft_strdup("");
	//next_line = *remainder_previous_buffer;
	//free(next_line); the order of when the memory is being free it doesn`t matter on this case, also next_line jsut need to be an empy memory
	//*remainder_previous_buffer = ft_strdup(newline_char_location + 1); added to gnl
	//free(next_line);
	next_line = get_first_line(*line_builder)
	free(*line_builder);
	return(next_line);

} */

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
		*line_builder = ft_strjoin(*line_builder, buffer);
		//join_buffer_into_line(line_builder, buffer);
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
	{
		remainder_previous_buffer = ft_strdup(newline_char_location + 1);
		return get_first_line(line_builder);
	}
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

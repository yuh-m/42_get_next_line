/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:06:46 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/06/24 16:03:51 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//main file functions
char	*get_next_line(int fd);
char	*split_on_newline (const char *line_builder);
char	*get_first_line	(char **line_builder,char **remainder_previous_buffer, \
		char *newline_char_location);
void	*manager_buffer(char **line_builder, int fd);
void	join_buffer_into_line(char **line_builder, char *buffer);

//utils functions - max of 5 functions per file
size_t	ft_strlen(const char *string);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);

#endif

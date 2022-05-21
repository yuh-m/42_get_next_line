/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:06:46 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/05/21 22:45:18 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//main file functions
char	*get_next_line(int fd);

//utils functions - max of 5 functions per file
size_t	ft_strlen(const char *string);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
/* it's possible to incorporate the ft_strlcpy in ft_strdup,
 in case I need to reduce the number of functions */
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

#endif

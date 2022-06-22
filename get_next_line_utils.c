/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:08:55 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/06/07 00:02:31 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t		cnt;

	cnt = 0;
	while (string[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_strdup(const char *s)
{
	size_t	lenght;
	char	*result;

	lenght = ft_strlen(s) + 1;
	result = (char *)malloc(lenght);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s, lenght);
	return (result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	if (!dest || !src)
		return (0);
	len = ft_strlen(src);
	if (n <= 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && (i < (n - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while ((*s != '\0') || (char) c == '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	size;
	char	*result;
	size_t	cnt;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len + 1;
	result = malloc(sizeof(char) * (size));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	cnt = 0;
	while ((cnt + s1_len < (size - 1) && s2[cnt]))
	{
		result[cnt + s1_len + 1] = s2[cnt];
		cnt++;
	}
	result[cnt + s1_len + 1] = '\0';
	return (result);
}

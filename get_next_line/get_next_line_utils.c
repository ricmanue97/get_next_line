/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:23:51 by ricmanue          #+#    #+#             */
/*   Updated: 2024/06/25 10:59:55 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (c)
	{
		while (c[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	char *start;
	int size;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(size + 1);
	if (!str)
		return NULL;
	start = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	if (s1)
		free (s1);
	return start;
}

int ft_newline (char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_cleanread (char *actual_line, char *buffer_content)
{
	size_t i;
	int flag;

	i = 0;
	flag = ft_newline(actual_line);
	if (flag != -1)
	{
		actual_line [flag + 1] = '\0';
		flag = ft_newline (buffer_content);
		flag++;
		while (buffer_content[flag])
			buffer_content[i++] = buffer_content[flag++];
	}
	while (i < BUFFER_SIZE)
		buffer_content[i++] = '\0';
	return (actual_line);
}


/* char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	int size;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc (size + 1);
	if (!str)
		return NULL;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	if (s1)
		free (s1);
	return (str - size);
} */


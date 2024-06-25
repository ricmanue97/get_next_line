/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:23:48 by ricmanue          #+#    #+#             */
/*   Updated: 2024/06/25 10:35:12 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer_content [BUFFER_SIZE + 1];
	char		*actual_line;
	int			bytes;

	if ( fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	actual_line = NULL;
	while (ft_newline(actual_line)== -1)
	{
		if (buffer_content[0] == '\0')
		{
			bytes = read(fd, buffer_content, BUFFER_SIZE);
			if (bytes <= 0)
			{
				if (bytes == 0)
					return (actual_line);
				free(actual_line);
				return (NULL);
			}
			buffer_content[bytes] = '\0';
		}
		actual_line = ft_strjoin(actual_line, buffer_content);
		ft_cleanread(actual_line, buffer_content);
	}
	return (actual_line);
}

int	main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("file.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%d->%s", lines++, line);
		free(line);
	}
}

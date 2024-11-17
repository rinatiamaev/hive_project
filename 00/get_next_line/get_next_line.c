/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:11:31 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/16 23:33:26 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *buffer_storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer_storage[i])
		return (NULL);
	while (buffer_storage[i] && buffer_storage[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer_storage[i] && buffer_storage[i] != '\n')
	{
		line[i] = buffer_storage[i];
		i++;
	}
	if (buffer_storage[i] == '\n')
	{
		line[i] = buffer_storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_buffer_storage(char *buffer_storage)
{
	int		i;
	int		j;
	char	*new_buffer_storage;

	i = 0;
	while (buffer_storage[i] && buffer_storage[i] != '\n')
		i++;
	if (!buffer_storage[i])
	{
		free(buffer_storage);
		return (NULL);
	}
	new_buffer_storage = (char *)malloc(sizeof(char)
			* (ft_strlen(buffer_storage) - i + 1));
	if (!new_buffer_storage)
		return (NULL);
	i++;
	j = 0;
	while (buffer_storage[i])
		new_buffer_storage[j++] = buffer_storage[i++];
	new_buffer_storage[j] = '\0';
	free(buffer_storage);
	return (new_buffer_storage);
}

static char	*read_and_store(int fd, char *buffer_storage)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(buffer_storage, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		buffer_storage = ft_strjoin(buffer_storage, buffer);
	}
	free(buffer);
	return (buffer_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_storage = read_and_store(fd, buffer_storage);
	if (!buffer_storage)
		return (NULL);
	line = extract_line(buffer_storage);
	buffer_storage = update_buffer_storage(buffer_storage);
	return (line);
}

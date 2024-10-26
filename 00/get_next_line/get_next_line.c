#include "get_next_line.h"

static int	read_buffer(int fd, char **cache, char *buffer)
{
	int		bytes;
	char	*temp;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (bytes);
	buffer[bytes] = '\0';
	temp = ft_strjoin(*cache, buffer);
	free(*cache);
	*cache = temp;
	if (*cache)
		return (bytes);
	else
		return (-1);
}

static char	*extract_line(char *cache)
{
	size_t	len;
	char	*line;

	len = 0;
	while (cache[len] && cache[len] != '\n')
		len++;
	if (cache[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strncpy(line, cache, len);
	line[len] = '\0';
	return (line);
}

static void	update_cache(char **cache)
{
	char	*new_cache;
	size_t	len;

	len = 0;
	while ((*cache)[len] && (*cache)[len] != '\n')
		len++;
	if (!(*cache)[len++])
	{
		free(*cache);
		*cache = NULL;
		return ;
	}
	new_cache = ft_strdup(*cache + len);
	free(*cache);
	*cache = new_cache;
}

static char	*prepare_and_finalize(int fd, char **cache, int bytes, int mode)
{
	char	*buffer;
	char	*line;

	if (mode == 0)
	{
		if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		if (!*cache)
			*cache = ft_strdup("");
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		return (buffer);
	}
	else
	{
		if (bytes < 0 || !*cache || **cache == '\0')
		{
			free(*cache);
			*cache = NULL;
			return (NULL);
		}
		line = extract_line(*cache);
		update_cache(cache);
		return (line);
	}
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*buffer;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = prepare_and_finalize(fd, &cache, 0, 0);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(cache, '\n') && bytes > 0)
	{
		bytes = read_buffer(fd, &cache, buffer);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		else if (bytes == 0)
			break ;
	}
	free(buffer);
	line = prepare_and_finalize(fd, &cache, bytes, 1);
	return (line);
}

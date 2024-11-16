/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:21:00 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/14 19:08:19 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int  read_buffer(int fd, char **buffer_storage, char *buffer)
{
    char    *tmp;
    int     bytes;

    ft_memset(buffer, 0, BUFFER_SIZE + 1);
    bytes = read(fd, buffer, BUFFER_SIZE);
    if (bytes < 0)
    {
        free(*buffer_storage);
        *buffer_storage = NULL;
        return (-1);
    }
    if (bytes == 0)
        return (bytes);
    tmp = ft_strjoin(*buffer_storage, buffer);
    free(*buffer_storage);
    *buffer_storage = tmp;
    return (bytes);
}

static void remove_result(char **buffer_storage)
{
    char    *nl;
    char    *tmp;

    nl = ft_strchr(*buffer_storage, '\n');
    if (!nl)
    {
        free(*buffer_storage);
        *buffer_storage = NULL;
        return ;
    }
    tmp = ft_strdup(nl + 1);
    free(*buffer_storage);
    *buffer_storage = tmp;
    if (**buffer_storage == '\0')
    {
        free(*buffer_storage);
        *buffer_storage = NULL;
    }
}

static void get_result(char **buffer_storage, char **result)
{
    char    *nl;
    size_t  len;
    size_t  i;

    nl = ft_strchr(*buffer_storage, '\n');
    if (nl)
        len = nl - *buffer_storage + 1;
    else
        len = ft_strlen(*buffer_storage);
    *result = (char *)malloc((len + 1) * sizeof(char));
    if (!*result)
        return ;
    i = 0;
    while (i < len)
    {
        (*result)[i] = (*buffer_storage)[i];
        i++;
    }
    (*result)[i] = '\0';
}

char    *get_next_line(int fd)
{
    static char *buffer_storage = NULL;
    char        *result;
    char        *buffer;
    int         bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(buffer_storage, '\n') && bytes > 0)
        bytes = read_buffer(fd, &buffer_storage, buffer);
    free(buffer);
    if (bytes == -1 || !buffer_storage || ft_strlen(buffer_storage) == 0)
    {
        free(buffer_storage);
        buffer_storage = NULL;
        return (NULL);
    }
    get_result(&buffer_storage, &result);
    remove_result(&buffer_storage);
    return (result);
}
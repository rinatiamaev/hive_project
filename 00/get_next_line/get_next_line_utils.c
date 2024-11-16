/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:27:49 by riamaev           #+#    #+#             */
/*   Updated: 2024/11/14 12:41:56 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  len = 0;
	
    while (str[len])
        len++;
    return (len);
}

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *p = (unsigned char *)s;
    size_t          i = 0;

    while (i < n)
    {
        p[i] = (unsigned char)c;
        i++;
    }
    return (s);
}

char    *ft_strdup(const char *s1)
{
    char    *copy;
    size_t  len = ft_strlen(s1);
    size_t  i;

    copy = (char *)malloc((len + 1) * sizeof(char));
    if (!copy)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        copy[i] = s1[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    size_t  len1 = ft_strlen(s1);
    size_t  len2 = ft_strlen(s2);
    size_t  i, j;

    result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (!result)
        return (NULL);
    i = -1;
    while (++i < len1)
        result[i] = s1[i];
    j = -1;
    while (++j < len2)
        result[i + j] = s2[j];
    result[i + j] = '\0';
    return (result);
}

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (*s == (char)c)
        return ((char *)s);
    return (NULL);
}
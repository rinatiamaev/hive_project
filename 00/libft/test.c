/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:10:33 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 09:25:59 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && big[i + j] == little[j] && (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// test_ft_strnstr.c


void test_ft_strnstr()
{
    char *big = "Hello, world!";
    char *little;
    size_t len;
    char *result;

    // Test 1: little is an empty string
    little = "";
    len = 5;
    result = ft_strnstr(big, little, len);
    printf("Test 1: %s\n", result == big ? "Passed" : "Failed");

    // Test 2: little found at the beginning of big
    little = "Hello";
    len = 5;
    result = ft_strnstr(big, little, len);
    printf("Test 2: %s\n", result == big ? "Passed" : "Failed");

    // Test 3: little found in the middle of big
    little = "world";
    len = 12;
    result = ft_strnstr(big, little, len);
    printf("Test 3: %s\n", result == &big[7] ? "Passed" : "Failed");

    // Test 4: little not found in big
    little = "42";
    len = 12;
    result = ft_strnstr(big, little, len);
    printf("Test 4: %s\n", result == NULL ? "Passed" : "Failed");

    // Test 5: len smaller than the length of little
    little = "world";
    len = 3;
    result = ft_strnstr(big, little, len);
    printf("Test 5: %s\n", result == NULL ? "Passed" : "Failed");
}

int main()
{
    test_ft_strnstr();
    return 0;
}

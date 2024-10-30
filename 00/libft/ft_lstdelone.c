/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:22:58 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 12:23:00 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

static void	ft_delfoo(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *new = ft_lstnew((char *)malloc(sizeof(char) * 25));
	if (!new)
		return (1);
	snprintf(new->content, 25, "Hello, HIVE!!!!!");
	printf("%s\n", (char *)new->content);
	ft_lstdelone(new, ft_delfoo);
	printf("node was deleted\n");
	return (0);
}*/

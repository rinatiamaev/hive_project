/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:12 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 12:23:14 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

static void	ft_delfoo(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *new1 = ft_lstnew((char *)malloc(sizeof(char) * 11));
	t_list *new2 = ft_lstnew((char *)malloc(sizeof(char) * 11));
	t_list *new3 = ft_lstnew((char *)malloc(sizeof(char) * 11));
	if (!new1 || !new2 || !new3)
		return (1);
	snprintf(new1->content, 11, "its node 1");
	snprintf(new2->content, 11, "its node 2");
	snprintf(new3->content, 11, "its node 3");
	new1->next = new2;
	new2->next = new3;
	t_list *current = new1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&new1, ft_delfoo);
	if (new1 == NULL)
		printf("list empty\n");
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:22:27 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 12:22:28 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*head = NULL;
	t_list *node1 = ft_lstnew("node 1");
	t_list *node2 = ft_lstnew("node 2");
	t_list *node3 = ft_lstnew("node 3");
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	t_list *last = ft_lstlast(head);
	if (last)
		printf("last node is: %s\n", (char *)last->content);
	return (0);
}*/

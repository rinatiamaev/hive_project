/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:26 by riamaev           #+#    #+#             */
/*   Updated: 2024/10/29 12:23:28 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void	ft_print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*new1 = ft_lstnew("node1");
	t_list  *new2 = ft_lstnew("node2");
	t_list  *new3 = ft_lstnew("node3");
	if (!new1 || !new2 || !new3)
		return (1);
	new1->next = new2;
	new2->next = new3;
	ft_lstiter(new1, ft_print_content);
	return (0);
}*/

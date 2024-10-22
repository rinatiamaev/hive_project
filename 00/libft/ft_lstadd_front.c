#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *head = NULL;
	t_list *new;
	char *content = "some content inside node";
	new = ft_lstnew(content);
	ft_lstadd_front(&head, new);
	printf("%s\n", (char *)head->content);
	return (0);
}*/

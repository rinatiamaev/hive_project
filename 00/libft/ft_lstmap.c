#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	new_node = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>

static void	*ft_rotone(void *content)
{
	int i = 0;
	char *str = (char *)content;
	char *new_str = (char *)malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i] + 1;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static void	ft_delfoo(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *new1 = ft_lstnew(ft_strdup("1"));
	t_list *new2 = ft_lstnew(ft_strdup("2"));
	t_list *new3 = ft_lstnew(ft_strdup("3"));
	if (!new1 || !new2 || !new3)
		return (1);
	new1->next = new2;
	new2->next = new3;
	t_list	*new_list = ft_lstmap(new1, ft_rotone, ft_delfoo);
	t_list	*current = new_list;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&new1, ft_delfoo);
	ft_lstclear(&new_list, ft_delfoo);
	return (0);
}*/

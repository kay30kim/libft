/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:33:31 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/25 16:41:01 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst && del)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
	}
}
/*
void	ft_lstprint(t_list *list)
{
	while (list)
	{
		printf("%s -> ", (char *)list->content);
		list = list->next;
	}
	printf("NULL\n");
}

void	print_node(void *content)
{
	printf("%s -> ", (char *)content);
}

void	delete_string_node(void *content)
{
	content = 0;
}

int	main(void)
{
	t_list	*list1;

	list1 = ft_lstnew("Item 1");
	list1->next = ft_lstnew("Item 2");
	list1->next->next = ft_lstnew("Item 3");
	printf("Original List 1: ");
	ft_lstprint(list1);

	printf("Clearing List 1: ");
	ft_lstclear(&list1, delete_string_node);
	printf("List 1 cleared\n");

	if (list1 == NULL)
	{
		printf("List 1 is now NULL\n");
	}
	return (0);
}*/
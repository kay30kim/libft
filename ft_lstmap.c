/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:35:19 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/25 14:53:10 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ptr;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (0);
	ptr = head;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ptr->next = tmp;
		ptr = tmp;
		lst = lst->next;
	}
	return (head);
}

int main() {
    // Test case 1: Non-null input
    t_list *list1 = ft_lstnew("Hello");
    list1->next = ft_lstnew("World");
    printf("Original List 1: ");
    print_list(list1);

    t_list *mapped_list1 = ft_lstmap(list1, create_string_node, delete_string_node);
    printf("Mapped List 1: ");
    print_list(mapped_list1);
    printf("\n");

    // Test case 2: Null input
    t_list *list2 = NULL;
    printf("Original List 2: NULL\n");

    t_list *mapped_list2 = ft_lstmap(list2, create_string_node, delete_string_node);
    printf("Mapped List 2: ");
    print_list(mapped_list2);
    printf("\n");

    // Test case 3: Mix of non-null and null input
    t_list *list3 = ft_lstnew("One");
    list3->next = NULL;
    printf("Original List 3: One -> NULL\n");

    t_list *mapped_list3 = ft_lstmap(list3, create_string_node, delete_string_node);
    printf("Mapped List 3: ");
    print_list(mapped_list3);
    printf("\n");

    // Remember to free the memory allocated for the mapped lists
    ft_lstclear(&mapped_list1, delete_string_node);
    ft_lstclear(&mapped_list2, delete_string_node);
    ft_lstclear(&mapped_list3, delete_string_node);

    return 0;
}
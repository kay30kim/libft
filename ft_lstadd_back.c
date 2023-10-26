/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:32:57 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:16:14 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new || !lst)
		return ;
	ptr = *lst;
	while (ptr && ptr->next)
	{
		ptr = ptr->next;
	}
	if (ptr)
		ptr->next = new;
	else
		*lst = new;
}
/*
int	main(void)
{
	t_list	*my_list;
	t_list	**list_ptr;
	t_list	*current;

	my_list = NULL;
	list_ptr = &my_list;
	printf("%p\n",*list_ptr);
	ft_lstadd_back(list_ptr, ft_lstnew("lore"));
	printf("%p\n",*list_ptr);
	ft_lstadd_back(list_ptr, ft_lstnew("lore2"));
	printf("%p\n",*list_ptr);
	ft_lstadd_back(list_ptr, ft_lstnew("lore3"));
	printf("%p\n",*list_ptr);
	// Print the list
	current = my_list;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/

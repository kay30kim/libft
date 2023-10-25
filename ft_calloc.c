/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:26:10 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/25 14:48:24 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// size * count still doesn't make sense
void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;

	if (size == 0 || count == 0)
		return (NULL);
	tmp = (char *)malloc(size * count);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, size * count);
	return ((void *)tmp);
}
/*
int main()
{
	int size = 8539;

	void * d2 = calloc(size, sizeof(int));
	void * d1 = ft_calloc(size, sizeof(int));

	printf("%p\n",d1);
	printf("%p\n",d2);
	return (0);
}
*/

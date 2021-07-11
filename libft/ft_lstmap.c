/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:32:58 by tvader            #+#    #+#             */
/*   Updated: 2021/04/23 18:26:43 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*nextelem;

	if (!f || !*f)
		return (NULL);
	elem = NULL;
	while (lst)
	{
		nextelem = ft_lstnew((*f)(lst->content));
		if (!nextelem)
		{
			while (elem)
			{
				nextelem = elem->next;
				ft_lstdelone(elem, del);
				elem = nextelem;
			}
			lst = NULL;
			return (lst);
		}
		ft_lstadd_back(&elem, nextelem);
		lst = lst->next;
	}
	return (elem);
}

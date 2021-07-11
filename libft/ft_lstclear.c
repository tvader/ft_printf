/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:36:32 by tvader            #+#    #+#             */
/*   Updated: 2021/04/21 19:09:14 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	t_list	*nelem;

	if (!lst || !*lst || !del)
		return ;
	while (*lst && lst)
	{
		nelem = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = nelem;
	}
}

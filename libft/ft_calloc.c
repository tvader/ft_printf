/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:07:21 by tvader            #+#    #+#             */
/*   Updated: 2021/04/22 12:54:16 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*res;
	unsigned int	cnt;

	cnt = 0;
	res = (void *)malloc(count * size);
	if (res)
	{
		while (cnt < count * size)
		{		
			*(char *)(res + cnt) = 0;
			cnt++;
		}
		return (res);
	}
	else
		return (NULL);
}

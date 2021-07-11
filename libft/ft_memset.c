/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:34:56 by tvader            #+#    #+#             */
/*   Updated: 2021/04/21 19:09:57 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*beg;

	beg = b;
	while (len > 0)
	{
		*(char *)b = (unsigned char)c;
		b++;
		len--;
	}
	return (beg);
}

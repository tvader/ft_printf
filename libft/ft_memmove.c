/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:40:25 by tvader            #+#    #+#             */
/*   Updated: 2021/04/23 17:47:10 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*beg;

	if (!dst && !src)
		return (NULL);
	beg = dst;
	if (dst < src)
	{
		while (len > 0)
		{
			*(char *)dst = *(char *)src;
			dst++;
			src++;
			len--;
		}
	}
	else
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(char *)dst-- = *(char *)src--;
	}
	return (beg);
}

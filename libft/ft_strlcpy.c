/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:12:38 by tvader            #+#    #+#             */
/*   Updated: 2021/04/24 14:59:47 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	slen;

	cnt = 0;
	slen = 0;
	if (!src)
		return (0);
	while (*(src + slen))
		slen++;
	if (!dst || dstsize == 0)
		return (slen);
	while (cnt + 1 < dstsize && *(src + cnt))
	{
		*(dst + cnt) = *(src + cnt);
		cnt++;
	}
	*(dst + cnt) = 0;
	return (slen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:39:39 by tvader            #+#    #+#             */
/*   Updated: 2021/04/24 16:50:04 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	dlen;
	size_t	slen;

	cnt = 0;
	dlen = ft_strlen((char *)dst);
	slen = ft_strlen((char *)src);
	if (dlen > dstsize)
		return (dstsize + slen);
	while (src[cnt])
	{
		if (cnt + dlen + 1 >= dstsize)
			break ;
		dst[cnt + dlen] = src[cnt];
		cnt++;
	}
	dst[cnt + dlen] = 0;
	while (cnt + dlen < dstsize && cnt + 1 == slen)
	{
		dst[cnt + dlen] = 0;
		cnt++;
	}
	if (dstsize > dlen + slen)
		return (slen + dlen);
	return (dlen + slen + (cnt + slen < dstsize) * (cnt));
}

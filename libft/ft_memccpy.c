/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:54:30 by tvader            #+#    #+#             */
/*   Updated: 2021/04/23 14:00:38 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		*(unsigned char *)(dst + cnt) = *(unsigned char *)(src + cnt);
		if ((*(unsigned char *)(src + cnt)) == (unsigned char)c)
			break ;
		cnt++;
	}
	if (cnt == n && (*(unsigned char *)(src + cnt)) != (unsigned char)c)
		return (NULL);
	else
		return (dst + cnt + 1);
}

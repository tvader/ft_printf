/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:21:53 by tvader            #+#    #+#             */
/*   Updated: 2021/04/27 02:38:26 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (*(unsigned char *)(s + cnt) == (unsigned char)c)
			return ((void *)(s + cnt));
		cnt++;
	}
	return (NULL);
}

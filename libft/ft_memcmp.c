/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:29:29 by tvader            #+#    #+#             */
/*   Updated: 2021/04/22 14:58:53 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n && *(char *)(s1 + cnt) == *(char *)(s2 + cnt))
		cnt++;
	if (cnt == n)
		cnt -= 1;
	return ((int)(*(unsigned char *)(s1 + cnt) - *(unsigned char *)(s2 + cnt)));
}

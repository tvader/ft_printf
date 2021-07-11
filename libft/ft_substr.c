/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:01:16 by tvader            #+#    #+#             */
/*   Updated: 2021/04/25 12:57:54 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	cnt;
	char			*res;

	if (!s)
		return (NULL);
	cnt = start;
	if (start + 1 > ft_strlen((char *)s))
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (cnt < len + start)
	{
		*(res + cnt - start) = *(s + cnt);
		if (!*(s + cnt))
			break ;
		cnt++;
	}
	*(res + len) = '\0';
	return (res);
}

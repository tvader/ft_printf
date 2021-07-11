/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:34:54 by tvader            #+#    #+#             */
/*   Updated: 2021/04/22 14:07:18 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	cnt;
	char	*res;

	len = 0;
	cnt = 0;
	while (*(s1 + len))
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (res)
	{
		while (cnt < len)
		{
			*(res + cnt) = *(s1 + cnt);
			cnt++;
		}
		res[cnt] = 0;
		return (res);
	}
	else
		return (NULL);
}

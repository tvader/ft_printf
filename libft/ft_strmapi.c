/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:45:04 by tvader            #+#    #+#             */
/*   Updated: 2021/04/24 17:21:12 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	len;
	unsigned int	cnt;

	cnt = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (*(s + len))
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res || !f)
		return (NULL);
	while (*(s + cnt))
	{
		*(res + cnt) = f(cnt, *(s + cnt));
		cnt++;
	}
	*(res + len) = 0;
	return (res);
}

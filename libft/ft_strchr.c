/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:36:55 by tvader            #+#    #+#             */
/*   Updated: 2021/04/22 15:06:54 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cnt;

	cnt = 0;
	while (*(s + cnt) != (char)c && *(s + cnt))
		cnt++;
	if (*(s + cnt) || c == 0)
		return ((char *)(s + cnt));
	else
		return (NULL);
}

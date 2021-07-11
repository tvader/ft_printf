/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:46:45 by tvader            #+#    #+#             */
/*   Updated: 2021/04/21 19:10:56 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cnt;

	cnt = 0;
	while (*(s + cnt))
		cnt++;
	if (c == 0)
		return ((char *)(s + cnt));
	while (*(s + cnt) != (char)c && cnt > 0)
		cnt--;
	if (*(s + cnt) == (char)c)
		return ((char *)(s + cnt));
	else
		return (NULL);
}

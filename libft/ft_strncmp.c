/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:25:08 by tvader            #+#    #+#             */
/*   Updated: 2021/04/21 19:10:47 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n > 1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (*((unsigned char *)s1) > *((unsigned char *)s2))
		return (1);
	if (*((unsigned char *)s1) < *((unsigned char *)s2))
		return (-1);
	return (0);
}

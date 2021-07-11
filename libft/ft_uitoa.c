/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:00:21 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 18:24:29 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revstr(char *s)
{
	size_t		len;
	size_t		cnt;
	char		buf;

	cnt = 0;
	len = 0;
	while (*(s + len))
		len++;
	while (cnt < len / 2)
	{
		buf = *(s + cnt);
		*(s + cnt) = *(s + len - cnt - 1);
		*(s + len - cnt - 1) = buf;
		cnt++;
	}
	return (s);
}

static int	ft_ilen(unsigned int n)
{
	int				len;
	unsigned int	div;

	len = 1;
	div = 1;
	if (n == 0)
		return (1);
	while (n / div != 0 && len < 11)
	{
		div *= 10;
		len++;
	}
	return (len - 1);
}

char	*ft_uitoa(unsigned int n)
{
	char		*res;
	int			cnt;

	cnt = 0;
	n = (unsigned int) n;
	res = malloc(sizeof(char) *(ft_ilen(n) + 1));
	if (!res)
		return (NULL);
	while (n != 0 || cnt == 0)
	{
		res[cnt++] = (char)(n % 10 + 48);
		n /= 10;
	}
	res[cnt] = 0;
	return (ft_revstr(res));
}

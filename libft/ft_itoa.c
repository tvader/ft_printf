/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:00:21 by tvader            #+#    #+#             */
/*   Updated: 2021/06/29 16:52:16 by tvader           ###   ########.fr       */
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

static int	ft_ilen(int n)
{
	int			len;
	int			div;

	len = 1;
	div = 1;
	if (n == 0)
		return (1);
	n = n + -2 * (n < 0);
	while (n / div != 0 && len < 11)
	{
		div *= 10;
		len++;
	}
	return (len - 1);
}

char	*ft_itoa(int n, int is_sign)
{
	char		*res;
	int			cnt;
	int			sign;

	if (n == -2147483648 && is_sign)
		return (ft_strdup("-2147483648"));
	else if (n == -2147483648 && !is_sign)
		return (ft_strdup("2147483648"));
	cnt = 0;
	sign = 1 - 2 *(n < 0);
	res = malloc(sizeof(char) *((ft_ilen(n) + ((n < 0) && is_sign) + 1)));
	if (!res)
		return (NULL);
	n *= sign;
	while (n != 0 || cnt == 0)
	{
		res[cnt++] = (char)(n % 10 + 48);
		n /= 10;
	}
	if (sign < 0 && is_sign)
		res[cnt++] = '-';
	res[cnt] = 0;
	return (ft_revstr(res));
}

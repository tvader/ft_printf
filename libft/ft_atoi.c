/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:56:21 by tvader            #+#    #+#             */
/*   Updated: 2021/06/29 16:49:34 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen1(char *s)
{
	int	len;

	len = 0;
	while (ft_isdigit(*(s + len)))
		len++;
	return (len);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	base;

	sign = 1;
	base = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	sign -= 2 * (*str == '-');
	str += (*str == '+' || *str == '-');
	if (ft_nlen1(str) > 10)
		return (-1);
	if (ft_nlen1(str) == 10 && sign < 0)
		if (ft_strncmp(str, "2147483648", 10) > 0)
			return (-1);
	if (ft_nlen1(str) == 10 && sign > 0)
		if (ft_strncmp(str, "2147483647", 10) > 0)
			return (-1);
	while (*str >= '0' && *str <= '9')
	{
		base = base * 10 + (*str - '0');
		str++;
	}
	return (base * sign);
}

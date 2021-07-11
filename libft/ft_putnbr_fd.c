/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:24:07 by tvader            #+#    #+#             */
/*   Updated: 2021/04/24 15:37:34 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_crutch(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	dig;

	len = 1;
	if (fd < 0 || ft_crutch(n, fd))
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n / (len * 10) != 0 && len < 1000000000)
		len *= 10;
	while (len > 0)
	{
		dig = (char)(n / len + 48);
		write(fd, &dig, 1);
		n %= len;
		len /= 10;
	}
}

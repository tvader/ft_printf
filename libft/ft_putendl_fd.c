/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:21:41 by tvader            #+#    #+#             */
/*   Updated: 2021/04/24 17:19:59 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	if (fd >= 0)
	{
		while (*(s + len))
			len++;
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}

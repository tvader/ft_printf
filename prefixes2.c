/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefixes2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:56:46 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 22:04:07 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_prefix_c(t_specs *sarg, size_t prelen)
{
	size_t	printed;

	printed = 0;
	prelen -= (sarg->plus || sarg->space);
	if (sarg->width)
	{
		while (printed < prelen)
		{
			if (sarg->zero)
				printed += write(1, "0", 1);
			else
				printed += write(1, " ", 1);
		}
	}
	return (printed);
}

short	def_0xlen(unsigned int arg)
{
	short	bits;
	short	nlen;

	nlen = 0;
	bits = 8 * sizeof(arg) - 4;
	while (bits >= 0 && arg)
	{
		if (arg >> bits)
			nlen++;
		bits -= 4;
	}
	return (nlen += (nlen == 0));
}

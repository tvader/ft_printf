/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefixes1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:54:39 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 22:04:06 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_prefix_x(t_specs *sarg, unsigned int arg)
{
	size_t	printed;
	size_t	nlen;
	size_t	zero_len;
	size_t	space_len;

	printed = 0;
	nlen = def_0xlen(arg);
	zero_len = (sarg->prec - nlen) * ((size_t) sarg->prec > nlen) * (sarg->dot);
	zero_len += ((sarg->zero && (size_t) sarg->width > nlen + zero_len) * \
				(sarg->width - nlen - zero_len - (sarg->space || sarg->plus)));
	space_len = ((size_t) sarg->width - nlen - zero_len) * \
	(((size_t) sarg->width > nlen + zero_len) && !(sarg->minus)) + sarg->space;
	space_len += (arg == 0 && sarg->prec == 0 && sarg->width && sarg->dot);
	while (printed < space_len)
		printed += write(1, " ", 1);
	if (sarg->plus)
		printed += write(1, "+", 1);
	while (printed - space_len < zero_len)
		printed += write(1, "0", 1);
	return (printed);
}

size_t	print_prefix_di(t_specs *sarg, char *arg, int neg)
{
	size_t	printed;
	size_t	nlen;
	size_t	zero_len;
	size_t	space_len;

	printed = 0;
	nlen = ft_strlen(arg);
	zero_len = (sarg->prec - nlen) * ((size_t) sarg->prec > nlen) * (sarg->dot);
	zero_len += ((sarg->zero && (size_t) sarg->width > nlen + zero_len) * \
				(sarg->width - nlen - zero_len - (sarg->space || sarg->plus)));
	space_len = ((size_t) sarg->width - nlen - zero_len) * \
	(((size_t) sarg->width > nlen + zero_len) && !(sarg->minus)) + sarg->space;
	space_len += ((*arg) == '0' && sarg->prec == 0 && sarg->width && sarg->dot);
	space_len -= neg && space_len;
	zero_len -= neg && (zero_len && !(sarg->dot));
	while (printed < space_len)
		printed += write(1, " ", 1);
	if (sarg->plus && !neg)
		printed += write(1, "+", 1);
	if (neg)
		printed += write(1, "-", 1);
	while (printed - space_len - neg - (!neg && sarg->plus) < zero_len)
		printed += write(1, "0", 1);
	return (printed);
}

size_t	print_prefix_u(t_specs *sarg, char *arg)
{
	size_t	printed;
	size_t	nlen;
	size_t	zero_len;
	size_t	space_len;

	printed = 0;
	nlen = ft_strlen(arg);
	zero_len = (sarg->prec - nlen) * ((size_t) sarg->prec > nlen) * (sarg->dot);
	zero_len += ((sarg->zero && (size_t) sarg->width > nlen + zero_len) * \
				(sarg->width - nlen - zero_len - (sarg->space || sarg->plus)));
	space_len = ((size_t) sarg->width - nlen - zero_len) * \
	(((size_t) sarg->width > nlen + zero_len) && !(sarg->minus)) + sarg->space;
	space_len += ((*arg) == '0' && sarg->prec == 0 && sarg->width && sarg->dot);
	while (printed < space_len)
		printed += write(1, " ", 1);
	if (sarg->plus)
		printed += write(1, "+", 1);
	while (printed - space_len - sarg->plus < zero_len)
		printed += write(1, "0", 1);
	return (printed);
}

size_t	print_prefix_p(t_specs *sarg, unsigned long long arg)
{
	size_t	printed;
	size_t	len;
	short	bits;

	printed = 0;
	len = 0;
	bits = 4 * sizeof(unsigned long) - 4;
	while (bits >= 0 && arg)
	{
		if (arg >> bits)
			len++;
		bits -= 4;
	}
	len += (len == 0);
	if (!(sarg->minus))
		while (printed + len + 2 < (size_t)(sarg->width))
			printed += write(1, " ", 1);
	printed += write(1, "0x", 2);
	return (printed);
}

size_t	print_prefix_s(t_specs *sarg, char *arg)
{
	size_t	printed;
	size_t	len;

	printed = 0;
	if (sarg->dot && (size_t)(sarg->prec) < ft_strlen(arg))
		len = sarg->prec;
	else
		len = ft_strlen(arg);
	while (printed + len < (size_t)(sarg->width))
		printed += write(1, " ", 1);
	return (printed);
}

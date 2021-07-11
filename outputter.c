/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:07:04 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 22:04:02 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	x_out(va_list args, t_specs *sarg, char *lsyms, char *usyms)
{
	unsigned long	arg;
	short			bits;
	short			res;
	char			*syms;

	if (sarg->ext == 'x')
		syms = lsyms;
	else
		syms = usyms;
	res = 0;
	arg = va_arg(args, unsigned int);
	bits = (4 * sizeof(arg) - 4);
	if (!(sarg->minus) || sarg->dot)
		res += print_prefix_x(sarg, arg);
	if (!arg && !(sarg->dot && !(sarg->prec)))
		res += write(1, "0", 1);
	while (bits >= 0 && arg)
	{
		if (arg >> bits)
			res += write(1, syms + ((arg >> bits) & 15), 1);
		bits -= 4;
	}
	return (res);
}

size_t	percent_out(t_specs *sarg)
{
	size_t	printed;

	printed = 0;
	if (sarg->width && !(sarg->minus))
	{
		while (printed + 1 < (size_t) sarg->width)
		{
			if (sarg->zero)
				printed += write(1, "0", 1);
			else
				printed += write(1, " ", 1);
		}
	}
	printed += write(1, "%", 1);
	return (printed);
}

size_t	print_suffix(t_specs *sarg, size_t strlen)
{
	size_t	printed;

	if (!sarg->minus)
		return (0);
	printed = strlen;
	while (printed < (size_t)sarg->width)
	{
		write(1, " ", 1);
		printed++;
	}
	return (printed - strlen);
}

size_t	outputter(va_list args, t_specs *sarg)
{
	size_t	printed;

	if (sarg->ext == 's')
		printed = s_out(args, sarg);
	if (sarg->ext == 'c')
		printed = c_out(args, sarg);
	if (sarg->ext == 'd' || sarg->ext == 'i')
		printed = d_out(args, sarg);
	if (sarg->ext == 'u')
		printed = u_out(args, sarg);
	if (sarg->ext == 'x' || sarg->ext == 'X')
		printed = x_out(args, sarg, "0123456789abcdef", "0123456789ABCDEF");
	if (sarg->ext == 'p')
		printed = p_out(args, sarg, "0123456789abcdef");
	if (sarg->ext == '%')
		printed = percent_out(sarg);
	printed += print_suffix(sarg, printed);
	return (printed);
}

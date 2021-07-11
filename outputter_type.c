/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputter_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:58:40 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 22:04:01 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	s_out(va_list args, t_specs *sarg)
{
	char	*arg;
	size_t	res;

	res = 0;
	arg = va_arg(args, char *);
	if (!arg)
		arg = "(null)";
	if (!(sarg->minus) && (sarg->width || sarg->dot))
		res += print_prefix_s(sarg, arg);
	if ((size_t)sarg->prec > ft_strlen(arg) || !(sarg->dot))
		res += write(1, arg, ft_strlen(arg));
	else
		res += write(1, arg, sarg->prec);
	return (res);
}

size_t	c_out(va_list args, t_specs *sarg)
{
	char	arg;
	int		res;

	(void)sarg;
	arg = (char)va_arg(args, int);
	res = 0;
	if (!(sarg->minus))
		res += print_prefix_c(sarg, sarg->width - 1);
	res += write(1, &arg, 1);
	return (res);
}

size_t	d_out(va_list args, t_specs *sarg)
{
	int		arg;
	char	*strarg;
	int		printed;

	arg = va_arg(args, int);
	strarg = ft_itoa(arg, 0);
	printed = 0;
	printed += print_prefix_di(sarg, strarg, arg < 0);
	if (!(!arg && (sarg->prec == 0 && sarg->dot)))
		printed += write(1, strarg, strlen(strarg));
	free(strarg);
	return (printed);
}

size_t	u_out(va_list args, t_specs *sarg)
{
	unsigned int	arg;
	char			*strarg;
	size_t			printed;

	printed = 0;
	arg = va_arg(args, unsigned int);
	strarg = ft_uitoa(arg);
	printed += print_prefix_u(sarg, strarg);
	if (!(!arg && (sarg->prec == 0 && sarg->dot)))
		printed += write(1, strarg, strlen(strarg));
	free(strarg);
	return (printed);
}

size_t	p_out(va_list args, t_specs *sarg, char *syms)
{
	unsigned long long	arg;
	short				bits;
	short				res;

	res = 0;
	arg = va_arg(args, unsigned long long);
	bits = (8 * sizeof(unsigned long long) - 4);
	res += print_prefix_p(sarg, arg);
	if (!arg)
		res += write(1, "0", 1);
	while (bits >= 0 && arg)
	{
		if (arg >> bits || sarg->zero)
			res += write(1, syms + ((arg >> bits) & 15), 1);
		bits -= 4;
	}
	return (res);
}

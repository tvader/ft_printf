/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:00:37 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 22:04:00 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_structs(t_specs **specs)
{
	(*specs) = ft_calloc(1, sizeof(t_specs));
}

size_t	clearer(t_specs **sarg, size_t res, int to_free)
{
	if (sarg && *sarg)
	{
		(*sarg)->ext = 0;
		(*sarg)->width = 0;
		(*sarg)->prec = 0;
		(*sarg)->minus = 0;
		(*sarg)->plus = 0;
		(*sarg)->space = 0;
		(*sarg)->zero = 0;
		(*sarg)->dot = 0;
		if (to_free)
			free(*sarg);
	}
	return (res);
}

size_t	proceed(const char *to_print, va_list args)
{
	t_specs	*cur_sarg;
	size_t	printed;

	printed = 0;
	cur_sarg = NULL;
	init_structs(&cur_sarg);
	while (*to_print)
	{
		if (*to_print != '%')
			printed += write(1, to_print++, 1);
		else
		{
			to_print++;
			clearer(&cur_sarg, printed, 0);
			parcer(args, &to_print, cur_sarg);
			if (cur_sarg->ext)
				printed += outputter(args, cur_sarg);
			else
				return (clearer(&cur_sarg, printed, 1));
		}
	}
	return (clearer(&cur_sarg, printed, 1));
}

size_t	ft_printf(const char *input, ...)
{
	const char	*to_print;
	va_list		args;
	size_t		cnt_out;

	to_print = ft_strdup(input);
	if (!to_print)
		return (1);
	va_start(args, input);
	cnt_out = proceed(input, args);
	va_end(args);
	free((void *)to_print);
	return (cnt_out);
}

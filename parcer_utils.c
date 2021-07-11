/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:48:12 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 22:04:04 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char spec)
{
	char	*types;

	types = "XxdiuoeEaAsScpfF%";
	while (*types)
		if (spec == *(types++))
			return (1);
	return (0);
}

int	is_ch_in_str(char c, const char *str)
{
	while (*str)
		if (c == *str++)
			return (1);
	return (0);
}

size_t	def_speclen(const char *to_print, t_specs *specs)
{
	char		*spec_syms;
	size_t		speclen;

	speclen = 0;
	spec_syms = "-+ #.*%0123456789lhjztLdiouxXfFeEgGaAcsSpn";
	while (is_ch_in_str(to_print[speclen], spec_syms) && \
	!is_type(to_print[speclen]))
		speclen++;
	if (is_type(to_print[speclen]))
		speclen++;
	specs->speclen = speclen;
	return (speclen);
}

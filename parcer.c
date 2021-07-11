/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:49:46 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 22:04:05 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parcetype(const char *to_print, t_specs *cur_specs)
{
	size_t	iter;

	iter = 0;
	while (iter < cur_specs->speclen)
	{
		if (is_type(to_print[iter]))
			cur_specs->ext = to_print[iter];
		iter++;
	}
	return (0);
}

size_t	parcespecs1(const char *to_print, t_specs *sarg)
{
	size_t	iter;

	iter = 0;
	while (iter < sarg->speclen)
	{
		if (to_print[iter] == '-')
			sarg->minus = 1;
		else if (to_print[iter] == '+')
			sarg->plus = 1;
		else if (to_print[iter] == '0')
			sarg->zero = 1;
		else if (ft_isdigit(to_print[iter]))
			iter += (ft_nlen((char *)(to_print + iter)) - 1);
		else if (to_print[iter] == ' ')
			sarg->space = 1;
		iter++;
	}
	return (iter);
}

void	specs_correct(t_specs *sarg)
{
	if (sarg->width < 0)
	{
		sarg->width *= -1;
		sarg->minus = 1;
	}
	if (sarg->prec < 0)
	{
		sarg->dot = 0;
		sarg->prec = 0;
	}
	if (sarg->minus)
	{
		sarg->space = 0;
		sarg->zero = 0;
	}
	if (sarg->plus)
		sarg->space = 0;
	if (sarg->ext == 'd' || sarg->ext == 'i' || sarg->ext == 'o' || \
	sarg->ext == 'u' || sarg->ext == 'x' || sarg->ext == 'X')
		if (sarg->dot)
			sarg->zero = 0;
}

size_t	parcespecs2(va_list args, const char *to_print, t_specs *sarg)
{
	size_t	iter;

	iter = 0;
	while (iter < sarg->speclen)
	{
		if (to_print[iter] == '.')
			sarg->dot = 1;
		else if (ft_isdigit(to_print[iter]) && !(sarg->dot) && !(sarg->width))
		{
			sarg->width = ft_atoi((char *)(to_print + iter));
			iter += (ft_nlen((char *)(to_print + iter)) - 1);
		}
		else if (ft_isdigit(to_print[iter]) && !(sarg->prec))
		{
			sarg->prec = ft_atoi((char *)(to_print + iter));
			iter += (ft_nlen((char *)(to_print + iter)) - 1);
		}
		else if (to_print[iter] == '*' && !(sarg->dot) && !(sarg->width))
			sarg->width = va_arg(args, int);
		else if (to_print[iter] == '*' && sarg->dot && !(sarg->prec))
			sarg->prec = va_arg(args, int);
		iter++;
	}
	return (iter);
}

int 	parcer(va_list args, const char **to_print, t_specs *cur_specs)
{
	def_speclen(*to_print, cur_specs);
	parcetype(*to_print, cur_specs);
	parcespecs1(*to_print, cur_specs);
	parcespecs2(args, *to_print, cur_specs);
	specs_correct(cur_specs);
	*to_print += cur_specs->speclen;
	return (0);
}

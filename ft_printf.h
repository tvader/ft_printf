/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:59:13 by tvader            #+#    #+#             */
/*   Updated: 2021/07/01 22:03:57 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_specs
{
	size_t		speclen;
	char		ext;
	int			width;
	int			minus;
	int			plus;
	int			space;
	int			prec;
	int			zero;
	int			dot;
}				t_specs;

size_t	ft_printf(const char *input, ...);
size_t	proceed(const char *to_print, va_list args);
void	init_structs(t_specs **specs);
int		parcer(va_list args, const char **to_print, t_specs *cur_specs);
size_t	def_speclen(const char *to_print, t_specs *specs);
int		parcetype(const char *to_print, t_specs *cur_specs);
size_t	parcespecs1(const char *to_print, t_specs *sarg);
size_t	parcespecs2(va_list args, const char *to_print, t_specs *sarg);
void	specs_correct(t_specs *sarg);
int		is_type(char spec);
int		is_ch_in_str(char c, const char *str);
size_t	outputter(va_list args, t_specs *sarg);
size_t	c_out(va_list args, t_specs *sarg);
size_t	d_out(va_list args, t_specs *sarg);
size_t	p_out(va_list args, t_specs *sarg, char *syms);
size_t	percent_out(t_specs *sarg);
size_t	s_out(va_list args, t_specs *sarg);
size_t	x_out(va_list args, t_specs *sarg, char *lsyms, char *usyms);
size_t	u_out(va_list args, t_specs *sarg);
short	def_0xlen(unsigned int arg);
size_t	print_prefix_c(t_specs *sarg, size_t prelen);
size_t	print_prefix_di(t_specs *sarg, char *arg, int neg);
size_t	print_prefix_p(t_specs *sarg, unsigned long long arg);
size_t	print_prefix_s(t_specs *sarg, char *arg);
size_t	print_prefix_u(t_specs *sarg, char *arg);
size_t	print_prefix_x(t_specs *sarg, unsigned int arg);
size_t	print_suffix(t_specs *sarg, size_t strlen);
size_t	clearer(t_specs **sarg, size_t res, int to_free);
#endif

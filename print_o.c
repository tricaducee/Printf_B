/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:11 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:18:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_o(t_flags *flags, unsigned int o)
{
	int	c;

	flags->o = u_nbrlen_base(o, 8, flags);
	if (!flags->zero || flags->point || !flags->o)
		c = ' ';
	else
		c = '0';
	if (!flags->min && !flags->zero)
		repeat_putc_for_u(flags, c);
	if (o > 0 && flags->sharp)
		ft_putchar('0');
	if (!flags->min && flags->zero)
		repeat_putc_for_u(flags, c);
	if (flags->point > flags->o)
		repeat_putchar('0', flags->point - flags->o);
	if (flags->o)
		ft_putnbr_base_u(o, "01234567", 8);
	if (flags->min)
		repeat_putc_for_u(flags, c);
	if (flags->len > flags->o && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->o)
		return (flags->point);
	return (flags->o);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:29 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:19:36 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(t_flags *flags, unsigned int x)
{
	int	c;

	if (!flags->zero || flags->point)
		c = ' ';
	else
		c = '0';
	flags->x = u_nbrlen_base(x, 16, flags);
	if (!flags->min && !flags->zero)
		repeat_putc_for_u(flags, c);
	if (flags->x > 0 && flags->sharp)
		ft_putstr("0x");
	if (!flags->min && flags->zero)
		repeat_putc_for_u(flags, c);
	if (flags->point > flags->x)
		repeat_putchar('0', flags->point - flags->x);
	ft_putnbr_base_u(x, "0123456789abcdef", 16);
	if (flags->min)
		repeat_putc_for_u(flags, c);
	if (flags->len > flags->x && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->x)
		return (flags->point);
	return (flags->x);
}

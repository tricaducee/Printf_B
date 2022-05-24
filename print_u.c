/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:44 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:18:51 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(t_flags *flags, unsigned int u)
{
	int	c;

	if (!flags->zero || flags->point)
		c = ' ';
	else
		c = '0';
	flags->u = u_nbrlen_base(u, 10, flags);
	if (!flags->min && !flags->zero)
		repeat_putc_for_u(flags, c);
	if (flags->point > flags->u)
		repeat_putchar('0', flags->point - flags->u);
	ft_putnbr_base_u(u, "0123456789", 10);
	if (flags->min)
		repeat_putc_for_u(flags, c);
	if (flags->len > flags->u && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->u)
		return (flags->point);
	return (flags->u);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:08 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:19:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_upx(t_flags *flags, unsigned int upx)
{
	int	c;

	if (!flags->zero || flags->point)
		c = ' ';
	else
		c = '0';
	flags->upx = u_nbrlen_base(upx, 16, flags);
	if (!flags->min && !flags->zero)
		repeat_putc_for_u(flags, c);
	if (flags->upx > 0 && flags->sharp)
		ft_putstr("0X");
	if (!flags->min && flags->zero)
		repeat_putc_for_u(flags, c);
	if (flags->point > flags->upx)
		repeat_putchar('0', flags->point - flags->upx);
	ft_putnbr_base_u(upx, "0123456789ABCDEF", 16);
	if (flags->min)
		repeat_putc_for_u(flags, c);
	if (flags->len > flags->upx && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->upx)
		return (flags->point);
	return (flags->upx);
}

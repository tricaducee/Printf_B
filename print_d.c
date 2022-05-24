/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:17:32 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:17:40 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	repeat_putc_for_d(t_flags *flags, int c)
{
	if (flags->len > flags->d
		|| (flags->point > flags->d && flags->len > flags->point))
	{
		if (flags->point > flags->d)
			repeat_putchar(c, flags->len - flags->point);
		else
			repeat_putchar(c, flags->len - flags->d);
	}
}

void	put_sign(t_flags *flags)
{
	if (flags->plus)
		ft_putchar('+');
	else if (flags->sp)
		ft_putchar(' ');
}

int	print_d(t_flags *flags, int d)
{
	int	c;

	if (!flags->zero || flags->point)
		c = ' ';
	else
		c = '0';
	flags->d = nbrlen(d, 10, flags);
	if (!flags->min && !flags->zero)
		repeat_putc_for_d(flags, c);
	if (flags->d > 0)
		put_sign(flags);
	if (!flags->min && flags->zero)
		repeat_putc_for_d(flags, c);
	if (flags->point > flags->d)
		repeat_putchar('0', flags->point - flags->d);
	ft_putnbr(d);
	if (flags->min)
		repeat_putc_for_d(flags, c);
	if (flags->len > flags->d && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->d)
		return (flags->point);
	return (flags->d);
}

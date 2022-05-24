/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:17:11 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:17:21 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_flags *flags, int c)
{
	flags->c = 1;
	if (!flags->min && flags->len > flags->c)
	{
		if (flags->zero)
			repeat_putchar('0', flags->len - flags->c);
		else
			repeat_putchar(' ', flags->len - flags->c);
	}
	if (c)
		ft_putchar(c);
	//else if (!c && flags->sp)
	//	ft_putchar(' ');
	if (flags->min && flags->len > flags->c)
		repeat_putchar(' ', flags->len - flags->c);
	if (flags->len <= flags->c)
		return (flags->c);
	return (flags->len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:25 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:18:34 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_s_len(char *s, t_flags *flags)
{
	if (flags->point && (flags->point <= ft_strlen(s)))
		return (flags->point);
	return (ft_strlen(s));
}

int	print_s(t_flags *flags, char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	flags->s = flag_s_len(s, flags);
	if (!flags->min && flags->len > flags->s)
	{
		if (flags->zero)
			repeat_putchar('0', flags->len - flags->s);
		else
			repeat_putchar(' ', flags->len - flags->s);
	}
	if (flags->point && (flags->point < flags->s))
		ft_putstr_l(s, flags->point);
	else
		ft_putstr_l(s, flags->s);
	if (flags->min && flags->len > flags->s)
		repeat_putchar(' ', flags->len - flags->s);
	if (flags->len <= flags->s)
		return (flags->s);
	return (flags->len);
}

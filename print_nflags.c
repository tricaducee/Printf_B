/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:17:57 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:18:03 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nflags(t_flags *flags)
{
	int	c;

	if (flags->len)
	{
		if (flags->zero)
			c = '0';
		else
			c = ' ';
		repeat_putchar(c, flags->len);
		return (flags->len);
	}
	return (0);
}

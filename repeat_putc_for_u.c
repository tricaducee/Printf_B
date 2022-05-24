/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_putc_for_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:44 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:19:48 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	repeat_putc_for_u(t_flags *flags, int c)
{
	if (flags->len > flags->u
		|| (flags->point > flags->u && flags->len > flags->point))
	{
		if (flags->point > flags->u)
			repeat_putchar(c, flags->len - flags->point);
		else
			repeat_putchar(c, flags->len - flags->u);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:16:51 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:16:58 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbrlen(long int nbr, unsigned int base, t_flags *flags)
{
	unsigned int	i;
	unsigned int	nbrb;

	i = 0;
	if (nbr < 0)
	{
		nbrb = nbr * -1;
		i++;
	}
	else
	{
		nbrb = (unsigned long )nbr;
		if (flags->sp || flags->plus)
			i++;
		if (flags->point)
			flags->point += 1;
	}
	while (nbrb >= base)
	{
		nbrb /= base;
		i++;
	}
	return (i + 1);
}

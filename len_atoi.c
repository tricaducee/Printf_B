/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:16:37 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:16:44 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_atoi(const char *str, int *i)
{
	unsigned int	nbr;

	nbr = 0;
	if (str[*i] == '.')
		*i += 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = (nbr * 10) + (str[*i] - '0');
		*i += 1;
	}
	*i -= 1;
	return (nbr);
}

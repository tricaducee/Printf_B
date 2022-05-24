/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:10:08 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:14:15 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cmpt;

	va_start(args, str);
	i = 0;
	cmpt = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cmpt += flags_check(str, args, &i);
			if (str[i] && ft_strchr("scpdiuxXo%", str[i]))
				i++;
		}
		else if (str[i])
		{
			write(1, &str[i++], 1);
			cmpt++;
		}
	}
	va_end(args);
	return (cmpt);
}

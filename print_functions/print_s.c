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

#include "../HEADER/ft_printf.h"

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
}

int	flag_s_len(char *s, t_flags *flags)
{
	if (flags->zpoint)
		return (0);
	else if (flags->point > 0 && (flags->point <= ft_strlen(s)))
		return (flags->point);
	return (ft_strlen(s));
}

int	print_s(t_flags *flags, char *s)
{
	char	n_string[7];

	if (!s)
	{
		ft_strcpy(n_string, "(null)");
		s = n_string;
	}
	flags->s = flag_s_len(s, flags);
	if (!flags->min && flags->len > flags->s)
	{
		if (flags->zero)
			repeat_putchar('0', flags->len - flags->s);
		else
			repeat_putchar(' ', flags->len - flags->s);
	}
	ft_putstr_l(s, flags->s);
	if (flags->min && flags->len > flags->s)
		repeat_putchar(' ', flags->len - flags->s);
	if (flags->len <= flags->s)
		return (flags->s);
	return (flags->len);
}

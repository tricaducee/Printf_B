/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:59:33 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/22 12:59:35 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct S_t_flags
{
	int	c;
	int	s;
	int	d;
	int	u;
	int	x;
	int	o;
	int	upx;
	int	pourcent;
	int	min;
	int	zero;
	int	plus;
	int	point;
	int	sharp;
	int	sp;
	int	len;
}					t_flags;

void	flags_set(t_flags *flags);
void	value_check(const char *str, t_flags *flags, int *i);
int		flags_check(const char *str, va_list args, int *i);
char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);
int		nbrlen(long int nbr, int base, t_flags *flags);
int		u_nbrlen_base(unsigned int nbr, int base, t_flags *flags);
int		flag_s_len(char *s, t_flags *flags);
int		len_atoi(const char *str, int *i);

void	ft_putstr(char *s);
void	ft_putstr_l(char *s, int len);
void	rec_putnbr(unsigned int n);
void	ft_putnbr(int n);
void	ft_putnbr_base_u(unsigned int n, char *str, int base);
void	ft_putchar(char c);
void	repeat_putchar(char c, int len);
void	repeat_putc_for_u(t_flags *flags, int c);
void	repeat_putc_for_d(t_flags *flags, int c);
void	put_sign(t_flags *flags);

int		print_c(t_flags *flags, int c);
int		print_s(t_flags *flags, char *s);
int		print_d(t_flags *flags, int d);
int		print_u(t_flags *flags, unsigned int u);
int		print_x(t_flags *flags, unsigned int x);
int		print_upx(t_flags *flags, unsigned int upx);
int		print_o(t_flags *flags, unsigned int o);
int		print_nflags(t_flags *flags);

int		ft_printf(const char *str, ...);

#endif
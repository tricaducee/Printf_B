/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:10:08 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/21 13:10:29 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

void	print_flags(t_flags *flags)
{
	printf("\n\nFlags valeurs :\nc = %d\n", flags->c);
	printf("s = %d\n", flags->s);
	printf("d = %d\n", flags->d);
	printf("u = %d\n", flags->u);
	printf("x = %d\n", flags->x);
	printf("X = %d\n", flags->upx);
	printf("o = %d\n", flags->o);
	printf("pourcent = %d\n", flags->pourcent);
	printf("min = %d\n", flags->min);
	printf("zero = %d\n", flags->zero);
	printf("plus = %d\n", flags->plus);
	printf("point = %d\n", flags->point);
	printf("sharp = %d\n", flags->sharp);
	printf("sp = %d\n", flags->sp);
	printf("len = %d\n", flags->len);
}

void	flags_set(t_flags *flags)
{
	flags->c = 0;
	flags->s = 0;
	flags->d = 0;
	flags->u = 0;
	flags->x = 0;
	flags->o = 0;
	flags->upx = 0;
	flags->pourcent = 0;
	flags->min = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->point = 0;
	flags->sharp = 0;
	flags->sp = 0;
	flags->len = 0;
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}
/*
int	ft_atoi(const char *str)
{
	int				pn;
	unsigned int	nbr;
	int				i;

	pn = 1;
	nbr = 0;
	i = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			pn *= -1;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*(str++) - '0');
		i++;
	}
	if (i > 10)
	{
		if (pn < 0)
			return (0);
		else
			return (-1);
	}
	return ((int)nbr * pn);
}
*/
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

void	valeur_checker(const char *str, t_flags *flags, int *i)
{
	while (ft_strchr("-0123456789+.# p", str[*i]))
	{
		if (str[*i] == '-')
			flags->min = 1;
		else if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if (str[*i] == '#' || str[*i] == 'p')
			flags->sharp = 1;
		else if (str[*i] == ' ')
			flags->sp = 1;
		else if (str[*i] >= '1' && str[*i] <= '9' && !flags->point)
			flags->len = len_atoi(str, i); //nfp
		else if (str[*i] == '.')
			flags->point = len_atoi(str, i); //nfp
		if (str[*i] == 'p')
			break ;
		*i += 1;
	}
}

int	nbrlen(long int nbr, int base, t_flags *flags)
{
	int					i;
	unsigned long int	nbrb;

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

int	u_nbrlen(unsigned int nbr, int base, t_flags *flags)
{
	unsigned int	i;

	i = 0;
	if (flags->sharp && nbr > 0 && base > 10)
	{
		if (flags->point)
			flags->point += 2;
		i += 2;
	}
	else if (flags->sharp && nbr > 0 && base < 10)
		i++;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i + 1);
}

int	flag_s_len(char *s, t_flags *flags)
{
	if (flags->point && (flags->point <= ft_strlen(s)))
		return (flags->point);
	return (ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_l(char *s, int len)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < len)
		write(1, s + i++, 1);
}

void	putnbr(unsigned int n)
{
	unsigned int	nb;

	nb = n;
	if (n > 9)
		putnbr(n / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int n)
{
	int	pn;

	pn = 1;
	if (n < 0)
	{
		ft_putchar('-');
		pn *= -1;
	}
	putnbr(n * pn);
}

void	ft_putnbr_base(unsigned int n, char *str, int base)
{
	unsigned int	nb;

	nb = n;
	if (n >= base)
		ft_putnbr_base(n / base, str, base);
	ft_putchar(str[nb % base]);
}

int	print_c(t_flags *flags, int c)
{
	flags->c = 1;
	if (c)
		ft_putchar(c);
	else if (!c && flags->sp)
		ft_putchar(' ');
	//print_flags(flags);
	return (flags->c);
}

void	putc_loop(char c, int len)
{
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
}

int	print_s(t_flags *flags, char *s)
{
	flags->s = flag_s_len(s, flags);
	if (!flags->min && flags->len > flags->s)
	{
		if (flags->zero)
			putc_loop('0', flags->len - flags->s);
		else
			putc_loop(' ', flags->len - flags->s);
	}
	if (flags->point && (flags->point < flags->s))
		ft_putstr_l(s, flags->point);
	else
		ft_putstr_l(s, flags->s);
	if (flags->min && flags->len > flags->s)
		putc_loop(' ', flags->len - flags->s);
	//print_flags(flags);
	if (flags->len <= flags->s)
		return (flags->s);
	return (flags->len);
}

void	print_nlen(t_flags *flags, int c)
{
	if (flags->len > flags->d || (flags->point > flags->d && flags->len > flags->point))
	{
		if (flags->point > flags->d)
			putc_loop(c, flags->len - flags->point);
		else
			putc_loop(c, flags->len - flags->d);
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
		print_nlen(flags, c);
	if (flags->d > 0)
		put_sign(flags);
	if (!flags->min && flags->zero)
		print_nlen(flags, c);
	if (flags->point > flags->d)
			putc_loop('0', flags->point - flags->d);
	ft_putnbr(d);
	if (flags->min)
		print_nlen(flags, c);
	//print_flags(flags);
	if (flags->len > flags->d && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->d)
		return (flags->point);
	return (flags->d);
}

void	print_unlen(t_flags *flags, int c)
{
	if (flags->len > flags->u || (flags->point > flags->u && flags->len > flags->point))
	{
		if (flags->point > flags->u)
			putc_loop(c, flags->len - flags->point);
		else
			putc_loop(c, flags->len - flags->u);
	}
}

int	print_u(t_flags *flags, unsigned int u)
{
	int	c;

	if (!flags->zero || flags->point)
		c = ' ';
	else
		c = '0';
	flags->u = u_nbrlen(u, 10, flags);
	if (!flags->min && !flags->zero)
		print_unlen(flags, c);
	if (flags->point > flags->u)
			putc_loop('0', flags->point - flags->u);
	ft_putnbr_base(u, "0123456789", 10);
	//print_flags(flags);
	if (flags->min)
		print_unlen(flags, c);
		if (flags->len > flags->u && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->u)
		return (flags->point);
	return (flags->u);
}

int	print_x(t_flags *flags, unsigned int x)
{
	int	c;

	if (!flags->zero || flags->point)
		c = ' ';
	else
		c = '0';
	flags->x = u_nbrlen(x, 16, flags);
	if (!flags->min && !flags->zero)
		print_unlen(flags, c);
	if (flags->x > 0 && flags->sharp)
		ft_putstr("0x");
	if (!flags->min && flags->zero)
		print_unlen(flags, c);
	if (flags->point > flags->x)
			putc_loop('0', flags->point - flags->x);
	ft_putnbr_base(x, "0123456789abcdef", 16);
	if (flags->min)
		print_unlen(flags, c);
	//print_flags(flags);
	if (flags->len > flags->x && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->x)
		return (flags->point);
	return (flags->x);
}

int	print_upx(t_flags *flags, unsigned int upx)
{
		int	c;

	if (!flags->zero || flags->point)
		c = ' ';
	else
		c = '0';
	flags->upx = u_nbrlen(upx, 16, flags);
	if (!flags->min && !flags->zero)
		print_unlen(flags, c);
	if (flags->upx > 0 && flags->sharp)
		ft_putstr("0X");
	if (!flags->min && flags->zero)
		print_unlen(flags, c);
	if (flags->point > flags->upx)
			putc_loop('0', flags->point - flags->upx);
	ft_putnbr_base(upx, "0123456789ABCDEF", 16);
	if (flags->min)
		print_unlen(flags, c);
	//print_flags(flags);
	if (flags->len > flags->upx && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->upx)
		return (flags->point);
	return (flags->upx);
}

int	print_o(t_flags *flags, unsigned int o)
{
		int	c;

	if (!flags->zero || flags->point)
		c = ' ';
	else
		c = '0';
	flags->o = u_nbrlen(o, 8, flags);
	if (!flags->min && !flags->zero)
		print_unlen(flags, c);
	if (flags->o > 0 && flags->sharp)
		ft_putchar('0');
	if (!flags->min && flags->zero)
		print_unlen(flags, c);
	if (flags->point > flags->o)
			putc_loop('0', flags->point - flags->o);
	ft_putnbr_base(o, "01234567", 8);
	if (flags->min)
		print_unlen(flags, c);
	//print_flags(flags);
	if (flags->len > flags->o && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->o)
		return (flags->point);
	return (flags->o);
}

int	print_nflags(t_flags *flags)
{
	int	c;

	if (flags->len)
	{
		if (flags->zero)
			c = '0';
		else
			c = ' ';
		putc_loop(c, flags->len);
		return (flags->len);
	}
	//print_flags(flags);
	return (0);
}

int	print_arg(const char *str, va_list args, int *i) //Je peux envoyer pour print depuis ici, j'ai déjà toutes les infos
{
	t_flags	flags;

	flags_set(&flags);
	valeur_checker(str, &flags, i);
	if (str[*i] == '%')
		flags.pourcent = 1;
	else if (str[*i] == 'c')
		return (print_c(&flags, va_arg(args, int)));
	else if (str[*i] == 's')
		return (print_s(&flags, va_arg(args, char *)));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (print_d(&flags, va_arg(args, int)));
	else if (str[*i] == 'u')
		return (print_u(&flags, va_arg(args, unsigned int)));
	else if (str[*i] == 'x' || str[*i] == 'p')
		return (print_x(&flags, va_arg(args, unsigned int)));
	else if (str[*i] == 'X')
		return (print_upx(&flags, va_arg(args, unsigned int)));
	else if (str[*i] == 'o')
		return (print_o(&flags, va_arg(args, unsigned int)));
	return (print_nflags(&flags));
//	i++;
}
/*
int	print_arg(va_list args, const char *str)
{
	int		ret;
	t_flags	flags;

	ret = 0;
	flags_set(&flags);
	ret = flags_checker(str, &flags, args);
	print_flags(&flags); //tester
	return (ret);
}
*/
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
			cmpt += print_arg(str, args, &i);
			if (ft_strchr("scpdiuxXo%", str[i]))
				i++;
		}
		else
		{
			write(1, &str[i++], 1);
			cmpt++;
		}
	}
	va_end(args);
	return (cmpt);
}





//============================= MAIN TESTER ============================= MAIN TESTER ============================= MAIN TESTER ============================= MAIN TESTER ============================= MAIN TESTER ============================= MAIN TESTER =============================//





void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void gets_nb(char *str)
{
	int i = 0;
	fgets(str, 10000, stdin);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		viderBuffer();
	str[i] = 0;
}

int main(int argc, char **argv)
{
	int selecteur = 1;
	int i = 0;
	char str[10000] = {0};
	int d = 0;
	float f = 0;
	unsigned int u = 0;
	char c = 0;
	char s[10000] = {0};
	int ft_ret;
	int original_ret;

	while (selecteur != 0)
	{
		printf("\n\nChoisie le type d'entrée :\n\n0. quitter\n1. int\n2. float\n3. unsigned int\n4. char\n5. string\n\nVotre choix: ");
		scanf("%d", &selecteur);
		viderBuffer();
		if (selecteur > 0 && selecteur <6)
		{
			printf("\nTa string pour printf : ");
			gets_nb(str);
		//	viderBuffer();
		} 
		switch (selecteur)
		{
			case 0:
				printf("\nAu revoir :)\n");
				break;
			case 1:
				printf("\nEntre un int : ");
				scanf("%d", &d);
				viderBuffer();
				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, d);
				printf("\nRetour original : %d", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, d);
				printf("\nRetour ft_version : %d", ft_ret);
				break;
			case 2:
				printf("\nEntre un float : ");
				scanf("%f", &f);
				viderBuffer();
				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, f);
				printf("\nRetour original : %d", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, f);
				printf("\nRetour ft_version : %d", ft_ret);
				break;
			case 3:
				printf("\nEntre un unsigned int : ");
				scanf("%u", &u);
				viderBuffer();
 				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, u);
				printf("\nRetour original : %d", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, u);
				printf("\nRetour ft_version : %d", ft_ret);
				break;
			case 4:
				printf("\nEntre un char : ");
				scanf("%c", &c);
				viderBuffer();
 				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, c);
				printf("\nRetour original : %d", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, c);
				printf("\nRetour ft_version : %d", ft_ret);
				break;
			case 5:
				printf("\nEntre une string : ");
				gets_nb(s);
			//	viderBuffer();
 				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, s);
				printf("\nRetour original : %d", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, s);
				printf("\nRetour ft_version : %d", ft_ret);
				break;
			default:
				printf("\nT con ou quoi ? c'est pourtant simple, tu as 6 choix!!!\n");
				break;
		}
		while (s[i] || str[i])
		{
			s[i] = 0;
			str[i++] = 0;
		}
		i = 0;
	}
	return (0);
}


#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct S_t_FLAGS
{
	int c;
	int s;
	int d;
	int u;
	int x;
	int X;
	int pourcent;
	int min;
	int zero;
	int plus;
	int point;
	int sharp;
	int sp;
	int len;
}					t_FLAGS;

void    flags_set(t_FLAGS *flags)
{
	flags->c = 0;
	flags->s = 0;
	flags->d = 0;
	flags->u = 0;
	flags->x = 0;
	flags->X = 0;
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

int     len_atoi(char **str)
{
	int     nbr;

	nbr = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')//à modifier
		*(str++);
	return (nbr);
}

void    valeur_checker(char **str, t_FLAGS *flags)
{
	while (ft_strchr("cspdiuxX%-0123456789+.# ", **str))
	{
		if (**str == '-')
			flags->min = 1;
		else if (**str == '0')
			flags->zero = 1;
		else if (**str == '+')
			flags->plus = 1;
		else if (**str == '.')
			flags->point = len_atoi(++str);
		else if (**str == '#' || **str == 'p')
			flags->sharp = 1;
		else if (**str == ' ')
			flags->sp = 1;
		else if (**str >= '1' && **str <= '9')
			flags->len = len_atoi(str);
		*(str++);
		if (ft_strchr("cspdiuxX%", **str - 1))
			return ;
	}
}

int		nbrlen(long int nbr, int base, t_FLAGS *flags)
{
	int	i;
	unsigned long int nbrb;

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
			flags->point++;
	}
	while (nbrb >= base)
	{
		nbrb /= base;
		i++;
	}
	return (i + 1);
}

int		u_nbrlen(unsigned long int nbr, int base, t_FLAGS *flags)
{
	unsigned int	i;

	i = 0;
	if (flags->sp || flags->plus)
		i++;
	if (flags->sharp && nbr > 0)
		i += 2;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i + 1);
}

int		flag_s_len(char *arg, t_FLAGS *flags)
{
	if (flags->point <= ft_strlen(arg))
		return (flags->point);
	return (ft_strlen(arg));
}

void    flags_checker(char **str, t_FLAGS *flags, void arg)
{
	valeur_checker(str, flags);
	while (ft_strchr("cspdiuxX%-0123456789+.# ", **str))
	{
		if (**str == '%')
			flags->pourcent = 1;
		else if (**str == 'c')
			flags->c = 1;
		else if (**str == 's')
			flags->s = flag_s_len((char *)arg, flags);
		else if (**str == 'd' || **str == 'i')
			flags->d = nbrlen((long int)arg, 10, flags);
		else if (**str == 'u')
			flags->u = u_nbrlen((unsigned long int)arg, 10, flags);
		else if (**str == 'x' || **str == 'p')
			flags->x = u_nbrlen((unsigned long int)arg, 16, flags);
		else if (**str == 'X')
			flags->X = u_nbrlen((unsigned long int)arg, 16, flags;
		*(str++);
		if (ft_strchr("cspdiuxX%", **str - 1))
			return ;
	}
}

int		print_c(char c, t_FLAGS *flags)
{

}

int		print_s(char *s, t_FLAGS *flags)
{

}

void	putnbr(unsigned int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n > 9)
		putnbr(n / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	pn;

	pn = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		pn *= -1;
	}
	putnbr(n * pn, fd);
}

void	putc_loop(char c, int repeat)
{
	int	i;

	i = 0;
	while (i < repeat)
	{
		write(1, &c, 1);
		i++;
	}
}

int		print_d(int nbr, t_FLAGS *flags)
{
	int	i;
	int	j;

	i = 0;
	if (flags->len && (flags->len > flags->d || flags->len > flags->point))
	{
		if (flags->len && !flags->min)
		{
			if (flags->d >= flags->point)
				putc_loop(' ', flags->len - flags->d);
			else
				putc_loop(' ', flags->len - flags->point);
		}
		if (flags->plus && nbr > 0)
			write(1, "+", 1);
		else if (flags->sp && nbr > 0)
			write(1, " ", 1);
		if (flags->point > flags->d)
			putc_loop('0', flags->point - flags->d);
	}
	if (flags->plus && nbr > 0)
		write(1, "+", 1);
	else if (flags->sp && nbr > 0)
		write(1, " ", 1);
	ft_putnbr_fd(nbr, 1);
}

int		print_arg(char **str, void arg)
{
	t_FLAGS	flags;
	int		i;

	i = 0;
	flags_set(&flags);
	flags_checker(str, &flags);
	if (flags->pourcent)
		i = write(1, "%", 1);
	else if (flags->c)
		i = print_c((int)arg, &flags);
	else if (flags->s)
		i = print_s((char *)arg, &flags);
	else if (flags->p || flags->x)
		i = print_x((unsigned int)arg, &flags);
	else if (flags->d)
		i = print_d((int)arg, flags);
	else if (flags->u)
		i = print_u((unsigned int)arg, &flags);
	else if (flags->X)
		i = print_X((unsigned int)arg, &flags);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	int		i;

	va_start(str, args);
	i = 0;
	while(*str)
	{
		if (*str = '%')
			i += print_arg(&str, va_arg(args, void)); //Peut-on envoyer un argument en void et le recaster par la suite ?
		write(1, str, 1);
		str++;
		i++;
	}
	va_end(args);
	return (i);
}

int main()
{
	ft_printf("%d", 5);
	return (0);
}
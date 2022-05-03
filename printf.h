#ifdef PRINTF_H
# ifndef PRINTF_H

#include <stdarg.h>

typedef struct S_FLAGS
{
    int c;
    int s;
    int p;
    int d;
    int i;
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
}					FLAGS;

void    flags_set(FLAGS *flags)
{
    flags->c = 0;
    flags->s = 0;
    flags->p = 0;
    flags->d = 0;
    flags->i = 0;
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

int     len_atoi(**str)
{
    int     nbr;

    nbr = ft_atoi(*str);
    while (**str >= '0' && **str <= '9');
        *(str++);
    return (ret);
}

void    valeur_checker(char *str, FLAGS *flags)
{
    while (ft_strchr("cspdiuxX%-0123456789+.# ", *str))
    {
        if (*str == '-')
            flags->min = 1;
        else if (*str == '0')
            flags->zero = 1;
        else if (*str == '+')
            flags->plus = 1;
        else if (*str == '.')
            flags->point = len_atoi(&(++str));
        else if (*str == '#')
            flags->sharp = 1;
        else if (*str == ' ')
            flags->sp = 1;
        else if (*str >= '1' && *str <= '9')
            flags->len = len_atoi(&str);
        if (ft_strchr("cspdiuxX%", *str))
            return ;
        str++;
    }
}

void    flags_checker(char *str, FLAGS *flags)
{
    valeur_checker(str, flags);
    while (ft_strchr("cspdiuxX%-0123456789+.# ", *str))
    {
        if (*str == '%')
            flags->pourcent = 1;
        else if (*str == 'c')
            flags->c = 1;
        else if (*str == 's')
            flags->s = 1;
        else if (*str == 'p')
            flags->p = 1;
        else if (*str == 'd')
            flags->d = 1;
        else if (*str == 'i')
            flags->i = 1
        else if (*str == 'u')
            flags->u = 1;
        else if (*str == 'x')
            flags->x = 1;
        else if (*str == 'X')
            flags->X = 1;
        if (ft_strchr("cspdiuxX%", *str))
            return ;
        str++;
    }
}

int     ft_printf(const char *str, ...)
{
    va_list args;

    va_start(str, args);
    
}
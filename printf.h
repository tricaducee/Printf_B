#ifdef PRINTF_H
# ifndef PRINTF_H

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

void    valeur_checker(const char *str, FLAGS *flags)
{
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

void    flags_checker(const char *str, FLAGS *flags)
{
    valeur_checker(const char *str, FLAGS *flags)
}
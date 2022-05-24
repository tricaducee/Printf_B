#include <stdio.h>
#include "../ft_printf.h"

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

int main()
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
		printf("\n\nChoisie le type d'entrée :\n\n0. quitter\n1. int\n2. float\n3. unsigned int\n4. char\n5. string\n6. NULL\n7. Tripouille\n\nVotre choix: ");
		scanf("%d", &selecteur);
		viderBuffer();
		if (selecteur > 0 && selecteur <7)
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
			case 6:
 				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, 0);
				printf("\nRetour original : %d", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, 0);
				printf("\nRetour ft_version : %d", ft_ret);
				break;
			case 7:
				printf("\n\nTest 1 :");
 				printf("\n\nOriginal :\n"); 
				original_ret = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
				printf("\nRetour original : %d", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
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

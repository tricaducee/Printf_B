
#include <stdio.h>
#include "../../HEADER/ft_printf.h"

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
	int	ft_ret = 0;
	int original_ret = 0;

	while (selecteur != 0)
	{
		printf("\n\nChoisie le type d'entrée :\n\n0. quitter\n1. int\n2. float\n3. unsigned int\n4. char\n5. string\n\nVotre choix: ");
		scanf("%d", &selecteur);
		viderBuffer();
		if (selecteur > 0 && selecteur <6)
		{
			printf("\nTa string pour printf : ");
			gets_nb(str);
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
				printf("\nRetour : %d\n", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, d);
				printf("\nRetour : %d\n", ft_ret);
				break;
			case 2:
				printf("\nEntre un float : ");
				scanf("%f", &f);
				viderBuffer();
				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, f);
				printf("\nRetour : %d\n", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, f);
				printf("\nRetour : %d\n", ft_ret);
				break;
			case 3:
				printf("\nEntre un unsigned int : ");
				scanf("%u", &u);
				viderBuffer();
 				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, u);
				printf("\nRetour : %d\n", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, u);
				printf("\nRetour : %d\n", ft_ret);
				break;
			case 4:
				printf("\nEntre un char : ");
				scanf("%c", &c);
				viderBuffer();
 				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, c);
				printf("\nRetour : %d\n", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, c);
				printf("\nRetour : %d\n", ft_ret);
				break;
			case 5:
				printf("\nEntre une string : ");
				gets_nb(s);	
 				printf("\n\nOriginal :\n"); 
				original_ret = printf(str, s);
				printf("\nRetour : %d\n", original_ret);
				printf("\n\nFt version :\n"); 
				ft_ret = ft_printf(str, s);
				printf("\nRetour : %d\n", ft_ret);
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
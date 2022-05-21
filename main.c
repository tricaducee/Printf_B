#include <stdio.h>
//#include "ft_printf.h"

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
				printf(str, d);
				printf("\n\nFt version :\n"); 
				ft_printf(str, d);
				break;
			case 2:
				printf("\nEntre un float : ");
				scanf("%f", &f);
				viderBuffer();
				printf("\n\nOriginal :\n"); 
				printf(str, f);
				printf("\n\nFt version :\n"); 
				ft_printf(str, f);
				break;
			case 3:
				printf("\nEntre un unsigned int : ");
				scanf("%u", &u);
				viderBuffer();
 				printf("\n\nOriginal :\n"); 
				printf(str, u);
				printf("\n\nFt version :\n"); 
				ft_printf(str, u);
				break;
			case 4:
				printf("\nEntre un char : ");
				scanf("%c", &c);
				viderBuffer();
 				printf("\n\nOriginal :\n"); 
				printf(str, c);
				printf("\n\nFt version :\n"); 
				ft_printf(str, c);
				break;
			case 5:
				printf("\nEntre une string : ");
				gets_nb(s);
			//	viderBuffer();
 				printf("\n\nOriginal :\n"); 
				printf(str, s);
				printf("\n\nFt version :\n"); 
				ft_printf(str, s);
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

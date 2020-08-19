#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define VALMAX 100

int conta_linhas(int x)
{
    printf("%d\n", x);
}

int maior_linha(char matrix[50][VALMAX], int x)
{
    int i, j=0, k;
    for(i=0; i<x; i++)
    {
        if(j < strlen(matrix[i]))
        {
            j = strlen(matrix[i]);
            k = ++i;
        }
    }
    printf("%d\n", k);
}

int menor_linha(char matrix[50][VALMAX], int x)
{
    int i, j=9999, k;
    for(i=0; i<x; i++)
    {
        if(j > strlen(matrix[i]))
        {
            j = strlen(matrix[i]);
            k = ++i;
        }
    }
    printf("%d\n", k);
}

int conta_vogais(char matrix[50][VALMAX], int x)
{
    int l, j, k;
    int a=0, e=0, i=0, o=0, u=0;
    for(l=0; l<x; l++)
    {
        for(j=0; j<strlen(matrix[l]); j++)
        {
            if(matrix[l][j] == 'a'|| matrix[l][j] == 'A')
            {
                ++a;
            }
            else if(matrix[l][j] == 'e'|| matrix[l][j] == 'E')
            {
                ++e;
            }
            else if(matrix[l][j] == 'i'|| matrix[l][j] == 'I')
            {
                ++i;
            }
            else if(matrix[l][j] == 'o'|| matrix[l][j] == 'O')
            {
                ++o;
            }
            else if(matrix[l][j] == 'u'|| matrix[l][j] == 'U')
            {
                ++u;
            }
        }
    }
    printf("a:%d e:%d i:%d o:%d u:%d", a, e, i, o, u);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    char txt[50][VALMAX], aux[VALMAX], arqgen[VALMAX];
    int i=0;


    printf("Digite o endereço do arquivo que deseja acessar\n");
    gets(arqgen);
    FILE *fin = fopen(arqgen, "r");
    while(fgets(aux, VALMAX, fin) != NULL)
    {
        strcpy(txt[i], aux);
        i++;
    }

    conta_linhas(i);

    maior_linha(txt, i);

    menor_linha(txt, i);

    conta_vogais(txt, i);

    fclose(fin);
    return 0;
}

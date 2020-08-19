#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nota_ {
char caracter[100];
float duracao[100];
} nota;



int main()
{
    nota n;
    int x, i=0, j=0, k, y=0;
    float ver;

    printf("Digite a sua partitura a seguir:\n");
    gets(n.caracter);
    x = strlen(n.caracter);

    for(i=0; i<x; i++)
    {
        if(n.caracter[i] == 'W')
        {
            n.duracao[i] = 1;
        }
        else if(n.caracter[i] == 'H')
        {
            n.duracao[i] = 0.5;
        }
        else if(n.caracter[i] == 'Q')
        {
            n.duracao[i] = 0.25;
        }
        else if(n.caracter[i] == 'E')
        {
            n.duracao[i] = 0.125;
        }
        else if(n.caracter[i] == 'S')
        {
            n.duracao[i] = 0.0625;
        }
        else if(n.caracter[i] == 'T')
        {
            n.duracao[i] = 0.03125;
        }
        else if(n.caracter[i] == 'X')
        {
            n.duracao[i] = 0.015625;
        }
        else if(n.caracter[i] == '/')
        {
            n.duracao[i] = 0;
        }

    }

    while(j < x)
    {
        if(n.caracter[j] == '/')
        {
            i = 0;
            ver = 0;
            j++;
        }
        else if(n.caracter[j+1] != '/')
        {
            i++;
            j++;
        }
        else if(n.caracter[j+1] == '/')
        {
            for(k=(j-i); k<=j; k++)
            {
                ver = ver + n.duracao[k];
            }
            if(ver == 1)
                {
                    y++;
                }
            j++;
        }

    }

    printf("\n%d", y);




    return 0;
}

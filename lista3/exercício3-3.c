#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float calcula_funcao(float y)
{
    if(y == 0) return 0;
    else return (1 + pow((y),2))/(y) + calcula_funcao(y-1);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float x;

    printf("Insira um número:\n");
    scanf("%f", &x);

    printf("%.2f", calcula_funcao(x));

    return 0;
}

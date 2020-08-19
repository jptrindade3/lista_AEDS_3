#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int imprime_intervalo(int x, int y)
{
    if(y == x)
    {
        printf("%d ", x);
        return x;
    }
    else
    {
        printf("%d ", x);
        return imprime_intervalo(x+1,y);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int a, b, c;

    printf("Digite um intervalo numérico:\n");
    scanf("%d %d", &a, &b);
    printf("\n");
    while(a > b)
    {
        printf("Intervalo inválido, tente novamente\n");
        scanf("%d %d", &a, &b);
        printf("\n");
    }

    imprime_intervalo(a, b);

    return 0;
}

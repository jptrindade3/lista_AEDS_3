#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int conta_digitos(int y)
{
    if(y < 10) return 1;
    else return conta_digitos(y/10) + 1;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int x;

    printf("Insira um n�mero:\n");
    scanf("%d", &x);

    printf("n� de d�gitos: %d\n", conta_digitos(x));

    return 0;
}

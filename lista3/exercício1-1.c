#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct carro_{
  char modelo[50];
  int consumo;
} carro;

int main()
{
    carro *info = NULL;
    int x, i, j=0, k;

    printf("Quantos carros deseja incluir? ");
    scanf("%d", &x);
    info = (carro*)malloc(x*sizeof(carro));
    printf("\ninsira os modelos e o consumo de cada carro\n");

    for(i=0; i<x; i++)
    {
      fflush(stdin);
      gets(info[i].modelo);
      scanf("%d", &info[i].consumo);
    }

    for(i=0; i<x; i++)
    {
      if(info[i].consumo > j)
      {
        j = info[i].consumo;
        k = i;
      }
    }

    printf("\n");
    puts(info[k].modelo);

    return 0;
}

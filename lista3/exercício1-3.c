#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct data_{
    int dia, mes, ano;
} data;
typedef struct hora_{
    int hora, min;
} hora;
typedef struct compromisso_{
    data d;
    hora h;
    char desc[50];
} compromisso;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int x, y, i=0, j;
    compromisso add[50];

    printf("Bem-vindo à agenda, o que deseja fazer?\n1. Registrar compromisso\n2. Listar todos os compromissos\n3. Listar compromissos de um mês\n4. Sair\n\n");
    while(x != 4)
    {
        fflush(stdin);
        scanf("%d", &x);
        if(x == 1)
        {
            printf("Insira a data desejada:\n");
            printf("Dia: ");
            fflush(stdin);
            scanf("%d/%d/%d", &add[i].d.dia, &add[i].d.mes, &add[i].d.ano);

            printf("Horário: ");
            fflush(stdin);
            scanf("%d:%d", &add[i].h.hora, &add[i].h.min);

            printf("Nome do compromisso: ");
            fflush(stdin);
            gets(add[i].desc);
            i++;
        }
        else if(x == 2)
        {
            for(j=0; j<i; j++)
            {
                printf("%s %d/%d/%d %d:%d \n", add[j].desc, add[j].d.dia, add[j].d.mes, add[j].d.ano, add[j].h.hora, add[j].h.min);
            }
        }
        else if(x == 3)
        {
            printf("Você deseja ver seus compromissos de qual mês?: ");
            scanf("%d", &y);
            for(j=0; j<i; j++)
            {
                if(y == add[j].d.mes)
                {
                    printf("%s %d/%d/%d %d:%d \n", add[j].desc, add[j].d.dia, add[j].d.mes, add[j].d.ano, add[j].h.hora, add[j].h.min);
                }
            }
            if(i == 0)
            {
                printf("Sem compromissos pendentes nesse mês!\n");
            }
        }
        else if(x == 4)
        {
            printf("\nAte mais !!!");
            break;
        }
        printf("\n");
    }
    return 0;
}

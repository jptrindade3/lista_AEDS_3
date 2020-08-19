#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define VALMAX 70

typedef struct data_{
    int dia, mes, ano;
} data;
typedef struct hora_{
    int hora, min;
} hora;
typedef struct compromisso_{
    data d;
    hora h;
    char desc[VALMAX];
} compromisso;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *fagenda;
    int x, y, i=0, j, k;
    char aux[VALMAX];
    compromisso add[50];

    printf("Bem-vindo à agenda, o que deseja fazer?\n1. Registrar compromisso\n2. Listar todos os compromissos\n3. Listar compromissos de um mês\n");
    printf("4. Salvar agenda\n5. Carregar agenda salva\n6. Sair\n\n");
    while(x != 6)
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
            fagenda = fopen("agenda.txt", "a");
            for(k=0; k<i; k++)
            {
                fprintf(fagenda,"%s %d/%d/%d %d:%d\n", add[k].desc, add[k].d.dia, add[k].d.mes, add[k].d.ano, add[k].h.hora, add[k].h.min);
            }
            fclose(fagenda);
            printf("A sua agenda foi salva com sucesso!\n");
        }
        else if( x == 5)
        {
            k = 1;
            printf("Compromissos salvos na agenda:\n\n");
            fagenda = fopen("agenda.txt", "r");
            while(fgets(aux, VALMAX, fagenda) != NULL)
            {
                printf("Compromisso %d:\n%s\n", k, aux);
                ++k;
            }
            fclose(fagenda);
        }
        else if( x == 6)
        {
            printf("\nAte mais !!!");
            break;
        }
        printf("\n");
    }
    return 0;
}



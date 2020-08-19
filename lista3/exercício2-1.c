#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define VALMAX 100
typedef struct registros_{
char nome[VALMAX];
int matricula;
int notas[4];
float medias;
} registros;

int main()
{
    setlocale(LC_ALL, "portuguese");
    //Abrindo os arquivos
    FILE *fnomes = fopen("nomes.txt", "r");
    FILE *fnotas = fopen("notas.txt", "r");
    FILE *fmedias = fopen("medias.txt", "w");

    //Definindo variáveis
    registros info[VALMAX];
    char aux[VALMAX], *token, *nxtoken;
    int i=0, j=0, k=0, intoken;
    float media;

    while(fgets(aux, VALMAX, fnomes) !=NULL)
    {
        token = strtok(aux, " ");
        nxtoken = strtok(NULL, " ");
        while(nxtoken != NULL)
        {
            strcat(info[i].nome, token);
            strcat(info[i].nome, " ");
            token = nxtoken;
            nxtoken = strtok(NULL, " ");
        }
        info[i].matricula = atoi(token);
        i++;
    }
    i--;
    while(fgets(aux, VALMAX, fnotas) != NULL)
    {
        token = strtok(aux, " ");
        nxtoken = strtok(NULL, " ");
        intoken = atoi(token);
        while(intoken != info[j].matricula)
        {
            j++;
        }
        //printf("---%d---\n", j);
        while(nxtoken != NULL)
        {
            token = nxtoken;
            intoken = atoi(token);
            info[j].notas[k] = intoken;
            //printf("%d\n", info[j].notas[k]);
            nxtoken = strtok(NULL, " ");
            k++;
        }
        j=0;
        k=0;
    }
    for(j=0; j<=i; j++)
    {
        for(k=0; k<4; k++)
        {
            media = media + info[j].notas[k];
        }
        info[j].medias = (media/4);
        media = 0;
        fprintf(fmedias, "%s %.2f\n",info[j].nome, info[j].medias);
    }
    fclose(fnomes);
    fclose(fnotas);
    fclose(fmedias);

    return 0;
}

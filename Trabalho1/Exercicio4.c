#include <stdio.h>
#include <stdlib.h>

int dados(int matriz[][6], int tamanho)
{
    for(int i = 0; i < tamanho; i ++)
    {
        printf("insira o codigo do municipio\n");
        scanf("%d", &matriz[i][0]);
        printf("insira o numero de habitantes\n");
        scanf("%d", &matriz[i][1]);
        printf("insira os casos confirmados\n");
        scanf("%d",&matriz[i][2]);
        printf("Insira o numero de obitos\n");
        scanf("%d", &matriz[i][3]);
    }

}

int incidencia(int matriz[][6], int tamanho)
{
    for(int i = 0; i < tamanho; i ++)
    {
        double habitantes = matriz[i][1];
        double casos = matriz[i][2];
        matriz[i][4] = 100000 * (casos/habitantes);
    }
}
int obitos(int matriz[][6], int tamanho)
{
    for(int i = 0; i < tamanho; i ++)
    {
        double habitantes = matriz[i][1];
        double obitos = matriz[i][3];
        matriz[i][5] = 100000 * (obitos/habitantes);
    }
}
int imprimir(int matriz[][6], int tamanho)
{
    for(int i = 0; i < tamanho; i ++)
    {
        printf("Codigo do municipio: %d\n",matriz[i][0]);
        printf("Quantidade de habitantes: %d\n",matriz[i][1]);
        printf("Casos confirmados: %d\n",matriz[i][2]);
        printf("Total de Obitos: %d\n",matriz[i][3]);
        printf("Incidencia de casos: %d\n",matriz[i][4]);
        printf("Mortalidade: %d\n\n",matriz[i][5]);
    }
}
int maisMort(int matriz[][6], int tamanho)
{
    int maior = 0;
    int codigo;
    for(int i = 0; i < tamanho; i ++)
    {
        if(matriz[i][5] > maior)
        {
            maior = matriz[i][5];
            codigo = i;
        }
    }
    printf("O codigo do municipio de maior mortalidade eh: %d\n", matriz[codigo][0]);
}
int maisInci(int matriz[][6], int tamanho)
{
    int maior = 0;
    int codigo;
    for(int i = 0; i < tamanho; i ++)
    {
        if(matriz[i][4] > maior)
        {
            maior = matriz[i][4];
            codigo = i;
        }
    }
    printf("O codigo do municio de maior incidencia eh: %d", matriz[codigo][0]);
}



int main()
{   int linha;
    printf("insira o numero de municipios\n");
    scanf("%d", &linha);
    int matriz[linha][6];
    dados(matriz, linha);
    incidencia(matriz, linha);
    obitos(matriz, linha);
    imprimir(matriz, linha);
    maisMort(matriz, linha);
    maisInci(matriz, linha);
}
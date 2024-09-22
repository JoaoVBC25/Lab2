#include <stdio.h>
#include <stdlib.h>

void lerVetor(int vetor[])
{
    for(int i = 0; i < 5; i ++)
    {
        printf("Insira um valor inteiro\n");
        scanf(" %d", &vetor[i]);
    }
}
void inverter(int vetor[])
{
    int vetorAuxiliar[5];

    for(int i = 0; i < 5; i ++)
    {
        vetorAuxiliar[i] = vetor[i];
    }

    for(int i = 0, ii = 4; i < 5; i ++, ii --)
    {
        vetor[i] = vetorAuxiliar[ii];
    }

}

float ordenar(int vetor[])
{   int w = 0;
    int maior = 0;
    for(int i = 0; i < 5; i ++)
    {
        for(int j = w; j < 5; j ++)
        {
            if(vetor[j] > maior)
            {
                maior = vetor[j];
            }
        }
        vetor[i] = maior;
        maior = 0;
        w++;
        printf("%d", vetor[i]);
    }
}
float mediaV(int vetor[])
{
    float media = 0;
    for(int i = 0; i < 5; i ++)
    {
        media = media + vetor[i];
    }
    media = media / 5;
    printf("a media dos valores do vetor eh%2.f\n", media);
    return media;
}
int maiorMedia(int vetor[], int media)
{
    int maior = 0;
    for(int i = 0; i < 5; i ++)
    {
        if(vetor[i] > media)
        {
            maior++;
        }
    }
    printf("%d valores sao maiores que a media\n", maior);
}

int main()
{
    float media = 0;
    int vetor[5];
    lerVetor(vetor);
    inverter(vetor);
    printf("\n");
    ordenar(vetor);
    printf("\n");
    printf("o maior valor eh %d\n", vetor[0]);
    printf("o menor valor eh %d\n", vetor[1]);
    media = mediaV(vetor);
    maiorMedia(vetor, media);
}
#include <stdio.h>
#include <stdlib.h>

struct usuario
{
int idade;
int qtdade;
};
typedef struct usuario Usuario;

void leVetor(int tamanho, Usuario* vetor)
{
    for(int i = 0; i < tamanho; i ++)
    {
       printf("insira a idade do usuario\n");
       scanf(" %d", &vetor[i].idade);
       printf("insira a quantidade de livros lida\n");
       scanf(" %d", &vetor[i].qtdade);
    }

}

int calculaQtidadedeLivros(int tamanho, Usuario* vetor)
{
    int QtdMenor = 0;
    for(int i = 0; i < tamanho; i ++)
    {
        if(vetor[i].idade < 18)
        {
            QtdMenor = QtdMenor + vetor[i].qtdade;
        }
    }
    return QtdMenor;

}

float calculaMedia(int tamanho, Usuario* vetor)
{
    float media = 0;
    for(int i = 0; i < tamanho; i ++)
    {
        media = media + vetor[i].qtdade;
    }
    media = media / tamanho;
    return media;


}

int main()
{   int QtdMenor18, tamanho = 5;
    float media;
    Usuario vetor[tamanho];
    leVetor(tamanho, vetor);
    QtdMenor18 = calculaQtidadedeLivros(tamanho, vetor);
    media = calculaMedia(tamanho, vetor);

    printf("Livros lidos por menores de 18: %d\n", QtdMenor18);
    printf("Media de livros lidos: %.1f", media);


}
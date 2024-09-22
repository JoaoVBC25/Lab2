#include <stdio.h>
#include <stdlib.h>

int main()
{
    float p1, p2, p3, media;
    printf("insira a primeira nota\n");
    scanf(" %f",&p1);
    printf("insira a segunda nota\n");
    scanf(" %f", &p2);
    media = (p1 + p2) / 2;
    if(p1 < 3 || p2 < 3 || media < 5)
    {
        printf("insira a nota da terceira prova\n");
        scanf("%f", &p3);
        if(p1 > p2)
        {
            media = (p1 + p3) / 2;
        }
        else
        {
            media = (p2 + p3) / 2;
        }
        if(media >= 5)
        {
            printf("aluno aprovado");
            return 0;
        }
        else
        {
            printf("aluno reprovado");
            return 0;
        }
    }
    else
    {
        printf("aluno aprovado");
        return 0;
    }
}
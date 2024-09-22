#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,n3;
    do
    {
       printf("\nInsira tres numeros em ordem crescente\n");
       scanf(" %f", &n1);
       scanf(" %f", &n2);
       scanf(" %f", &n3);
       printf("Soma: %f\n", n1 + n2 + n3);
       printf("Produto: %f\n", n1 * n2 * n3);
       printf("Media: %f", (n1 + n2 + n3) / 3);
    }  while(n1 < n2 && n2 < n3);
}
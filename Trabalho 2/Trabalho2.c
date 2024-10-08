#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buscarPalavra(char** matriz,int linha,int coluna);
void definirMatriz(char **matriz, char* texto, int linha, int coluna);
void removerEspaco(char* texto);
char **definirTamanho(int *linha, int *coluna);
void definirConteudo(char **matriz, int linha, int coluna);
void imprimeMatriz(char** matriz, int linha, int coluna);
void buscarPalavra(char** matriz, int linha, int coluna);
void buscarDiagonais(char** matriz, int linha, int coluna, int len, char* texto);




void definirMatriz(char **matriz, char* texto, int linha, int coluna)
{
    int w = 0;
    for(int i = 0; i < linha; i ++)
    {

        for(int j = 0; j < coluna; j ++)
        {
            matriz[i][j] = texto[w];
            w ++;
        }
    }

}

void removerEspaco(char* texto) 
{
    char* copia = texto;
    do {
        while (*copia == ' ') {
            ++copia;
        }
    } while (*texto++ = *copia++);
}
char **definirTamanho(int *linha, int *coluna)
{
    int l;
    int c;
    char** matriz;
    printf("Insira o numero de linhas\n");
    scanf(" %d", &l);
    printf("Insira o numero de colunas\n");
    scanf(" %d",&c);
    *linha = l;
    *coluna = c;
    matriz = (char**)malloc(l*sizeof(char*));
    for(int i = 0; i < l; i ++)
    {
        matriz[i] = (char*)malloc(c*sizeof(char));
    }
    return matriz;
}
void definirConteudo(char **matriz, int linha, int coluna)
{
    int tamanho = coluna * linha, i = 0;
    char texto[1000], texto2[tamanho + 1];
    printf("Insira o conteudo da matriz\n");
    scanf(" ");
    fgets(texto, 1000, stdin);
    removerEspaco(texto);
    texto[strlen(texto) - 1] = '\0';
    for(i = 0; texto[i] != '\0'; i ++)
    {
        texto2[i] = texto[i];
    }
    for(i; i < tamanho; i ++)
    {
        texto2[i] = ' ';
    }
    definirMatriz(matriz, texto2, linha, coluna);
}
void imprimeMatriz(char** matriz, int linha, int coluna)
{
    printf("\n\n\n");
    for(int i = 0; i < linha; i ++)
    {
        printf("\n|");
        for(int j = 0; j < coluna; j ++)
        {
            printf("%c|", matriz[i][j]);
        }
    }
}
void buscarPalavra(char** matriz, int linha, int coluna)
{
    char** auxiliar = (char**)malloc(coluna*sizeof(char*));
    for(int i = 0; i < coluna; i ++)
    {
        auxiliar[i] = (char*)malloc(linha*sizeof(char));
    }
    for(int i = 0; i < coluna; i ++)
    {
        for(int j = 0; j < linha; j ++)
        {
            auxiliar[i][j] = matriz[j][i];
        }
    }
    char texto[30], reverso[30], reverso2[30];
    char *palavra, *inverso, *palavraV, *inversoV;
    printf("\nPARA PARAR DE PROCURAR DIGITE .");  
    do
    {
      printf("\n\nInsira uma palavra: ");
      scanf(" %s", &texto);
      int len = strlen(texto);
      strcpy(reverso, texto);
      strcpy(reverso2, texto);
      for(int i = 0; i < linha; i ++)
      {
        palavra = strstr(matriz[i], texto);
        inverso = strstr(matriz[i], strrev(reverso));
        palavraV = strstr(auxiliar[i], texto);
        inversoV = strstr(auxiliar[i], strrev(reverso2));
        if(palavra != NULL)
        {
            //Horizontal Direta
            printf("\nPalavra %s ocorre na horizontal direta, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]",texto, i + 1, palavra - matriz[i] + 1, i + 1, strlen(texto) + palavra - matriz[i]);
        }
        else if(inverso != NULL)
        {
          //Horizontal Reversa
          printf("\nPalavra %s ocorre na horinzontal reversa, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]",texto, i + 1, strlen(texto) + inverso - matriz[i], i + 1, inverso - matriz[i] + 1);
        }
        else if(palavraV != NULL)
        {
          //Vertical Direta
          printf("\nPalavra %s ocorre na vertical direta, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]",texto, palavraV - auxiliar[i] + 1, i + 1, strlen(texto) + palavraV - auxiliar[i], i + 1);
        }
        else if(inversoV != NULL)
        {
          //Vertical Reversa
          printf("\nPalavra %s ocorre na vertical reversa, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]",texto, strlen(texto) + inversoV - auxiliar[i], i + 1, inversoV - auxiliar[i] + 1, i + 1);
        }
      }
      buscarDiagonais(matriz, linha, coluna, len, texto);
    }    
    while (texto[0] != '.');
    free(auxiliar);
}
void buscarDiagonais(char** matriz, int linha, int coluna, int len, char* texto)
{
    //Diagonal Principal Direta
          for (int i = 0; i <= linha - len; i++) 
          {
            for (int j = 0; j <= coluna - len; j++) 
            {
              int k;
              for (k = 0; k < len; k++) 
              {
                if (matriz[i + k][j + k] != texto[k]) 
                {
                  break;
                }
              }
              if (k == len) 
              {
                printf("\nPalavra %s ocorre na diagonal principal direta, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]",texto, i + 1, j + 1, strlen(texto) + i, strlen(texto) + j);
                i = linha + 1;
              }

            }
          }
          //Diagonal Principal reversa
          for (int i = linha - 1; i >= len - 1; i--) 
          {
            for (int j = coluna; j >= len - 1; j--) 
            {
              int k;
              for (k = 0; k < len; k++) 
              {

                  if (matriz[i - k][j - k] != texto[k]) 
                  {
                    break;
                  }
              }
              if (k == len) 
              {
                printf("\nPalavra %s ocorre na diagonal principal reversa, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]",texto, i + 1, j + 1, strlen(texto) - i, strlen(texto) - j);
                i = len - 1;
              }

            }
          }  
          //Diagonal secundaria direta
          for (int i = 0; i <= linha - len; i++) 
          {
            for (int j = len - 1; j < coluna; j++) 
            {
              int k;
              for (k = 0; k < len; k++) 
              {
                if (matriz[i + k][j - k] != texto[k]) 
                {
                    break;
                }
              }
              if (k == len) 
              {
                printf("\nPalavra %s ocorre na diagonal secundaria direta, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]",texto, i + 1, j + 1, strlen(texto) - i, strlen(texto) - j);
                i = linha + 1;
              }
            }
          }
          //Diagonal secundaria reversa
          for (int i = linha - 1; i >= len - 1; i--) 
          {
            for (int j = 0; j <= coluna; j++) 
            {
              int k;
              for (k = 0; k < len; k++) 
              {
                if (matriz[i - k][j + k] != texto[k]) 
                {
                    break;
                }
              }
              if (k == len) 
              {
                printf("\nPalavra %s ocorre na diagonal secundaria reversa, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]",texto, i + 1, j + 1, strlen(texto) - i, strlen(texto) + j);
                i = linha + 1;
              }
            }
          }

}
int main()
{
    int linha, coluna;
    char** matriz = definirTamanho(&linha, &coluna);
    definirConteudo(matriz, linha, coluna);
    imprimeMatriz(matriz, linha, coluna);
    buscarPalavra(matriz, linha, coluna);
    free (matriz);

}
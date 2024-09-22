1. SELEÇÃO Considere uma disciplina que adota o seguinte critério de aprovação: os alunos fazem duas provas
(P1 e P2) iniciais; se a média nas duas provas for maior ou igual a 5.0, e se nenhuma das duas notas for inferior
a 3.0, o aluno passa direto. Caso contrário, o aluno faz uma terceira prova (P3) e a média é calculada
considerando-se a terceira nota e a maior das notas entre P1 e P2. Neste caso, o aluno é aprovado se a média
final for maior ou igual a 5.0.
Escreva um programa em C que leia inicialmente as duas notas de um aluno, fornecidas pelo usuário
via teclado. Se as notas não forem suficientes para o aluno passar direto, o programa deve capturar a nota da
terceira prova, também fornecida via teclado. Como saída, o programa deve imprimir a média final do aluno,
seguida da mensagem “Aprovado” ou “Reprovado”.

2. REPETIÇÃO Faça um programa em C que leia vários conjuntos de três valores reais e mostre para cada
conjunto: sua soma, seu produto e sua média. O programa encerra quando não entrar um conjunto com seus
valores em ordem crescente.

3. VETORES Faça um programa em C que:
a. Leia um vetor de inteiros de tamanho 5;
b. Inverta e imprima este vetor (ex: o vetor 1 7 3 4 2 vira 2 4 3 7 1);
c. Ordene e imprima este vetor em ordem decrescente;
d. Calcule e imprima:
i. O maior valor do vetor;
ii. O menor valor do vetor;
iii. A média de valores do vetor;
iv. A quantidade de valores que são maiores do que a média de valores calculada no item iii.
Cada um dos itens acima deve ser uma função separada.

4. MATRIZES Faça um programa em C que armazene numa matriz de inteiros (de tamanho m x 6) os seguintes
dados COVID referentes a m municípios:
a. A primeira coluna guarda o código do município;
b. A segunda coluna guarda a quantidade de habitantes do município;
c. A terceira coluna guarda o total de casos confirmados;
d. A quarta coluna guarda o total de óbitos;
e. A quinta coluna guarda a incidência de casos a cada 100 mil habitantes;
f. A sexta coluna guarda a mortalidade a cada 100 mil habitantes.

Exemplo: um município com 283 mil habitantes, 52 mil casos e 850 óbitos, tem uma incidência de 18374
casos por 100 mil habitantes e uma mortalidade de 300 óbitos por 100 mil habitantes.
Faça um programa em C que:
a. Leia e preencha as quatro primeiras colunas da matriz;
b. Calcule e armazene as duas últimas colunas da matriz;
c. Imprima toda a matriz;
d. Mostre qual o código do município que tem a maior mortalidade;
e. Mostre qual o código do município que tem a maior incidência de casos.
Cada um dos itens acima deve ser uma função separada.

5. STRUCTS Em uma pesquisa de campo, uma editora solicitou os seguintes dados para os entrevistados: idade
e quantidade de livros que leu no ano de 2023. Faça um programa que leia os dados de 5 usuários. Depois,
calcule e imprima:
a. A quantidade total de livros lidos pelos entrevistados menores de 18 anos;
b. A média de livros lidos pelos entrevistados.
Deve ser usada a seguinte struct:
struct usuario
{
int idade;
int qtdade;
};
typedef struct usuario Usuario;

Os dados devem ser armazenados em um vetor de usuários. O programa deve ser estruturado nas seguintes
funções:

void leVetor (int tamanho, Usuario* vet);

//esta funcao recebe o tamanho do vetor e o endereço do primeiro elemento do vetor; preenche o vetor com

dados digitados pelo usuário

int calculaQtidadeLivros (int tamanho, Usuario* vet);

// esta função recebe o tamanho do vetor e o endereco do primeiro elemento do vetor; calcula a quantidade total
de livros lidos pelos entrevistados menores de 18 anos, e retorna esta quantidade para o main

float calculaMedia (int tamanho, Usuario* vet);

// esta função recebe o tamanho do vetor e o endereco do primeiro elemento do vetor; calcula a média de livros

lidos pelos entrevistados e retorna esta quantidade para o main.

Ao final, o main mostra na tela os valores calculados.

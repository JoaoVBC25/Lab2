#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//Inicializa a lista vazia
Aluno* alunoVazio(void)
{
    return NULL;
}

//Inicializa a lista vazia
Professor* professorVazio(void)
{
    return NULL;
}

//Inicializa a lista vazia
Projeto* projetoVazio(void)
{
    return NULL;
}

//Inicializa a lista vazia
Vinculo* vinculoVazio(void)
{
    return NULL;
}

//Define todos os dados necessarios para a criaçao do próximo nó
void alunoDados(int* matricula, int* telefone, char* nome)
{
    int m, t;
    char n[50];
    printf("Insira o numero de matricula do aluno: ");
    scanf(" %d", &m);
    printf("Insira o numero de telefone do aluno: ");
    scanf(" %d", &t);
    printf("Insira o nome do aluno: ");
    scanf(" ");
    fgets(n, 20, stdin);
    *matricula = m;
    *telefone = t;
    strcpy(nome, n);
}

//Define todos os dados necessarios para a criaçao do próximo nó
void professorDados(int* codigo, char* departamento, char* nome)
{
    int c;
    char n[20], d[20];
    printf("Insira o codigo do professor: ");
    scanf(" %d", &c);
    printf("Insira o departamento: ");
    scanf(" ");
    fgets(d, 20, stdin);
    printf("Insira o nome do professor: ");
    scanf(" ");
    fgets(n, 20, stdin);
    *codigo = c;
    strcpy(departamento, d);
    strcpy(nome, n);
}

//Define todos os dados necessarios para a criaçao do próximo nó
void projetoDados(int* codigo, char* descricao, char* tipo, float* orcamento, float* orcamentoAtual, int* codigoProfessor)
{
    int c, cp;
    float o, oa;
    char t[20], d[100];
    printf("Insira o codigo do projeto: ");
    scanf(" %d", &c);
    printf("Insira o orcamento do projeto: ");
    scanf(" %f", &o);
    oa = o;
    printf("Insira a descricao do projeto: ");
    scanf(" ");
    fgets(d, 100, stdin);
    printf("Insira o tipo do projeto(ensino, pesquisa, extensao): ");
    scanf(" ");
    fgets(t, 20, stdin);
    printf("Insira o codigo do professor associado ao projeto: ");
    scanf(" %d", &cp);
    *codigo = c;
    *orcamento = o;
    *orcamentoAtual = oa;
    *codigoProfessor = cp;
    strcpy(descricao, d);
    strcpy(tipo, t);
}

//Define todos os dados necessarios para a criaçao do próximo nó
void vinculoDados(float* bolsa, int* matricula, int* codigo)
{
    float b;
    int m, c;
    printf("Insira a matricula do aluno a ser vinculado: ");
    scanf(" %d", &m);
    printf("Insira o codigo do projeto a ser vinculado: ");
    scanf(" %d", &c);
    printf("Insira o valor da bolsa desejada: ");
    scanf(" %f", &b);
    *codigo = c;
    *matricula = m;
    *bolsa = b;
}
//Cria um novo nó na lista com os dados ja inseridos pelo usuario
Aluno* cadastrarAluno(Aluno* a, int m, int t, char* n)
{
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    novo->matricula = m;
    novo->telefone = t;
    strcpy(novo->nome, n);
    novo->prox = a;
    return novo;
}

//Cria um novo nó na lista com os dados ja inseridos pelo usuario
Professor* cadastrarProfessor(Professor* p, int c, char* n, char* d)
{
    Professor* novo = (Professor*) malloc(sizeof(Professor));
    novo->codigo = c;
    strcpy(novo->nome, n);
    strcpy(novo->departamento, d);
    novo->prox = p;
    return novo;
}

//Cria um novo nó na lista com os dados ja inseridos pelo usuario
Projeto* cadastrarProjeto(Projeto* proj, Professor* prof, int c, char* t, float orca, float orcaA, char* d, int cp)
{
    Projeto* novo = (Projeto*) malloc(sizeof(Projeto));
    Professor* p = prof;
    novo->codigo = c;
    novo->orcamento = orca;
    novo->orcamentoAtual = orcaA;
    strcpy(novo->tipo, t);
    strcpy(novo->descricao, d);
    while(p != NULL && p->codigo != cp)
    {
        p = p->prox;
    }
    //Checa se foi encontrado um professor com o codigo fornecido
    if(p == NULL)
    {
        printf("\nNenhum professor com o codigo fornecido foi encontrado\n");
        return proj;
    }
    novo->professor = p;
    novo->prox = proj;
    return novo;
}

//Cria um novo nó na lista com os dados ja inseridos pelo usuario
Vinculo* criarVinculo(Vinculo* v, Aluno* a, Projeto* p, int matricula, int codigo, float b)
{
    Vinculo* novo = (Vinculo*) malloc(sizeof(Vinculo));

    //Checa se a orçamento disponivel no projeto para pagar 12 meses da bolsa
    if((p->orcamentoAtual - 12 * b) >= 0)
    {
       Aluno* p1 = a;
       while(p1 != NULL && p1->matricula != matricula)
       {
         p1= p1->prox;
       }
       //Checa se foi encontrado um aluno com a matricula fornecida
       if(p1 == NULL)
       {
        printf("\nNenhum aluno com o numero de matricula fornecido foi encontrado\n");
        return v;
       }
       novo->aluno = p1;
       Projeto* p2 = p;
       while(p2 != NULL && p2->codigo != codigo)
       {
         p2 = p2->prox;
       }
       //Checa se foi encontrado um professor com o codigo fornecido
       if(p2 == NULL)
       {
        printf("\nNenhum professor com o codigo fornecido foi encontrado\n");
        return v;
       }
       novo->projeto = p2;
       novo->bolsa = b;
       novo->prox = v;
       p2->orcamentoAtual = p2->orcamentoAtual - b * 12;
       return novo;
    }
    //Retorna a lista original caso nao acha orçamento suficiente
    printf("Nao a orcamento disponivel para pagar a bolsa do aluno durante 12 meses\n");
    return v;
}

//Exclui o vinculo definido pelo usuario
Vinculo* excluirVinculo(Vinculo* vinculo)
{
    int matricula, codigo;
    float bolsaRestante;
    printf("Insira a matricula do aluno associado ao vinculo que deseja excluir: ");
    scanf(" %d", &matricula);
    printf("Insira o codigo do projeto associado ao vinculo que deseja excluir: ");
    scanf(" %d", &codigo);
    printf("Insira a quantidade de meses em que a bolsa nao vai mais ser paga: ");
    scanf(" %f", &bolsaRestante);
    Vinculo* p = vinculo;
    Vinculo* ant = NULL;
    while(p != NULL && (p->aluno->matricula != matricula || p->projeto->codigo != codigo))
    {   
        ant = p;
        p = p->prox;
    }
    //Checa se foi encontrado o vinculo
    if(p == NULL)
    {
        return vinculo;
    }
    //Checa se havia somento um vinculo na lista
    if(ant == NULL)
    {
        vinculo = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }
    //Retorna o valor restante da bolsa
    bolsaRestante = bolsaRestante * p->bolsa;
    p->projeto->orcamentoAtual = p->projeto->orcamentoAtual + bolsaRestante;
    //Libera o vinculo
    free(p);
    return vinculo;
}

//Lista todos os alunos ja cadastrados
void listarAlunos(Aluno* aluno)
{
    Aluno* p;
    int contador = 0;
    for(p = aluno; p != NULL; p = p->prox)
    {
        contador ++;
        printf("Aluno %d\n", contador);
        printf("    Nome: %s", p->nome);
        printf("    Matricula: %d\n", p->matricula);
        printf("    Telefone: %d\n", p->telefone);
    }
}

//Lista todos os professores ja cadastrados
void listarProfessores(Professor* professor)
{
    Professor* p;
    int contador = 0;
    for(p = professor; p != NULL; p = p->prox)
    {
        contador ++;
        printf("\nProfessor %d:\n", contador);
        printf("    Nome: %s", p->nome);
        printf("    Codigo: %d\n", p->codigo);
        printf("    Departamento: %s", p->departamento);
    }
}

//Lista todos os projetos ja cadastrados
void listarProjeto(Projeto* projeto)
{
    Projeto* p;
    int contador = 0;
    for(p = projeto; p != NULL; p = p->prox)
    {
        contador ++;
        printf("Projeto %d:\n", contador);
        printf("    Codigo: %d\n", p->codigo);
        printf("    Descricao: %s", p->descricao);
        printf("    Tipo: %s", p->tipo);
        printf("    Orcamento: %.2f\n", p->orcamento);
        printf("    Orcamento atual: %.2f\n", p->orcamentoAtual);
        printf("    Professor responsavel: %s", p->professor->nome);
    }
}

//Lista todos os vinculos ja criados
void listarVinculo(Vinculo* vinculo)
{
    Vinculo* p;
    int contador = 0;
    for(p = vinculo; p != NULL; p = p->prox)
    {
        contador ++;
        printf("Vinculo %d:\n", contador);
        printf("    Aluno vinculado: %s", p->aluno->nome);
        printf("    Codigo do projeto vinculado: %d\n", p->projeto->codigo);
        printf("    Bolsa desejada: %.2f\n", p->bolsa);
    }
}

//Ao final do programa lista todos os projetos, seus dados e os alunos vinculados aos mesmos(caso haja algum)
void finalPrograma(Projeto* projeto, Vinculo* vinculo)
{
    Projeto* p1;
    Vinculo* p2;
    int contador = 0;
    int alunoPresente = 0;
    for(p1 = projeto; p1 != NULL; p1 = p1->prox)
    {
        contador ++;
        printf("\nProjeto %d:\n", contador);
        printf("    Codigo: %d\n", p1->codigo);
        printf("    Descricao: %s", p1->descricao);
        printf("    Tipo: %s", p1->tipo);
        printf("    Orcamento: %.2f\n", p1->orcamento);
        printf("    Orcamento atual: %.2f\n", p1->orcamentoAtual);
        printf("    Professor responsavel: %s", p1->professor->nome);
        for(p2 = vinculo; p2 != NULL; p2 = p2->prox)
        {
            if(p2->projeto->codigo == p1->codigo)
            {
                printf("    Aluno vinculado: %s", p2->aluno->nome);
                alunoPresente ++;
            }
        }
        if(alunoPresente == 0)
        {
            printf("    Nao ha alunos vinculados ao projeto\n");
        }
        alunoPresente = 0;
    }
    exit(0);

}

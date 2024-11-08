
//Definição de todas as estruturas usadas ao longo do programa

struct aluno
{
    int matricula;
    char nome[50];
    int telefone;
    struct aluno* prox;
};
typedef struct aluno Aluno;

struct professor
{
    int codigo;
    char nome[50];
    char departamento[20];
    struct professor* prox;
};
typedef struct professor Professor;

struct projeto
{
    int codigo;
    char descricao[100];
    char tipo[20];
    float orcamento;
    float orcamentoAtual;
    struct projeto* prox;
    Professor* professor; 

};
typedef struct projeto Projeto;

struct vinculo
{
    Aluno* aluno;
    Projeto* projeto;
    float bolsa;
    struct vinculo* prox;
};
typedef struct vinculo Vinculo;

//Prototipo das funções usadas no arquivo lista.c
Aluno* alunoVazio(void);
Professor* professorVazio(void);
Projeto* projetoVazio(void);
Vinculo* vinculoVazio(void);
Aluno* cadastrarAluno(Aluno* a, int m, int t, char* n);
Professor* cadastrarProfessor(Professor* p, int c, char* n, char* d);
Projeto* cadastrarProjeto(Projeto* proj, Professor* prof, int c, char* t, float orca, float orcaA, char* d, int cp);
Vinculo* criarVinculo(Vinculo* v, Aluno* a, Projeto* p, int matricula, int codigo, float b);
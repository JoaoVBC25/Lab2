#include "lista.c"

//Prototipo das funções usadas no arquivo menu.c
void menu(Aluno* aluno, Professor* professor, Projeto* projeto, Vinculo* vinculo);
void alunoDados(int* matricula, int* telefone, char* nome);
void professorDados(int* codigo, char* departamento, char* nome);
void projetoDados(int* codigo, char* descricao, char* tipo, float* orcamento, float* orcamentoAtual, int* codigoProfessor);
void vinculoDados(float* bolsa, int* matricula, int* codigo);
Vinculo* excluirVinculo(Vinculo* vinculo);
void listarAlunos(Aluno* aluno);
void listarProfessores(Professor* aluno);
void listarProjetos(Projeto* aluno);
void listarVinculos(Vinculo* aluno);

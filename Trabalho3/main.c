#include <stdio.h>
#include <stdlib.h>
#include "menu.c"

//Inicializa as listas vazias e chama a função menu
int main()
{
    Aluno* aluno;
    Professor* professor;
    Projeto* projeto;
    Vinculo* vinculo;
    
    //Inicializa as listas vazias
    aluno = alunoVazio();
    professor = professorVazio();
    projeto = projetoVazio();
    vinculo = vinculoVazio();
    menu(aluno, professor, projeto, vinculo);
}
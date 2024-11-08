#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

//Permite o usuario definir as ações que deseja realizar e chama as funções necessarias
void menu(Aluno* aluno, Professor* professor, Projeto* projeto, Vinculo* vinculo)
{
    int escolha;
    int matricula, telefone, codigo, codigoProfessor;
    float orcamento, orcamentoAtual, bolsa;
    char nome[20], departamento[20], descricao[20], tipo[20];
    while(1)
    {
        printf("\nDigite o valor correspondente ao que deseja realizar\n 1 - Cadastro \n 2 - Vinculo\n 3 - Listar\n 4 - Finalizar\n");
        scanf("%d", &escolha);

        //Permite o usuario criar novos nós nas listas Aluno, Professor e Projeto
        if(escolha == 1)
        {
            printf("\nDigite o valor correspondente ao que deseja cadastrar: \n 1 - Aluno \n 2 - Professor\n 3 - Projeto\n");
            scanf("%d", &escolha);
            switch (escolha)
            {
            case 1:
                alunoDados(&matricula, &telefone, nome);
                aluno = cadastrarAluno(aluno, matricula, telefone, nome);
                break;
            case 2:
                professorDados(&codigoProfessor, departamento, nome);
                professor = cadastrarProfessor(professor, codigoProfessor, nome, departamento);
                break;
            case 3:
                projetoDados(&codigo, descricao, tipo, &orcamento, &orcamentoAtual, &codigoProfessor);
                projeto = cadastrarProjeto(projeto, professor, codigo, tipo, orcamento, orcamentoAtual, descricao, codigoProfessor);
                break;
            }
            
        }

        //Permite o usuario criar e excluir vinculos
        else if(escolha == 2)
        {
            printf("\nDigite o valor correspondente ao que deseja realizar: \n 1 - Criar vinculo \n 2 - Excluir vinculo\n");
            scanf("%d", &escolha);
            switch (escolha)
            {
            case 1:
                vinculoDados(&bolsa, &matricula, &codigo);
                vinculo = criarVinculo(vinculo,aluno, projeto, matricula, codigo, bolsa);
                break;
            case 2:
                vinculo = excluirVinculo(vinculo);

                break;
            }
        }

        //Permite o usuario exibir as listas por completo
        else if(escolha == 3)
        {
            printf("\nDigite o valor correspondente ao que deseja listar: \n 1 - Aluno \n 2 - Professor\n 3 - Projeto\n 4 - Vinculo\n");
            scanf(" %d", &escolha);
            switch (escolha)
            {
            case 1:
                listarAlunos(aluno);
                break;
            case 2:
                listarProfessores(professor);
                break;
            case 3:
                listarProjeto(projeto);
                break;
            case 4:
                listarVinculo(vinculo);
                break;
            }
        }

        //Ao final do programa lista todos os projetos, seus dados e os alunos vinculados aos mesmos(caso haja algum)
        else if(escolha == 4)
        {
            finalPrograma(projeto, vinculo);
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "utilidades.h"

#define TAM 2

typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;

 typedef struct {
    int ativo;
    char cpf[12];
    char nome[100];
    char sexo;
    int matricula;
    Data nascimento;
} Dados;

int menuListatem();
int menuInicial();
int menuAluno();
void inserirAluno(Dados listaAlunos[],int qtdAlunos);
void listarAlunos(int qtdAlunos, Dados listarAlunos[]);
void atualizaAluno(int indice,Dados listaAlunos[]);

void inserirAluno(Dados listaAlunos[],int qtdAlunos){
    limparBuffer();
    printf("\nDigite a matricula do aluno: ");
    scanf("%d",&listaAlunos[qtdAlunos].matricula);
    limparBuffer();
    printf("\nDigite o nome do aluno: ");
    fgets(listaAlunos[qtdAlunos].nome,100,stdin);
    printf("\nDigite o CPF do aluno: ");
    fgets(listaAlunos[qtdAlunos].cpf,12,stdin);
        //validação do cpf
    getchar();
    printf("\nDigite o sexo do aluno (M/F): ");
    scanf("%c",&listaAlunos[qtdAlunos].sexo);
    printf("\nDigite o dia de nascimento: ");
    scanf("%d",&listaAlunos[qtdAlunos].nascimento.dia);
    printf("\nDigite o mes de nascimento: ");
    scanf("%d",&listaAlunos[qtdAlunos].nascimento.mes);
    printf("\nDigite o ano de nascimento: ");
    scanf("%d",&listaAlunos[qtdAlunos].nascimento.ano);
    listaAlunos[qtdAlunos].ativo = 1;
}

void atualizaAluno(int indice,Dados listaAlunos[]){
    limparBuffer();
    printf("\nDigite a nova matricula do aluno: ");
    scanf("%d",&listaAlunos[indice].matricula);
    limparBuffer();
    printf("\nDigite o novo nome do aluno: ");
    fgets(listaAlunos[indice].nome,100,stdin);
    printf("\nDigite o novo CPF do aluno: ");
    fgets(listaAlunos[indice].cpf,12,stdin);
        //validação do cpf
    getchar();
    printf("\nDigite o novo sexo do aluno (M/F): ");
    scanf("%c",&listaAlunos[indice].sexo);
    printf("\nDigite o novo dia de nascimento: ");
    scanf("%d",&listaAlunos[indice].nascimento.dia);
    printf("\nDigite o novo mes de nascimento: ");
    scanf("%d",&listaAlunos[indice].nascimento.mes);
    printf("\nDigite o novo ano de nascimento: ");
    scanf("%d",&listaAlunos[indice].nascimento.ano);
}

int menuListatem(){
    int opcaoLista;
    printf("\n-----Menu de Listagem-----\n");
    printf("\n1- Lista de Alunos");
    printf("\n0 - Voltar");
    printf("\nEscolha uma opcao: ");
    scanf("%d",&opcaoLista);
    return opcaoLista;
}

int menuInicial(){
    int opcao;
    printf("\n--------MENU--------\n");
    printf("\n0 - Sair\n");
    printf("\n1 - Cadastrar aluno");
    printf("\n2 - Cadastrar professor");
    printf("\n3 - Cadastrar disciplina");
    printf("\n4 - Pesquisar Listas");
    printf("\nEscolha um opcao:\n");
    scanf("%d",&opcao);
    return opcao;
}

int menuAluno(){
    int opcaoAluno;
    printf("\n--------MENU--------\n");
    printf("\n0 - Sair\n");
    printf("\n1 - Inserir aluno");
    printf("\n2 - Excluir aluno");
    printf("\n3 - Atualizar aluno");
    printf("\nEscolha um opcao:\n");
    scanf("%d",&opcaoAluno);
    return opcaoAluno;
}

void listarAlunos(int qtdAlunos, Dados listaAlunos[]){
    if (qtdAlunos == 0){
        printf("Nao existem alunos cadastrados\n");
    } else {
        printf("Listando os alunos...");
        for(int i = 0;i < qtdAlunos;i++){
            if(listaAlunos[i].ativo == 1){
                printf("\nMATRICULA: %d",listaAlunos[i].matricula);
                printf("\nNome: %s",listaAlunos[i].nome);
                printf("\nCPF: %s\n",listaAlunos[i].cpf);
                printf("\nData de Nascimento: %d / %d / %d\n",listaAlunos[i].nascimento.dia,listaAlunos[i].nascimento.mes,listaAlunos[i].nascimento.ano);
            }
        }
    }
}

int main(){

    Dados listaAlunos[TAM];

    int qtdAlunos = 0;
    int sair = 0;
    int opcao;

    while (!sair){
        opcao = menuInicial();
        if (!valida_opcaoInicial(opcao)){
            printf("OPCAO INVALIDA\n");
        }
        switch (opcao){

            case 0:{
                sair = 1;
                break;
            }

            case 1:{
                int sairAluno = 0;

                while (!sairAluno){
                    int opcaoAluno = menuAluno();
                    if (!valida_opcaoAluno(opcaoAluno)){
                        printf("OPCAO INVALIDA\n");
                    }
                    switch(opcaoAluno){

                        case 0:{
                            sairAluno = 1;
                            break;
                        }

                        case 1:{
                            if (qtdAlunos < TAM){
                                inserirAluno(listaAlunos,qtdAlunos);
                                qtdAlunos++;
                            } else {
                                printf("Lista de Alunos Completa\n");
                            }
                            break;
                        }

                        case 2:{
                            if (qtdAlunos == 0){
                                printf("Sem alunos cadastrados!");
                            } else {
                                listarAlunos(qtdAlunos,listaAlunos);

                                int matricula;
                                printf("Digite a matricula do aluno que deseja excluir: ");
                                scanf("%d",&matricula);

                                if (matricula < 0){
                                    printf("Matricula invalida");
                                }

                                int indice = -1;
                                for (int i = 0; i < qtdAlunos; i++){
                                    if(matricula == listaAlunos[i].matricula && listaAlunos[i].ativo == 1){
                                        indice = i;
                                    }
                                }
                                if (indice == -1){
                                    printf("Matricula nao encontrada");
                                } else {
                                    listaAlunos[indice].ativo = 0;
                                }
                            }
                            break;
                        }

                        case 3:{
                            listarAlunos(qtdAlunos,listaAlunos);

                            int matricula;
                            printf("Digite a matricula do aluno que deseja atualizar: ");
                            scanf("%d",&matricula);

                            if (matricula < 0){
                                printf("Matricula invalida");
                            }

                            int indice = -1;
                            for (int i = 0; i < qtdAlunos; i++){
                                if(matricula == listaAlunos[i].matricula){
                                    indice = i;
                                }
                            }

                            if (indice == -1){
                                printf("Matricula nao encontrada");
                            } else {
                                atualizaAluno(indice,listaAlunos);
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 4:{
                int sairLista = 0;

                while (!sairLista){
                    int opcaoLista = menuListatem();

                    switch(opcaoLista){

                        case 0:{
                            sairLista = 1;
                            break;
                        }

                        case 1:{
                            listarAlunos(qtdAlunos,listaAlunos);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

    return 0;
}
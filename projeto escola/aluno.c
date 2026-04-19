#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


#define TAM 5
typedef struct data{
    int dia;
    int mes;
    int ano;
} Data;

 typedef struct {
    char cpf[12];
    char nome[50];
    char sexo;
    char matricula[10];
    Data nascimento;
} Dados;

void menuInicial();
void menuAluno();
void inserirAluno(Dados listaAlunos[],int qtdAlunos);

void inserirAluno(Dados listaAlunos[],int qtdAlunos){
    printf("\nDigite a matricula do aluno: ");
    fgets(listaAlunos[qtdAlunos].matricula,10,stdin);
    printf("\nDigite o nome do aluno: ");
    fgets(listaAlunos[qtdAlunos].nome,50,stdin);
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
}

void menuInicial(){
    printf("--------MENU--------");
    printf("\n0 - Sair\n");
    printf("\n1 - Cadastrar aluno");
    printf("\n2 - Cadastrar professor");
    printf("\n3 - Cadastrar disciplina");
    printf("\n4 - Pesquisar Listas");
    printf("\nEscolha um opcao:\n");
}

void menuAluno(){
    printf("--------MENU--------");
    printf("\n0 - Sair\n");
    printf("\n1 - Inserir aluno");
    printf("\n2 - Atualizar aluno");
    printf("\n3 - Excluir aluno");
    printf("\nEscolha um opcao:\n");
}

int main(){

    Dados listaAlunos[TAM];

    int qtdAlunos = 0;
    int sair = 0;
    int opcao;

    while (sair == 0){
    menuInicial();
    scanf("%d",&opcao);
        switch (opcao){
            case 0:{
                //sair do programa
                sair = 1;
                break;
            }
            case 1:{
                menuAluno(); //menu aluno
                int opcaoAluno;
                scanf("%d",&opcaoAluno);
                switch(opcaoAluno){
                    case 0:{//voltar
                    break;
                    }
                    case 1:{ //1-cadastrar aluno
                        if (qtdAlunos < TAM){
                            getchar();
                            inserirAluno(listaAlunos,qtdAlunos);
                            qtdAlunos++;
                        } else {
                            printf("Lista de Alunos Completa");
                        }
                    break;
                    }
                    case 2:{//2-Excluir Aluno
                    break;
                    }
                    case 3:{//3-Atualizar Aluno
                    printf("Listando os alunos...");
                        for(int i = 0;i < qtdAlunos;i++){
                            printf("\nMATRICULA: %s",listaAlunos[i].matricula);
                            printf("\nNome: %s",listaAlunos[i].nome);
                            printf("\nCPF: %s\n",listaAlunos[i].cpf);
                            printf("\nData de Nascimento: %d / %d / %d\n",listaAlunos[i].nascimento.dia,listaAlunos[i].nascimento.mes,listaAlunos[i].nascimento.ano);
                        }
                        //Escolhendo o livro para atualizar
                    }
                }
            break;
            }
            case 4:{
                int opcaoLista;
                printf("\n-----Menu de Listagem-----\n");
                printf("\n1- Lista de Alunos");
                printf("\n0 - Voltar");
                printf("\nEscolha uma opcao: ");
                scanf("%d",&opcaoLista);
                switch(opcaoLista){
                    case 0:{
                        break;//voltar para o menu;
                    }
                    case 1:{
                        //listando os alunos
                        printf("Listando os alunos...");
                        for(int i = 0;i < qtdAlunos;i++){
                            printf("\nMATRICULA: %s",listaAlunos[i].matricula);
                            printf("\nNome: %s",listaAlunos[i].nome);
                            printf("\nCPF: %s\n",listaAlunos[i].cpf);
                            printf("\nData de Nascimento: %d / %d / %d\n",listaAlunos[i].nascimento.dia,listaAlunos[i].nascimento.mes,listaAlunos[i].nascimento.ano);
                        }
                    break;
                    }
                }
            }
        }
    }
}

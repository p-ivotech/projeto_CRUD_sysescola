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
    char matricula[11];
    Data nascimento;
} Dados;

int main(){

    Dados listaAlunos[TAM];

    int qtdAlunos = 0;
    int sair = 0;
    int opcao;

    while (sair == 0){
        printf("--------MENU--------");
        printf("\nEscolha um opcao:\n");
        printf("\n0 - Sair\n");
        printf("\n1 - Cadastrar aluno\n");
        printf("\n2 - Cadastrar professor\n");
        printf("\n3 - Cadastrar disciplina\n");
        printf("\n4 - Pesquisar Listas\n");
        scanf("%d",&opcao);

        switch (opcao){
            case 0:{
                //sair do programa
                sair = 1;
                break;
            }
            case 1:{
                //cadastrar aluno
                if (qtdAlunos == TAM){
                    printf("Lista de Alunos Completa");
                } else {
                    int i;
                    for(i = 0; i < TAM; i++)
                        printf("Digite a matricula do aluno:");
                        fgets(listaAlunos[i].matricula,11,stdin);
                }
                break;
            }
        }
    }


}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "aluno.h"

bool valida_opcaoInicial(int opcao){
    return (opcao >= 0 && opcao <= 4);
}

bool valida_opcaoAluno(int opcao){
    return (opcao >= 0 && opcao <= 3);
}

bool valida_opcaoLista(int opcao){
    return (opcao >= 0 && opcao <=5);
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validaMatricula(int qtdAlunos,Dados listaAlunos[],int matriculaNova){
    for (int i = 0;i < qtdAlunos;i++){
        if(listaAlunos[i].matricula == matriculaNova){
            return -1;
        }
    }
    return 0;
}

int validaSexo(char sexo){
    if (sexo == 'M' || sexo == 'F'){
        return 1;
    } else {
        return 0;
    }
}


#ifndef ALUNO_H
#define ALUNO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

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

int validacaoData(Dados listaAlunos, int qtdAlunos);


int validacaoDiasMesAno(Dados listaAlunos, int qtdAlunos){
    if (listaAlunos[qtdAlunos].nascimento.dia <= 0){
        return 1;
    } else {
        return 0;
    }//validacao dia

    if (listaAlunos[qtdAlunos].nascimento.mes <= 0 || listaAlunos[qtdAlunos].nascimento.mes > 12){
        return 1;
    } else {
        return 0;
    }//validacao mes

    if (listaAlunos[qtdAlunos].nascimento.ano <= 0){
        return 1;
    } else {
        return 0;
    }//validacao ano
}

int validaDatas

#endif

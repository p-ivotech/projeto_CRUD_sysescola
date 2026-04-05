#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct {
    char *nome;
    char *cpf;
    char *matricula;
    data *data;
    int qtdAlunos;
}dados;

dados *novo_aluno(char *nome, char *matricula,char *cpf, data *data){
    dados *novo = malloc(sizeof(dados));
    novo->nome = nome;
    novo->matricula = matricula;
    novo->cpf = cpf;
    novo->data = NULL;
    novo->qtdAlunos = qtdAlunos;

    return novo;
}

data *nova_data(int dia,int mes,int ano){
    data *nova = malloc(sizeof(data));
    nova->dia = dia;
    nova->mes = mes;
    nova->ano = ano;

    return nova;
}


int main(){
    int qtdAlunos = 0;


    dados *aluno = malloc(sizeof(dados));
    aluno = novo_Aluno(char *nome, char *matricula,char *cpf, data *data, int qtdAlunos);
    qtdAlunos++;


}

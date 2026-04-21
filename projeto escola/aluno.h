#ifndef ALUNO_H
#define ALUNO_H

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

void inserirAluno(Dados listaAlunos[],int qtdAlunos);
void listarAlunos(int qtdAlunos, Dados listarAlunos[]);
void atualizaAluno(int indice,Dados listaAlunos[]);
void listarAlunos_sexo(int qtdAlunos, Dados listaAlunos[],char sexo);
int menuAluno();

#endif
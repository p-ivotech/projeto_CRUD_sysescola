#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdbool.h>
#include "aluno.h"

bool valida_opcaoAluno(int opcao);
bool valida_opcaoInicial(int opcao);
bool valida_opcaoLista(int opcao);
int validaMatricula(int qtdAlunos,Dados listaAlunos[],int matriculaNova);
int validaSexo(char sexo);
void limparBuffer();

#endif
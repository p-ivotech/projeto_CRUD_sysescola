#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

bool valida_opcaoInicial(int opcao){
    return (opcao >= 0 && opcao <= 4);
}

bool valida_opcaoAluno(int opcao){
    return (opcao >= 0 && opcao <= 3);
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "tabuleiro.c"
#include "hospedes.c"
#include "validacao.c"
#include "ajudante.c"
#include "fases.c"
#include<locale.h>


int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Esse jogo basea-se em inserir hóspedes dentro de quartos válidos. \n");
    printf("Algumas regras antes: \n\n");
    printf("Você receberá os valores para inserir nos quartos, V são os quartos válidos \n");
    printf("E I são os quartos inválidos\n");
    printf("Os ratos (R) não podem ficar ao lado de gatos (G) \n");
    printf("Os cães (C) não pode ficar ao lado de ossos (O) \n");
    printf("Os gatos (G) não podem ficar ao lado de cães (C) \n");
    printf("O quiejo (Q) não pode ficar ao lado dos ratos (R) \n\n");
    printf("Essa é a primeira fase.\n");
    printf("\n");
    primeiraFase();
    printf("Essa é a segunda fase.\n");
    segundaFase();
    printf("Essa é a terceira fase. \n");
    terceiraFase();
    printf("Essa é a quarta fase. \n");
    quartaFase();
    printf("Essa é a quinta fase. \n");
    quintaFase();
}



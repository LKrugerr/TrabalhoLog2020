#include<stdio.h>
#include<stdlib.h>

int buscarLinha() {
    printf("Insira a linha:\n");
    int linha = 0;
    scanf("%d", &linha);
    return linha;
}//Pede para o usuário inserir a linha para inserir

int buscarColuna() {
    printf("Insira a coluna:\n");
    int coluna = 0;
    scanf("%d", &coluna);
    system("cls");
    return coluna;
}//Pede para o usuario inserir a coluna 

int buscarHospede() {
    printf("Insira o Hospede:\n");
    char hospede;
    scanf(" %c", &hospede);
    system("cls");
    return hospede;
}//Pede para o usuário o hospede que deseja inserir
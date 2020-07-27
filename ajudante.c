#include<stdio.h>
#include<stdlib.h>

int buscarLinha() {
    printf("Insira a linha:\n");
    int linha = 0;
    scanf("%d", &linha);
    return linha;
}

int buscarColuna() {
    printf("Insira a coluna:\n");
    int coluna = 0;
    scanf("%d", &coluna);
    system("cls");
    return coluna;
}

int buscarHospede() {
    printf("Insira o Hospede:\n");
    char hospede;
    scanf(" %c", &hospede);
    system("cls");
    return hospede;
}
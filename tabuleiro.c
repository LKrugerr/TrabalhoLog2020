#include<stdio.h>
#include "hospedes.c"

void desenharEspacoInicial() {
    printf(" ");
}

void desenharCabecalho(int coluna) {
    int i = 0, 
        j = 0;
    
    for (i=0; i < coluna; i++) {
        printf(" %d", i); 
    }

    printf("\n");
}

void desenharMatrizTabuleiro(int linha, int coluna, char tabuleiro[][coluna]) {
    int i = 0, 
        j = 0;

    for (i = 0; i < linha; i++) {
        printf("%d ", i);
        for (j = 0;j < coluna;j++) {
            printf("%c ", tabuleiro[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
}

void desenharTabuleiro(int linha, int coluna, char tabuleiro[][coluna]) {

    desenharEspacoInicial();
    desenharCabecalho(coluna);  
    desenharMatrizTabuleiro(linha, coluna, tabuleiro);

}

void colocarHospedeNoTabuleiro(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) { 
    tabuleiro[linha][coluna] = hospede;
}

void removerHospedeDosHospedesParaAlocar(char hospedeSelecionado, int tamanhoHospedesParaAlocar, char hospedesParaAlocar[tamanhoHospedesParaAlocar]) {
    int i = 0;

    for (int i = 0; i < tamanhoHospedesParaAlocar; i++) {
        if(hospedesParaAlocar[i] == hospedeSelecionado) {
            hospedesParaAlocar[i] = Alocado;
            break;
        }
    }
}
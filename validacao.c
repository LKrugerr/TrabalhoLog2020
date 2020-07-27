#include<stdio.h>
#include<stdbool.h> 
#include <string.h>
#include "hospedes.c"

bool indiceValido(int linha, int coluna, int maximoLinhaTabuleiro, int maximoColunaTabuleiro) {
    bool valida = (linha <= maximoLinhaTabuleiro -1 && coluna <= maximoColunaTabuleiro -1) && (linha >= 0  && coluna >= 0);
    if(!valida) {
        printf("As cordenadas de linha e coluna estao fora do permitido no tabuleiro.\n");
    }
    return valida;
}

bool hospedeValido(char hospede) {
    bool valido = hospede == Cao
        || hospede == Rato
        || hospede == Gato
        || hospede == Osso
        || hospede == Queijo;

    if(!valido) {
        printf("Hospede invalido.\n");
    }
    return valido;
}

bool ratoAoLadoDoGato(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    
    bool jogadaInvalida = tabuleiro[linha][coluna] == Rato && hospede == Gato
        || tabuleiro[linha][coluna] == Gato && hospede == Rato;

    if(jogadaInvalida) {
        printf("Rato ao Lado do Gato\n");
    }

    return jogadaInvalida;
}

bool caoAoLadoDoOsso(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool jogadaInvalida = tabuleiro[linha][coluna] == Cao && hospede == Osso
        || tabuleiro[linha][coluna] == Osso && hospede == Cao;
    if(jogadaInvalida) {
        printf("Cao ao Lado do Osso!\n", tabuleiro[linha][coluna], hospede, linha, coluna);
    }
    return jogadaInvalida;
}

bool gatoAoLadoDoCao(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool jogadaInvalida = tabuleiro[linha][coluna] == Gato && hospede == Cao
                    || tabuleiro[linha][coluna] == Cao && hospede == Gato;
    if(jogadaInvalida) {
        printf("Gato ao Lado do Cao!\n");
    }
    return jogadaInvalida;
}

bool queijoAoLadoDoRato(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool jogadaInvalida = tabuleiro[linha][coluna] == Queijo && hospede == Rato
                    || tabuleiro[linha][coluna] == Rato && hospede == Queijo;
    if(jogadaInvalida) {
        printf("Queijo ao Lado do Rato!\n");
    }
    return jogadaInvalida;
}

bool validarEsquerda(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    return !caoAoLadoDoOsso(linha, coluna - 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !ratoAoLadoDoGato(linha, coluna - 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !gatoAoLadoDoCao(linha, coluna - 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !queijoAoLadoDoRato(linha, coluna - 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
}

bool validarDireita(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    return !caoAoLadoDoOsso(linha, coluna + 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !ratoAoLadoDoGato(linha, coluna + 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !gatoAoLadoDoCao(linha, coluna + 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !queijoAoLadoDoRato(linha, coluna + 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
}

bool validarCima(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    return !caoAoLadoDoOsso(linha - 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !ratoAoLadoDoGato(linha - 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !gatoAoLadoDoCao(linha - 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !queijoAoLadoDoRato(linha - 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
}

bool validarBaixo(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    return !caoAoLadoDoOsso(linha + 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !ratoAoLadoDoGato(linha + 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !gatoAoLadoDoCao(linha + 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !queijoAoLadoDoRato(linha + 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
}//Valida o caracter abaixo do inserido, linha+1 

bool hospedeAlocadoCorretamente(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool validoCima = false,
    validoBaixo = false,
    validoEsquerda = false,
    validoDireita = false;

    if(linha > 0) {
        validoCima = validarCima(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
    } else {
        validoCima = true;
    }

    if(linha < maximoLinhaTabuleiro - 1) {
        validoBaixo = validarBaixo(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
    } else {
        validoBaixo = true;
    }

    if(coluna > 0) {
        validoEsquerda = validarEsquerda(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
    } else {
        validoEsquerda = true;
    }

    if(coluna < maximoColunaTabuleiro - 1) {
        validoDireita = validarDireita(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
    } else {
        validoDireita = true;
    }

    return validoCima && validoBaixo && validoEsquerda && validoDireita;
}

bool posicaoValida(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool valida = tabuleiro[linha][coluna] != Indisponivel && tabuleiro[linha][coluna] == Disponivel;
    if(!valida) {
        printf("Espaço indisponível\n");
    }
    return valida;
}

bool podeAlocarHospede(char hospedeSelecionado, int tamanhoHospedesValidos, char hospedesValidos[tamanhoHospedesValidos]) { 
    bool podeAlocar = false;
    int i = 0;

    for (i = 0; i < tamanhoHospedesValidos; i++) {
        if(hospedesValidos[i] == hospedeSelecionado) {
            podeAlocar = true;
        }
    }
    
    return podeAlocar;
}

bool jogadaValida(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro], int tamanhoHospedesValidos, char hospedesQuePodemSerAlocados[tamanhoHospedesValidos]) {
    
    if(!indiceValido(linha, coluna, maximoLinhaTabuleiro, maximoColunaTabuleiro)) {
        return false;
    }

    if(!podeAlocarHospede(hospede, tamanhoHospedesValidos, hospedesQuePodemSerAlocados)) {
        printf("Não é possível alocar esse hospede");
        return false;
    }

    if(!hospedeValido(hospede)) {
        return false;
    }

    if(!posicaoValida(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)) {
        return false;
    }

    if(!hospedeAlocadoCorretamente(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)) {
        return false;
    }
    return true;
}

bool verificaSeJogoAcabou(int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool possuiEspacoDisponivel = false;
    int i, j = 0;

    for (i = 0; i < maximoLinhaTabuleiro; i++) {
        for (j = 0;j < maximoColunaTabuleiro;j++) {
            if(tabuleiro[i][j] == Disponivel) {
                possuiEspacoDisponivel = true;
            }
        }
    }

    return !possuiEspacoDisponivel;
}


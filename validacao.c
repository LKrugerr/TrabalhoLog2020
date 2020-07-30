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
}//Valida se as coordenadas para inserção estão dentro dos parâmetros ideais

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
}//Valida se o valor para hóspede é válido ou não

bool ratoAoLadoDoGato(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    
    bool jogadaInvalida = tabuleiro[linha][coluna] == Rato && hospede == Gato
        || tabuleiro[linha][coluna] == Gato && hospede == Rato;

    if(jogadaInvalida) {
        printf("Rato ao Lado do Gato\n");
    }

    return jogadaInvalida;
}//Verifica se as regras estão sendo seguidas

bool caoAoLadoDoOsso(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool jogadaInvalida = tabuleiro[linha][coluna] == Cao && hospede == Osso
        || tabuleiro[linha][coluna] == Osso && hospede == Cao;
    if(jogadaInvalida) {
        printf("Cao ao Lado do Osso!\n", tabuleiro[linha][coluna], hospede, linha, coluna);
    }
    return jogadaInvalida;
}//Verifica se as regras estão sendo seguidas

bool gatoAoLadoDoCao(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool jogadaInvalida = tabuleiro[linha][coluna] == Gato && hospede == Cao
                    || tabuleiro[linha][coluna] == Cao && hospede == Gato;
    if(jogadaInvalida) {
        printf("Gato ao Lado do Cao!\n");
    }
    return jogadaInvalida;
}//Verifica se as regras estão sendo seguidas

bool queijoAoLadoDoRato(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool jogadaInvalida = tabuleiro[linha][coluna] == Queijo && hospede == Rato
                    || tabuleiro[linha][coluna] == Rato && hospede == Queijo;
    if(jogadaInvalida) {
        printf("Queijo ao Lado do Rato!\n");
    }
    return jogadaInvalida;
}//Verifica se as regras estão sendo seguidas

bool validarEsquerda(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    return !caoAoLadoDoOsso(linha, coluna - 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !ratoAoLadoDoGato(linha, coluna - 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !gatoAoLadoDoCao(linha, coluna - 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !queijoAoLadoDoRato(linha, coluna - 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
}// Valida o caracter a esquerda do inserido, coluna -1 para ir à esquerda

bool validarDireita(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    return !caoAoLadoDoOsso(linha, coluna + 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !ratoAoLadoDoGato(linha, coluna + 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !gatoAoLadoDoCao(linha, coluna + 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !queijoAoLadoDoRato(linha, coluna + 1, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
}//Valida o caracter a direita do inserido, coluna+1 para ir à direita

bool validarCima(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    return !caoAoLadoDoOsso(linha - 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !ratoAoLadoDoGato(linha - 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !gatoAoLadoDoCao(linha - 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !queijoAoLadoDoRato(linha - 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
}//Valida o caracter acima do inserido, linha-1 para 'subir'

bool validarBaixo(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    return !caoAoLadoDoOsso(linha + 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !ratoAoLadoDoGato(linha + 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !gatoAoLadoDoCao(linha + 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro)
    && !queijoAoLadoDoRato(linha + 1, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
}//Valida o caracter abaixo do inserido, linha+1 para 'descer'

bool hospedeAlocadoCorretamente(int linha, int coluna, char hospede, int maximoLinhaTabuleiro, int maximoColunaTabuleiro, char tabuleiro[][maximoColunaTabuleiro]) {
    bool validoCima = false,
    validoBaixo = false,
    validoEsquerda = false,
    validoDireita = false;

    if(linha > 0) {
        validoCima = validarCima(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
    } else {
        validoCima = true;
    }//Se a linha for maior que 0 ele fará a verificação do hóspede acima, se for igual a 0, não é necessário fazer a validação

    if(linha < maximoLinhaTabuleiro - 1) {
        validoBaixo = validarBaixo(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
    } else {
        validoBaixo = true;
    }

    if(coluna > 0) {
        validoEsquerda = validarEsquerda(linha, coluna, hospede, maximoLinhaTabuleiro, maximoColunaTabuleiro, tabuleiro);
    } else {
        validoEsquerda = true;
    }//Se a coluna for maior que 1 ele fará a verificação do hóspede à esquerda, se for igual a 0, não é necessário fazer a validação

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
}//valida se a poisção está ocupada por I ou não.

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
}//todas as validações tem que ser válidas para o hóspede ser alocado

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


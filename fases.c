#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>

void primeiraFase() {

    const int tamanhoMaximoLinha = 2, 
              tamanhoMaximoColuma = 4,
              tamanhoMaximoHospedesParaAlocar = 2;

    char tabuleiro[2][4] = {
        {Indisponivel, Indisponivel, Disponivel, Gato}, 
        {Rato, Disponivel, Indisponivel, Indisponivel }
    };// Define o tabuleiro para o nível

    char hospedesParaAlocar[2] = { Rato, Gato }; //Define quais os caracteres o usuário poderá inserir

    bool jogadaFoiValida = false,
         jogoAcabou = false;
    char jogadaInvalidaContinue;
    
    do {
        desenharTabuleiro(2, 4, tabuleiro);
        printf("Insira um Rato e um Gato.\n");

        int linha = 0, 
            coluna = 0;
        char hospede;

        linha = buscarLinha();
        coluna = buscarColuna();
        hospede = buscarHospede();

        jogadaFoiValida = jogadaValida(linha, coluna, hospede, 2, 4, tabuleiro, tamanhoMaximoHospedesParaAlocar, hospedesParaAlocar);

        if(!jogadaFoiValida) {

            printf("A jogada nao foi valida.\n Aperte qualquer botao para tentar novamente.");
            scanf(" %c", &jogadaInvalidaContinue);

        } else {

            colocarHospedeNoTabuleiro(linha, coluna, hospede, 2, 4, tabuleiro);
            jogoAcabou = verificaSeJogoAcabou(2, 4, tabuleiro);
            removerHospedeDosHospedesParaAlocar(hospede, 2, hospedesParaAlocar);

        }

        system("cls");

    }
    while(!jogadaFoiValida || !jogoAcabou);

    printf("Parabéns, a fase foi completa com êxito! :D. :)\nDigite qualquer valor e aperte ENTER para prosseguir.");
    scanf(" %c", &jogadaInvalidaContinue);

}

void segundaFase() {

    const int tamanhoMaximoLinha = 2, 
              tamanhoMaximoColuma = 4,
              tamanhoMaximoHospedesParaAlocar = 3;

    char tabuleiro[2][4] = {
        {Disponivel, Indisponivel, Indisponivel, Indisponivel}, 
        {Indisponivel, Cao, Disponivel, Disponivel }
    };

    char hospedesParaAlocar[3] = { Cao, Cao, Osso };

    bool jogadaFoiValida = false,
         jogoAcabou = false;
    char jogadaInvalidaContinue;
    
    do {
        desenharTabuleiro(2, 4, tabuleiro);
        printf("Insira dois cães e um osso\n");

        int linha = 0, 
            coluna = 0;
        char hospede;

        linha = buscarLinha();
        coluna = buscarColuna();
        hospede = buscarHospede();

        jogadaFoiValida = jogadaValida(linha, coluna, hospede, 2, 4, tabuleiro, tamanhoMaximoHospedesParaAlocar, hospedesParaAlocar);

        if(!jogadaFoiValida) {

            printf("A jogada nao foi valida.\n Aperte qualquer botao para tentar novamente.");
            scanf(" %c", &jogadaInvalidaContinue);

        } else {

            colocarHospedeNoTabuleiro(linha, coluna, hospede, 2, 4, tabuleiro);
            jogoAcabou = verificaSeJogoAcabou(2, 4, tabuleiro);
            removerHospedeDosHospedesParaAlocar(hospede, 2, hospedesParaAlocar);

        }

        system("cls");

    }
    while(!jogadaFoiValida || !jogoAcabou);

    printf("Parabéns, a fase foi completa com êxito! :D. :)\nDigite qualquer valor e aperte ENTER para prosseguir.");
    scanf(" %c", &jogadaInvalidaContinue);

}

void terceiraFase() {


    const int tamanhoMaximoLinha = 2, 
              tamanhoMaximoColuma = 3,
              tamanhoMaximoHospedesParaAlocar = 3;

    char tabuleiro[2][3] = {
        {Disponivel, Indisponivel, Indisponivel}, 
        {Disponivel, Gato, Disponivel }
    };

    char hospedesParaAlocar[3] = { Rato, Gato, Osso };

    bool jogadaFoiValida = false,
         jogoAcabou = false;
    char jogadaInvalidaContinue;
    
    do {
        desenharTabuleiro(2, 3, tabuleiro);
        printf("Insira um Rato, um Gato e um Osso.\n");

        int linha = 0, 
            coluna = 0;
        char hospede;

        linha = buscarLinha();
        coluna = buscarColuna();
        hospede = buscarHospede();

        jogadaFoiValida = jogadaValida(linha, coluna, hospede, 2, 3, tabuleiro, tamanhoMaximoHospedesParaAlocar, hospedesParaAlocar);

        if(!jogadaFoiValida) {

            printf("A jogada nao foi valida.\n Aperte qualquer botao para tentar novamente.");
            scanf(" %c", &jogadaInvalidaContinue);

        } else {

            colocarHospedeNoTabuleiro(linha, coluna, hospede, 2, 3, tabuleiro);
            jogoAcabou = verificaSeJogoAcabou(2, 3, tabuleiro);
            removerHospedeDosHospedesParaAlocar(hospede, 2, hospedesParaAlocar);

        }

        system("cls");

    }
    while(!jogadaFoiValida || !jogoAcabou);

    printf("Parabéns, a fase foi completa com êxito! :D. :)\nDigite qualquer valor e aperte ENTER para prosseguir.");
    scanf(" %c", &jogadaInvalidaContinue);

}

void quartaFase() {

    const int tamanhoMaximoLinha = 2, 
              tamanhoMaximoColuma = 3,
              tamanhoMaximoHospedesParaAlocar = 3;

    char tabuleiro[2][3] = {
        {Disponivel, Disponivel, Disponivel}, 
        {Indisponivel, Rato, Indisponivel }
    };

    char hospedesParaAlocar[3] = { Queijo, Queijo, Osso };

    bool jogadaFoiValida = false,
         jogoAcabou = false;
    char jogadaInvalidaContinue;
    
    do {
        desenharTabuleiro(2, 3, tabuleiro);
        printf("Insira dois Queijos e um Osso.\n");

        int linha = 0, 
            coluna = 0;
        char hospede;

        linha = buscarLinha();
        coluna = buscarColuna();
        hospede = buscarHospede();

        jogadaFoiValida = jogadaValida(linha, coluna, hospede, 2, 3, tabuleiro, tamanhoMaximoHospedesParaAlocar, hospedesParaAlocar);

        if(!jogadaFoiValida) {

            printf("A jogada nao foi valida.\n Aperte qualquer botao para tentar novamente.");
            scanf(" %c", &jogadaInvalidaContinue);

        } else {

            colocarHospedeNoTabuleiro(linha, coluna, hospede, 2, 3, tabuleiro);
            jogoAcabou = verificaSeJogoAcabou(2, 3, tabuleiro);
            removerHospedeDosHospedesParaAlocar(hospede, 2, hospedesParaAlocar);

        }

        system("cls");

    }
    while(!jogadaFoiValida || !jogoAcabou);

    printf("Parabéns, a fase foi completa com êxito! :D. :)\nDigite qualquer valor e aperte ENTER para prosseguir.");
    scanf(" %c", &jogadaInvalidaContinue);

}

void quintaFase() {

    const int tamanhoMaximoLinha = 1, 
              tamanhoMaximoColuma = 4,
              tamanhoMaximoHospedesParaAlocar = 3;

    char tabuleiro[1][4] = { Disponivel, Queijo, Disponivel, Disponivel };

    char hospedesParaAlocar[3] = { Gato, Rato, Osso };

    bool jogadaFoiValida = false,
         jogoAcabou = false;
    char jogadaInvalidaContinue;
    
    do {
        desenharTabuleiro(1, 4, tabuleiro);
        printf("Insira um Gato, um Rato e um Osso.\n");

        int linha = 0, 
            coluna = 0;
        char hospede;

        linha = buscarLinha();
        coluna = buscarColuna();
        hospede = buscarHospede();

        jogadaFoiValida = jogadaValida(linha, coluna, hospede, 1, 4, tabuleiro, tamanhoMaximoHospedesParaAlocar, hospedesParaAlocar);

        if(!jogadaFoiValida) {

            printf("A jogada nao foi valida.\n Aperte qualquer botao para tentar novamente.");
            scanf(" %c", &jogadaInvalidaContinue);

        } else {

            colocarHospedeNoTabuleiro(linha, coluna, hospede, 1, 4, tabuleiro);
            jogoAcabou = verificaSeJogoAcabou(1, 4, tabuleiro);
            removerHospedeDosHospedesParaAlocar(hospede, 3, hospedesParaAlocar);

        }

        system("cls");

    }
    while(!jogadaFoiValida || !jogoAcabou);

    printf("Parabéns, a fase foi completa com êxito! :D. :)\nDigite qualquer valor e aperte ENTER para prosseguir.");
    scanf(" %c", &jogadaInvalidaContinue);

}
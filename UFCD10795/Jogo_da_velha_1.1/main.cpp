#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char jogo[3][3];
int l, c;

void inicializarMatriz() {
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++)
            jogo[l][c] = ' ';
    }
}

void imprimir() {

    printf("\n\n");
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            if (c == 0)
                printf("\t");
            printf(" %c ", jogo[l][c]);
            if (c < 2)
                printf("|");
        }
        printf("\n");
        if (l < 2)
            printf("\t-----------\n");
    }
    printf("\n");
}

int ganhouPorLinha(int l, char c) {
    if (jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c)
        return 1;
    else
        return 0;
}

int ganhouPorLinhas(char c) {
    int ganhou = 0;
    for (l = 0; l < 3; l++) {
        ganhou += ganhouPorLinha(l, c);
    }
    return ganhou;
}

int ganhouPorColuna(int c, char j) {
    if (jogo[0][c] == j && jogo[1][c] == j && jogo[2][c] == j)
        return 1;
    else
        return 0;
}

int ganhouPorColunas(char j) {
    int ganhou = 0;
    for (c = 0; c < 3; c++) {
        ganhou += ganhouPorColuna(c, j);
    }
    return ganhou;
}

int ganhouPorDiagPrin(char c) {
    if (jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
        return 1;
    else
        return 0;
}

int ganhouPorDiagSec(char c) {
    if (jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
        return 1;
    else
        return 0;
}

int ehValida(int l, int c) {
    if (l >= 0 && l < 3 && c >= 0 && c < 3 && jogo[l][c] == ' ')
        return 1;
    else
        return 0;
}

void coordEmCasa(int *linha, int *coluna, int casa){
    switch(casa){
        case 1:
            *linha = 0;
            *coluna = 0;
            break;
        case 2:
            *linha = 0;
            *coluna = 1;
            break;
        case 3:
            *linha = 0;
            *coluna = 2;
            break;
        case 4:
            *linha = 1;
            *coluna = 0;
            break;
        case 5:
            *linha = 1;
            *coluna = 1;
            break;
        case 6:
            *linha = 1;
            *coluna = 2;
            break;
        case 7:
            *linha = 2;
            *coluna = 0;
            break;
        case 8:
            *linha = 2;
            *coluna = 1;
            break;
        case 9:
            *linha = 2;
            *coluna = 2;
            break;
        }
}

void lerCasas(char j) {
    int linha, coluna, casa;

    if (j == 'X') {
        printf("Digite a casa: ");
        scanf("%d", &casa);
        fflush(stdin);

        coordEmCasa(&linha, &coluna, casa);

        while (ehValida(linha, coluna) == 0) {
            printf("Casa ocupada!\nDigite outra casa: ");
            scanf("%d", &casa);
            coordEmCasa(&linha, &coluna, casa);
        }
    } else {
        // Lógica para a jogada do computador
        do {
            linha = rand() % 3;
            coluna = rand() % 3;
        } while (ehValida(linha, coluna) == 0);
    }

    jogo[linha][coluna] = j;
}

int quantVazias() {
    int quantidade = 0;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++)
            if (jogo[l][c] == ' ')
                quantidade++;
    }
    return quantidade;
}

void jogar() {
    int jogador = 1, vitoriaX = 0, vitoria0 = 0;
    char jogador1 = 'X', jogador2 = '0';

    do {
        imprimir();
        if (jogador == 1) {
            lerCasas(jogador1);
            jogador++;
            vitoriaX += ganhouPorLinhas(jogador1);
            vitoriaX += ganhouPorColunas(jogador1);
            vitoriaX += ganhouPorDiagPrin(jogador1);
            vitoriaX += ganhouPorDiagSec(jogador1);
        } else {
            lerCasas(jogador2);
            jogador = 1;
            vitoria0 += ganhouPorLinhas(jogador2);
            vitoria0 += ganhouPorColunas(jogador2);
            vitoria0 += ganhouPorDiagPrin(jogador2);
            vitoria0 += ganhouPorDiagSec(jogador2);
        }
    } while (vitoriaX == 0 && vitoria0 == 0 && quantVazias() > 0);

    imprimir();

    if (vitoria0 == 1)
        printf("\nVoce perdeu para o computador. :(\n");
    else if (vitoriaX == 1)
        printf("\nParabens Jogador 1. Voce venceu!!!\n");
    else
        printf("\nQue pena. Perderam!!!\n");
}

int main() {
    //int opcao;
    char opcao;

    srand(time(NULL));  // Inicializa a semente para gerar números aleatórios

    do {
        inicializarMatriz();
        jogar();


        printf("\nDeseja jogar novamente? (s/n)");
        scanf("%c", &opcao);
        fflush(stdin);
        while(opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N'){
            printf("\nEscolha invalida. Escolha 's' para jogar novamente ou 'n' para sair... (s/n)");
            scanf("%c", &opcao);
            fflush(stdin);
        }
    } while (opcao == 's' || opcao == 'S');

    return 0;
}

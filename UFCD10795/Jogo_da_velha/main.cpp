#include <stdlib.h>

/*
        Aula 166: Jogo da velha com fun��es e procedimentos

        Escrito por Wagner Gaspar
        Mar�o de 2021
*/

// vari�veis globais
char jogo[3][3]; // matriz do jogo
int l, c; // �ndices para linha e coluna

// procedimento para inicializar todas as posi��es da matriz com um espa�o
void inicializarMatriz(){
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++)
            jogo[l][c] = ' ';
    }
}

// procedimento para imprimir o jogo na tela
void imprimir(){
    printf("\n\n\t 0   1   2\n\n");
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            if(c == 0)
                printf("\t");
            printf(" %c ", jogo[l][c]);
            if(c < 2)
                printf("|");
            if(c == 2)
                printf("   %d", l);
        }
        printf("\n");
        if(l < 2)
            printf("\t-----------\n");
    }
}

/*
    fun��o para verificar vit�ria do jogador c na linha l
    1 - ganhou
    0 - n�o ganhou ainda
*/
int ganhouPorLinha(int l, char c){
    if(jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c)
        return 1;
    else
        return 0;
}

/*
    fun��o para verificar vit�ria do jogador c nas linhas
    1 - ganhou
    0 - n�o ganhou ainda
*/
int ganhouPorLinhas(char c){
    int ganhou = 0;
    for(l = 0; l < 3; l++){
        ganhou += ganhouPorLinha(l, c);
    }
    return ganhou;
}

/*
    fun��o para verificar vit�ria do jogador j na coluna c
    1 - ganhou
    0 - n�o ganhou ainda
*/
int ganhouPorColuna(int c, char j){
    if(jogo[0][c] == j && jogo[1][c] == j && jogo[2][c] == j)
        return 1;
    else
        return 0;
}

/*
    fun��o que verifica vit�ria do jogador j por colunas
    1 - ganhou
    0 - n�o ganhou ainda
*/
int ganhouPorColunas(char j){
    int ganhou = 0;
    for(c = 0; c < 3; c++){
        ganhou += ganhouPorColuna(c, j);
    }
    return ganhou;
}

/*
    fun��o para verificar vit�ria do jogador c na diagonal principal
    1 - vit�ria
    0 - n�o ganhou
*/
int ganhouPorDiagPrin(char c){
    if(jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
        return 1;
    else
        return 0;
}

/*
    fun��o para verificar vit�ria do jogador c na diagonal secund�ria
    1 - vit�ria
    0 - n�o ganhou
*/
int ganhouPorDiagSec(char c){
    if(jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
        return 1;
    else
        return 0;
}

/*
    fun��o que diz se uma coordenada � v�lida ou n�o
    1 - � v�lida
    0 - n�o � v�lida
*/
int ehValida(int l, int c){
    if(l >= 0 && l < 3 && c >= 0 && c < 3 && jogo[l][c] == ' ')
        return 1;
    else
        return 0;
}

// procedimento para ler as coordenadas digitadas pelo jogador
void lerCoordenadas(char j){
    int linha, coluna;

    printf("Digite linha e coluna: ");
    scanf("%d%d", &linha, &coluna);

    while(ehValida(linha, coluna) == 0){
        printf("Coordenadas invalidas! Digite outra linha e coluna: ");
        scanf("%d%d", &linha, &coluna);
    }
    jogo[linha][coluna] = j;
}

// fun��o que retorna a quantidade de posi��es ainda vazias (n�o jogadas)
int quantVazias(){
    int quantidade = 0;

    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++)
            if(jogo[l][c] == ' ')
                quantidade++;
    }
    return quantidade;
}

// procedimento jogar com o loop (repeti��o) principal do jogo
void jogar(){
    int jogador = 1, vitoriaX = 0, vitoria0 = 0;
    char jogador1 = 'X', jogador2 = '0';

    do{
        imprimir();
        if(jogador == 1){
            lerCoordenadas(jogador1);
            jogador++;
            vitoriaX += ganhouPorLinhas(jogador1);
            vitoriaX += ganhouPorColunas(jogador1);
            vitoriaX += ganhouPorDiagPrin(jogador1);
            vitoriaX += ganhouPorDiagSec(jogador1);
        }
        else{
            lerCoordenadas(jogador2);
            jogador = 1;
            vitoria0 += ganhouPorLinhas(jogador2);
            vitoria0 += ganhouPorColunas(jogador2);
            vitoria0 += ganhouPorDiagPrin(jogador2);
            vitoria0 += ganhouPorDiagSec(jogador2);
        }
    }while(vitoriaX == 0 && vitoria0 == 0 && quantVazias() > 0);

    imprimir();

    if(vitoria0 == 1)
        printf("\nParabens Jogador 2. Voce venceu!!!\n");
    else if(vitoriaX == 1)
        printf("\nParabens Jogador 1. Voce venceu!!!\n");
    else
        printf("\nQue pena. Perderam!!!\n");
}

int main(){
    int opcao;

    do{
        inicializarMatriz();
        jogar();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    }while(opcao == 1);

    return 0;
}

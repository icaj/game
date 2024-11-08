#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <keyboard.h>
#include <screen.h>
#include <timer.h>
#include <score.h>
#include <game.h>

// move as coordenadas dos objetos para o centro da tela a cada iteracao
int moveParaCentro (Invasor *inv, int centroX, int centroY) {
    if (inv->x < centroX) {
        inv->x++;
    } else if (inv->x > centroX) {
        inv->x--;
    }

    if (inv->y < centroY) {
        inv->y++;
    } else if (inv->y > centroY) {
        inv->y--;
    }

    return !(inv->x == centroX && inv->y == centroY);
}

// desenha na tela os invasores a partir de suas coordenadas
void desenhaInvasores(Invasor inv[], int qtde) {
    screenClear();
    for (int i = 0; i < qtde; i++) {
        screenGotoxy(inv[i].x, inv[i].y);
        screenSetColor(YELLOW, DARKGRAY);
        printf("*");
        screenSetNormal();
    }
    screenUpdate();
}

// exibe efeito grafico na tela inicial do jogo
void telaInicial() {
    int centroX = MAXX / 2, centroY = MAXY /2;
    int qtdeInv = 50;
    Invasor inv[qtdeInv];
    char szTitulo[] = ". . : :  S P A C E   I N V A D E R S  : : . .\n";

    screenInit(1);
    keyboardInit();   // inicializa o teclado
    timerInit(DELAY); // inicializa o timer 

    for(int i = 0; i< qtdeInv; i++) {
        inv[i].x = rand() % MAXX;
        inv[i].y = rand() % MAXY;
    }

    int centro = 1;
    while(centro) {
        desenhaInvasores(inv, qtdeInv);
        centro = 0;
        for(int i = 0; i < qtdeInv; i++) {
            centro += moveParaCentro(&inv[i], centroX, centroY);
        }

        while(timerTimeOver() != 1); 
        // soa um beep
        printf("\a");

        screenClear();
    }
    screenClear();
    screenGotoxy(MAXX/2 - strlen(szTitulo)/2, MAXY/2);
    screenSetColor(YELLOW, DARKGRAY);
    screenSetBold();
    printf("%s", szTitulo);
    screenSetNormal();
    screenUpdate();

}

// exibe maiores pontuadores do jogo
void exibeMaioresPontuadores() {
    char szTitulo[] = "Maiores Pontuadores";
    int j = quantidadeJogadores();
    if (j > 5) j = 5;

    JogadorPonto *jogadores = lerJogadores(5);

    screenGotoxy(MAXX/2 - strlen(szTitulo)/2, MAXY/2+2);
    printf("%s", szTitulo);
    for(int i = 0;i < j;i++) {
        screenGotoxy(MAXX/2 - 8, MAXY/2 + i + 4);
        printf("%8s  - %4d\n", jogadores[i].nome, jogadores[i].ponto);
    }
    screenUpdate();    
}

// solicita o nome do jogador atual
void getNomeJogador(char *nomeJogador) {
    screenGotoxy(MAXX/2 - 7, MAXY/2 + 12);
    printf("Seu apelido: ");
    screenShowCursor();
    screenUpdate();
    keyboardEcho();
    scanf("%8s", nomeJogador);
    keyboardNoEcho();
}
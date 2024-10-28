#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <timer.h>
#include <screen.h>
#include <keyboard.h>

#define DELAY 60
#define ESQUERDA 'a' 
#define DIREITA 'd' 
#define FIM 'f'
#define TIRO ' '
#define INVASORES 19
#define PROJETEIS 5

// Estruturas para o jogador e os invasores
typedef struct {
    int x, y;
} Jogador;

typedef struct {
    int x, y;
    int ativo;
} Projetil;

typedef struct {
    int x, y;
    int ativo;
} Nave;

// Variáveis globais
Jogador jogador;
Projetil projeteis[PROJETEIS];
Nave invasores[INVASORES];
int pontuacao = 0;

// Inicializa o jogo
void inicializar() {

    // Inicializa o jogador
    jogador.x = MAXX / 2;
    jogador.y = MAXY - 3;

    // Inicializa os projeteis
    for (int i = 0; i < 5; i++) {
        projeteis[i].ativo = 0;
    }

    // Inicializa os invasores
    for (int i = 0; i < INVASORES; i++) {
        invasores[i].ativo = 1;
        invasores[i].x = (MAXX/INVASORES) + ((MAXX/INVASORES) * i);
        invasores[i].y = 4;
        screenGotoxy(invasores[i].x, invasores[i].y);
        printf("*");
    }
}

// Desenha o jogo na tela
void desenhar() {

    // Desenha os invasores
    for (int i = 0; i < INVASORES; i++) {
        screenGotoxy((MAXX/INVASORES) + ((MAXX/INVASORES) * i), 4);
        if(invasores[i].ativo)
            printf("*");
        else
            printf(" ");
    }

    // Desenha os projeteis
    for (int i = 0; i < PROJETEIS; i++) {
        if (projeteis[i].ativo) {
            if(projeteis[i].y != jogador.y-1) {
                screenGotoxy(projeteis[i].x, projeteis[i].y+1);
                printf(" ");
            }
            screenGotoxy(projeteis[i].x, projeteis[i].y);
            printf("|");
        }
    }

    // Desenha o jogador
    screenGotoxy(jogador.x, jogador.y);
    printf("A");

    // Desenha a pontuação
    screenGotoxy(MAXX-16, MAXY);
    printf("Pontuação: %3d", pontuacao);
    
    screenUpdate();
}

// Lógica do jogo
void atualizar() {
    
    // Movimenta os projeteis
    for (int i = 0; i < PROJETEIS; i++) {
        if (projeteis[i].ativo) {
            projeteis[i].y -= 1;
            if (projeteis[i].y < 1) {
                projeteis[i].ativo = 0;
            }
        }
    }

    // Verifica colisão dos projeteis com os invasores
    for (int i = 0; i < PROJETEIS; i++) {
        if (projeteis[i].ativo) {
            if (invasores[i].x == projeteis[i].x && invasores[i].y == projeteis[i].y) {
                invasores[i].ativo = 0;
                projeteis[i].ativo = 0;
                pontuacao += 10;
            }
        }
    }
    screenUpdate();
}

// Controle do jogador e dos projeteis
int controle() {
    int tecla = 0;

    if(keyhit()) { // verifica se usuario pressionou alguma tecla
       tecla = readch(); // le tecla pressionada

        // apaga posicao anterior do jogador
        if (tecla == ESQUERDA || tecla == DIREITA) {
            screenGotoxy(jogador.x, jogador.y);
            printf(" ");

            // Movimento do jogador
            if (tecla == ESQUERDA && jogador.x > 0) {
                jogador.x -= 1;
            } else if (tecla == DIREITA && jogador.x < MAXX - 1) {
                jogador.x += 1;
            }
        }
        // Disparo do jogador
        if (tecla == TIRO) {
            for (int i = 0; i < PROJETEIS; i++) {
                if (!projeteis[i].ativo) {
                    projeteis[i].x = jogador.x;
                    projeteis[i].y = jogador.y - 1;
                    projeteis[i].ativo = 1;
                    break;
                }
            }
            printf("\a");
        }
    }
    screenUpdate();
    return tecla;
}

// Loop principal do jogo
void loop_jogo() {
    int tecla = 0;

    screenInit(1);   // inicializa a tela
    keyboardInit();  // inicializa o teclado
    timerInit(DELAY);   // inicializa o timer 

    while(tecla != FIM) {
        if(timerTimeOver() == 1) { // delay para atualizacao do jogo
            desenhar();   // desenha a tela do jogo
            atualizar();  // atualiza a posicao dos objetos na tela
            tecla = controle();  // verifica tecla pessionada e atualiza variaveis
        }
    }

    keyboardDestroy(); // finaliza teclado
    screenDestroy();   // finaliza tela
    timerDestroy();    // finaliza timer
}

int main() {

    inicializar(); // inicializa variaveis
    loop_jogo();   // loop principal do jogo

    return 0;
}

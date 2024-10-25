#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <timer.h>
#include <screen.h>
#include <keyboard.h>

#define LARGURA 40
#define ALTURA 20
#define ESQUERDA 109
#define DIREITA 108
#define FIM 70
#define TIRO 32

// Estruturas para o jogador e os invasores
typedef struct {
    int x, y;
} Nave;

typedef struct {
    int x, y;
    int ativo;
} Projetil;

// Variáveis globais
Nave jogador;
Projetil projeteis[5];
int invasores[LARGURA];
int pontuacao = 0;

// Inicializa o jogo
void inicializar() {
    screenInit(1);
    keyboardInit();
    timerInit(50);

    // Inicializa o jogador
    jogador.x = LARGURA / 2;
    jogador.y = ALTURA - 1;

    // Inicializa os projeteis
    for (int i = 0; i < 5; i++) {
        projeteis[i].ativo = 0;
    }

    // Inicializa os invasores
    for (int i = 0; i < LARGURA; i++) {
        invasores[i] = 1;
    }
}

// Desenha o jogo na tela
void desenhar() {

    // Desenha os invasores
    for (int i = 0; i < LARGURA; i++) {
        if (invasores[i]) {
            screenGotoxy(i+1, 1);
            printf("*");
            screenUpdate();
        }
    }

    // Desenha os projeteis
    for (int i = 0; i < 5; i++) {
        if (projeteis[i].ativo) {
            screenGotoxy(projeteis[i].x, projeteis[i].y);
            printf("|");
            screenUpdate();
        }
    }

    // Desenha o jogador
    screenGotoxy(jogador.x, jogador.y);
    printf("A");
    screenUpdate();

    // Desenha a pontuação
    screenGotoxy(MAXX-16, MAXY);
    printf("Pontuação: %3d", pontuacao);

    screenUpdate();
}

// Lógica do jogo
void atualizar() {
    
    // Movimenta os projeteis
    for (int i = 0; i < 5; i++) {
        if (projeteis[i].ativo) {
            projeteis[i].y -= 1;
            if (projeteis[i].y < 1) {
                projeteis[i].ativo = 0;
            }
        }
    }

    // Verifica colisão dos projeteis com os invasores
    for (int i = 0; i < 5; i++) {
        if (projeteis[i].ativo) {
            if (invasores[projeteis[i].x]) {
                invasores[projeteis[i].x] = 0;
                projeteis[i].ativo = 0;
                pontuacao += 10;
            }
        }
    }
}

// Controle do jogador e dos projeteis
int controle() {

    if(keyhit()) {
       int tecla = readch();

        // Movimento do jogador
        if (tecla == ESQUERDA && jogador.x > 0) {
            jogador.x -= 1;
        } else if (tecla == DIREITA && jogador.x < LARGURA - 1) {
            jogador.x += 1;
        }

        // Disparo do jogador
        if (tecla == TIRO) {
            for (int i = 0; i < 5; i++) {
                if (!projeteis[i].ativo) {
                    projeteis[i].x = jogador.x;
                    projeteis[i].y = jogador.y - 1;
                    projeteis[i].ativo = 1;
                    break;
                }
            }
        }
        // fim do jogo
        if (tecla == FIM) {
            return 1;
        }
    }
    return 0;
}

// Loop principal do jogo
void loop_jogo() {

    while (!controle()) {
        desenhar();
        atualizar();
        
    }
}

int main() {

    inicializar();
    loop_jogo();

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}

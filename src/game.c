#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <timer.h>
#include <screen.h>
#include <keyboard.h>

#define WIDTH 40
#define HEIGHT 20
#define CLI_KEY_LEFT 109
#define CLI_KEY_RIGHT 108
#define CLI_KEY_F 'F'
#define CLI_KEY_SPACE 32

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
int invasores[WIDTH];
int pontuacao = 0;

// Inicializa o jogo
void inicializar() {
    screenInit(1);
    keyboardInit();
    timerInit(5000);

    // Inicializa o jogador
    jogador.x = WIDTH / 2;
    jogador.y = HEIGHT - 1;

    // Inicializa os projeteis
    for (int i = 0; i < 5; i++) {
        projeteis[i].ativo = 0;
    }

    // Inicializa os invasores
    for (int i = 0; i < WIDTH; i++) {
        invasores[i] = 1;
    }
}

// Desenha o jogo na tela
void desenhar() {

    // Desenha os invasores
    for (int i = 0; i < WIDTH; i++) {
        if (invasores[i]) {
            screenGotoxy(i, 1);
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
    screenGotoxy(MAXX - 8, MAXY - 8);
    printf("Pontuação: %d", pontuacao);

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
    //screenUpdate();
}

// Controle do jogador e dos projeteis
int controle() {
    int tecla; 

    if(keyhit()) {
       tecla = readch();

        // Movimento do jogador
        if (tecla == CLI_KEY_LEFT && jogador.x > 0) {
            jogador.x -= 1;
        } else if (tecla == CLI_KEY_RIGHT && jogador.x < WIDTH - 1) {
            jogador.x += 1;
        }

        // Disparo do jogador
        if (tecla == CLI_KEY_SPACE) {
            for (int i = 0; i < 5; i++) {
                if (!projeteis[i].ativo) {
                    projeteis[i].x = jogador.x;
                    projeteis[i].y = jogador.y - 1;
                    projeteis[i].ativo = 1;
                    break;
                }
            }
        }
        // Fim do jogo
        if (tecla == CLI_KEY_F) {
            return CLI_KEY_F;
        }
    }
}

// Loop principal do jogo
void loop_jogo() {

    while (1) {
        desenhar();
        atualizar();
        if (controle() == CLI_KEY_F) break;
        screenGotoxy(MAXX, MAXY-10);
        timerPrint();
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

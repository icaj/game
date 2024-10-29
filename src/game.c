#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <timer.h>
#include <screen.h>
#include <keyboard.h>

#define DELAY 50
#define ESQUERDA 'a' 
#define DIREITA 'd' 
#define FIM 'f'
#define TIRO ' '
#define INVASORES 19
#define PROJETEIS 5
#define CHAR_INV  '*'
#define TAXA_ATUALIZACAO_INVASORES 80

// Estruturas para o jogador, projeteis e os invasores
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
int contador = TAXA_ATUALIZACAO_INVASORES;
int fim = 0;

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
        printf("%c", CHAR_INV);
    }
}

void gameOver() {
    fim = 1;
}

int isGameOver() {
    return fim;
}

// Desenha o jogo na tela
void desenhar() {

    // Desenha os invasores
    for (int i = 0; i < INVASORES; i++) {
        screenGotoxy(invasores[i].x, invasores[i].y);
        if(invasores[i].ativo)
            printf("%c", CHAR_INV);
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
            if(projeteis[i].y > 1) {
                screenGotoxy(projeteis[i].x, projeteis[i].y);
                printf("|");
            }
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
    
    // Movimenta os invasores
    if(contador==0) {
        for(int i = 0; i < INVASORES; i++) {
            if(invasores[i].ativo) {
                screenGotoxy(invasores[i].x, invasores[i].y);
                printf(" ");
                invasores[i].y += 1;
                if(invasores[i].y >= jogador.y)
                    gameOver();
            }
        }
    }
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
            for(int z = 0; z < INVASORES; z++) {
                if (invasores[z].x == projeteis[i].x && invasores[z].y == projeteis[i].y) {
                    invasores[z].ativo = 0;
                    projeteis[i].ativo = 0;
                    pontuacao += 10;
                    screenGotoxy(invasores[z].x, invasores[z].y);
                    printf(" ");
                    screenGotoxy(invasores[z].x, invasores[z].y+1);
                    printf(" ");
                }
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
            // soa um beep
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

        if(isGameOver())
            break;

        if(timerTimeOver() == 1) { // delay para atualizacao do jogo
            desenhar();   // desenha a tela do jogo
            atualizar();  // atualiza a posicao dos objetos na tela
            tecla = controle();  // verifica tecla pessionada e atualiza variaveis
            contador--;
            if(contador < 0) contador = TAXA_ATUALIZACAO_INVASORES;
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

#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>

#define DELAY 40
#define ESQUERDA 'a' 
#define DIREITA 'd' 
#define FIM 'f'
#define TIRO ' '
#define INVASORES_POR_NIVEL 19
#define PROJETEIS 5
#define CHAR_INV  "W"
#define TAXA_ATUALIZACAO_INVASORES 80
#define GAMEOVER -1
#define PROXIMONIVEL 1

// Estruturas para o jogador, projeteis e os invasores
typedef struct {
    int x, y;
    char nome[9];
    int pontuacao;
} Jogador;

typedef struct {
    int x, y;
    int ativo;
} Projetil;

typedef struct {
    int x, y;
    int ativo;
} Invasor;

typedef struct {
    int nivel;
    Invasor *pInv;
    int qtdeInvasores;
    Jogador jogador;
    Projetil projeteis[PROJETEIS];
    int contador;
} Jogo;

#endif /* __GAME_H__ */
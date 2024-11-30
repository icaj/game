/**
 * game.h
 * Created on Nov, 18th 2024
 * Author: Fernando Cyreno, Marcello Fernandes e Ivo Caetano
 * Based on Imperative and Functional Programming from CEZAR School"
*/

#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>

#define DELAY 40
#define ESQUERDA 'A' 
#define DIREITA 'D' 
#define FIM 'F'
#define TIRO ' '
#define INVASORES_POR_NIVEL 8
#define PROJETEIS 5
#define CHAR_INV  "👾"
#define TAXA_ATUALIZACAO_INVASORES 80
#define GAMEOVER -1
#define PROXIMONIVEL 1
#define NIVELMAXIMO 10

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
    int taxaAtualizacao;
} Jogo;

#endif /* __GAME_H__ */
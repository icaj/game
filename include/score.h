/**
 * score.h
 * Created on Nov, 18th 2024
 * Author: Fernando Cyreno, Marcello Fernandes e Ivo Caetano
 * Based on Imperative and Functional Programming from CEZAR School"
*/

#ifndef __SCORE_H__
#define __SCORE_H__

#include <stdio.h>

// Estrutura para armazenar o nome e a pontuação do jogador
typedef struct {
    char nome[9];
    int ponto;
} JogadorPonto;

// Declaração das funções
int salvarJogador(JogadorPonto jogador);
JogadorPonto *lerJogadores();
int quantidadeJogadores();

#endif /* __SCORE_H__ */
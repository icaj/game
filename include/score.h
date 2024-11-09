#ifndef __SCORE_H__
#define __SCORE_H__

#include <stdio.h>

// Estrutura para armazenar o nome e a pontuação do jogador
typedef struct {
    char nome[9];
    int ponto;
} JogadorPonto;

// Declaração das funções
void salvarJogador(JogadorPonto jogador);
JogadorPonto *lerJogadores(int quantidade);
int quantidadeJogadores();

#endif /* __SCORE_H__ */
/**
 * util.h
 * Created on Nov, 18th 2024
 * Author: Fernando Cyreno, Marcello Fernandes e Ivo Caetano
 * Based on Imperative and Functional Programming from CEZAR School"
*/

#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <game.h>

void telaInicial();

void lerNomeJogador(char *nomeJogador);

void exibeMaioresPontuadores();

void efeitoInvasores(Jogo *p, int qtdeInvaores);

#endif /* __UTIL_H__ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <timer.h>
#include <screen.h>
#include <keyboard.h>
#include <util.h>
#include <score.h>
#include <game.h>

// Variáveis globais
Jogo jogo;

// Inicializa o jogo
void inicializar(int nivel) {

    // limpa tela
    screenInit(1);

    // iniciaiza o jogo
    jogo.nivel = nivel;
    jogo.qtdeInvasores = jogo.nivel * INVASORES_POR_NIVEL;
    jogo.contador = TAXA_ATUALIZACAO_INVASORES;

    // aloca em memória invasores necessarios para o jogo
    if(jogo.pInv == NULL) {
        jogo.pInv = malloc(sizeof(Invasor) * jogo.qtdeInvasores);
    } else {
        jogo.pInv = realloc(jogo.pInv, sizeof(Invasor) * jogo.qtdeInvasores);
    }

    // Inicializa o jogador
    jogo.jogador.x = MAXX / 2;
    jogo.jogador.y = MAXY - 3;
    if(jogo.nivel == 1)
        jogo.jogador.pontuacao = 0;

    // Inicializa os projeteis
    for (int i = 0; i < PROJETEIS; i++) {
        jogo.projeteis[i].ativo = 0;
    }

    // Inicializa os invasores
    int linha = 4;
    int coluna = ((MAXX - 2) / INVASORES_POR_NIVEL);
    int linhasInvasores = jogo.qtdeInvasores / INVASORES_POR_NIVEL;
    for (int i = 0; i < linhasInvasores; i++) {
        for(int z = 0;z < INVASORES_POR_NIVEL; z++) {
            jogo.pInv[i*INVASORES_POR_NIVEL + z].ativo = 1;
            jogo.pInv[i*INVASORES_POR_NIVEL + z].x = coluna;
            jogo.pInv[i*INVASORES_POR_NIVEL + z].y = linha;
            screenGotoxy(jogo.pInv[i].x, jogo.pInv[i].y);
            printf("%s", CHAR_INV);
            coluna += ((MAXX-2)/INVASORES_POR_NIVEL);
        }
        linha += 2;
        coluna = ((MAXX - 2) / INVASORES_POR_NIVEL);
    }
}

// aguarda x milessegundos
void sleep(int milissegundos) {
    int cont = milissegundos/DELAY;    // tempo para mostrar a tela 

    // delay para mostrar a tela game over
    while(cont) {
        if(timerTimeOver() == 1) cont--;
    }
}

void exibeTela(char szMensagem[]) {
    // exibe a tela de parabens
    screenClear();
    screenGotoxy((MAXX-strlen(szMensagem))/2, MAXY/2);
    screenSetBlink();
    screenSetColor(RED, DARKGRAY);
    printf("%s", szMensagem);
    screenSetNormal();
    screenUpdate();
}

void proximoNivel() {
    exibeTela("P A R A B E N S  !!!");
    sleep(4000);
}

// tela Game Over
void gameOver(char nome[], int pontuacao) {
    JogadorPonto jogador[1];
    strcpy(jogador[0].nome, nome);
    jogador[0].ponto = pontuacao;

    salvarJogador(jogador[0]);

    exibeTela("G A M E  O V E R");
    exibeMaioresPontuadores();
    sleep(4000);
}

// zerou o jogo
void zerouJogo() {
    exibeTela("V O C Ê  Z E R O U  O  J O G O !!!!   PARABÉNS !");
    sleep(5000);
}

// Desenha o jogo na tela
void desenhar() {

    // Desenha os invasores
    screenSetColor(LIGHTMAGENTA, DARKGRAY);
    for (int i = 0; i < jogo.qtdeInvasores; i++) {
        screenGotoxy(jogo.pInv[i].x, jogo.pInv[i].y);
        if(jogo.pInv[i].ativo)
            printf("%s", CHAR_INV);
        else
            printf(" ");
    }
    screenSetNormal();

    // Desenha os projeteis
    for (int i = 0; i < PROJETEIS; i++) {
        if (jogo.projeteis[i].ativo) {
            if(jogo.projeteis[i].y != jogo.jogador.y-1) {
                screenGotoxy(jogo.projeteis[i].x, jogo.projeteis[i].y+1);
                printf(" ");
            }
            if(jogo.projeteis[i].y > 1) {
                screenGotoxy(jogo.projeteis[i].x, jogo.projeteis[i].y);
                screenSetColor(YELLOW, DARKGRAY);
                printf("|");
                screenSetNormal();
            }
        }
    }

    // Desenha cabeçalho
    screenGotoxy(3, 0);
    printf("Nível %d", jogo.nivel);

    // Desenha o jogador
    screenGotoxy(jogo.jogador.x, jogo.jogador.y);
    screenSetColor(CYAN, DARKGRAY);
    printf("A");
    screenSetNormal();

    // Desenha a pontuação
    screenGotoxy(MAXX-25, 0);
    screenSetColor(YELLOW, DARKGRAY);
    printf("%s Pontos: %6d", jogo.jogador.nome, jogo.jogador.pontuacao);
    screenSetNormal();

    // exibe ajuda
    screenGotoxy(3, MAXY);
    printf("A:Direita - D:Esquerda - Espaço:Tiro - F:Sair");
    
    screenUpdate();
}

// Lógica do jogo
int atualizar() {
    int invasoresAtivos = 0;
    // Movimenta os invasores
    if(!jogo.contador) {
        for(int i = 0; i < jogo.qtdeInvasores; i++) {
            if(jogo.pInv[i].ativo) {
                screenGotoxy(jogo.pInv[i].x, jogo.pInv[i].y);
                printf(" ");
                jogo.pInv[i].y += 1;
                invasoresAtivos++;
                if(jogo.pInv[i].y >= jogo.jogador.y)
                    return GAMEOVER;
            }
        }
        if (invasoresAtivos == 0) {
            return PROXIMONIVEL;
        }
    }

    // Movimenta os projeteis
    for (int i = 0; i < PROJETEIS; i++) {
        if (jogo.projeteis[i].ativo) {
            jogo.projeteis[i].y -= 1;
            if (jogo.projeteis[i].y < 1) {
                jogo.projeteis[i].ativo = 0;
            }
        }
    }

    // Verifica colisão dos projeteis com os invasores
    for (int i = 0; i < PROJETEIS; i++) {
        if (jogo.projeteis[i].ativo) {
            for(int z = 0; z < jogo.qtdeInvasores; z++) {
                if (jogo.pInv[z].ativo) {
                    if (jogo.pInv[z].x == jogo.projeteis[i].x && jogo.pInv[z].y == jogo.projeteis[i].y) {
                        jogo.pInv[z].ativo = 0;
                        jogo.projeteis[i].ativo = 0;
                        jogo.jogador.pontuacao += 10;
                        screenGotoxy(jogo.pInv[z].x, jogo.pInv[z].y);
                        printf(" ");
                        screenGotoxy(jogo.pInv[z].x, jogo.pInv[z].y+1);
                        printf(" ");
                    }
                }
            }
        }
    }
    screenUpdate();
    return 0;
}

// Controle do jogador e dos projeteis
int controle() {
    int tecla = 0;

    if(keyhit()) { // verifica se usuario pressionou alguma tecla
       tecla = readch(); // le tecla pressionada

        // apaga posicao anterior do jogador
        if (tecla == ESQUERDA || tecla == DIREITA) {
            screenGotoxy(jogo.jogador.x, jogo.jogador.y);
            printf(" ");

            // Movimento do jogador
            if (tecla == ESQUERDA && jogo.jogador.x > 2) {
                jogo.jogador.x -= 1;
            } else if (tecla == DIREITA && jogo.jogador.x < MAXX - 2) {
                jogo.jogador.x += 1;
            }
        }
        // Disparo do jogador
        if (tecla == TIRO) {
            for (int i = 0; i < PROJETEIS; i++) {
                if (!jogo.projeteis[i].ativo) {
                    jogo.projeteis[i].x = jogo.jogador.x;
                    jogo.projeteis[i].y = jogo.jogador.y - 1;
                    jogo.projeteis[i].ativo = 1;
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
    // tecla pressionada pelo jogador
    int tecla = 0;
    // status atual do jogo (GAMEOVER ou PROXIMONIVEL)
    int status = 0;

    keyboardInit();   // inicializa o teclado
    timerInit(DELAY); // inicializa o timer 

    while(tecla != FIM) {
        if(timerTimeOver() == 1) { // delay para atualizacao do jogo
            desenhar();            // desenha a tela do jogo
            status = atualizar();  // atualiza a posicao dos objetos na tela
            // verifica se é fim de jogo
            if (status == GAMEOVER) {
                gameOver(jogo.jogador.nome, jogo.jogador.pontuacao);
                break;
            // verifica se vai pro próximo nivel
            } else if (status == PROXIMONIVEL) {
                // verifica se chegou no nivel máximo
                if(jogo.nivel == 8) {
                    zerouJogo();
                    break;
                }
                // vai para o proximo nivel
                proximoNivel();
                inicializar(jogo.nivel+1);
            }
            tecla = controle();  // verifica tecla pessionada e atualiza variaveis
            // atualiza timer
            jogo.contador--;
            if(jogo.contador < 0) jogo.contador = TAXA_ATUALIZACAO_INVASORES;
        }
    }

    keyboardDestroy(); // finaliza teclado
    screenDestroy();   // finaliza tela
    timerDestroy();    // finaliza timer
}

int main() {
    char szNomeJogador[9] = "\0";

    // exibe tela inicial
    telaInicial();

    // exibe lista dos maiores jogadores
    exibeMaioresPontuadores();

    // solicta o nome do jodador
    getNomeJogador(szNomeJogador);
    strcpy(jogo.jogador.nome, szNomeJogador);

    // inicializa variaveis definindo o nivel inicial 
    inicializar(1);

    // loop principal do jogo
    loop_jogo();

    // libera memoria
    free(jogo.pInv);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <keyboard.h>
#include <screen.h>
#include <timer.h>
#include <score.h>
#include <game.h>

// aguarda x milessegundos
void sleep(int milissegundos) {
    int cont = milissegundos/DELAY;    // tempo para mostrar a tela 

    // delay para mostrar a tela game over
    while(cont) {
        if(timerTimeOver() == 1) cont--;
    }
}

// move as coordenadas dos objetos para o centro da tela a cada iteracao
int moveParaCentro (Invasor *inv, int centroX, int centroY) {
    // move coordenada x para o centro 1 posicao
    if (inv->x < centroX) {
        inv->x++;
    } else if (inv->x > centroX) {
        inv->x--;
    }
    // move coornada y 1 posicao para o centro
    if (inv->y < centroY) {
        inv->y++;
    } else if (inv->y > centroY) {
        inv->y--;
    }
    // retorna 0 se o invasor chegou ao centro
    return !(inv->x == centroX && inv->y == centroY);
}

// desenha na tela os invasores a partir de suas coordenadas
void desenhaInvasores(Invasor inv[], int qtde) {
    // limpa a tela
    screenClear();
    screenInit(1);
    // desenha os invasores a partir de suas coordenadas
    for (int i = 0; i < qtde; i++) {
        screenGotoxy(inv[i].x, inv[i].y);
        screenSetColor(YELLOW, DARKGRAY);
        printf("%s", CHAR_INV);
        screenSetNormal();
    }
    // atualiza a tela
    screenUpdate();
}

void efeitoInvasores(Jogo *p, int qtdeInvaores) {
    Invasor inv[qtdeInvaores];

    // define posicao inicial dos invasores
    for(int i = 0; i < qtdeInvaores; i++) {
        inv[i].x = rand() % MAXX;
        inv[i].y = rand() % MAXY;
    }

    int centro = 1;
    while(centro) {
        desenhaInvasores(inv, qtdeInvaores);
        centro = 0;
        for(int i = 0; i < qtdeInvaores; i++) {
            centro += moveParaCentro(&inv[i], p->pInv[i].x, p->pInv[i].y);
        }
        // aguarda alguns milessegundos
        while(timerTimeOver() != 1); 
    }
    desenhaInvasores(inv, qtdeInvaores);
}

// exibe efeito grafico na tela inicial do jogo
void telaInicial() {
    // define centro da tela
    int centroX = MAXX / 2, centroY = MAXY /2;

    // define qtde de invasores aleatorios
    int qtdeInv = 60;
    Invasor inv[qtdeInv];

    // mensagem final depois do efeito especial
    char szTitulo[] = ". . : :  S P A C E   I N V A D E R S  : : . .\n";

    // define posicao inicial dos invasores
    for(int i = 0; i < qtdeInv; i++) {
        inv[i].x = rand() % MAXX;
        inv[i].y = rand() % MAXY;
    }

    // loop do efeito especial
    int centro = 1;
    while(centro) {
        // desenha invasores
        desenhaInvasores(inv, qtdeInv);
        // muda coordenadas nos invasores em direcao ao centro
        centro = 0;
        for(int i = 0; i < qtdeInv; i++) {
            centro += moveParaCentro(&inv[i], centroX, centroY);
        }
        // aguarda alguns milessegundos
        while(timerTimeOver() != 1); 
        // soa um beep
        printf("\a");
    }
    // limpa a tela e exibe o nome do jogo
    screenClear();
    screenGotoxy(MAXX/2 - strlen(szTitulo)/2, MAXY/2);
    screenSetColor(YELLOW, DARKGRAY);
    screenSetBold();
    printf("%s", szTitulo);
    screenSetNormal();
    screenUpdate();
}

// exibe maiores pontuadores do jogo
void exibeMaioresPontuadores() {
    char szTitulo[] = "Maiores Pontuadores";
    
    // verfifica qtde de maiores jogadores
    int j = quantidadeJogadores();

    // se maior que 0 exibe
    if (j > 0) {
        if (j > 5) j = 5;
        // obtem relacao de jogadores
        JogadorPonto *jogadores = lerJogadores();

        // exibe relacao de jogadores se ponteiro nso é invalido
        if(jogadores != NULL) {
            screenGotoxy(MAXX/2 - strlen(szTitulo)/2, MAXY/2+2);
            printf("%s", szTitulo);
            for(int i = 0;i < j;i++) {
                screenGotoxy(MAXX/2 - 8, MAXY/2 + i + 4);
                printf("%8s  - %4d\n", jogadores[i].nome, jogadores[i].ponto);
            }
            screenUpdate();
        }
    }    
}

// solicita o nome do jogador atual
void lerNomeJogador(char *nome) {
    char nomeJogador[9];

    memset(nomeJogador, 0, sizeof(nomeJogador));

    // posiciona o cursor na tela
    screenGotoxy(MAXX/2 - 7, MAXY/2 + 12);

    // solicita o apelido ao jogador
    printf("Seu apelido: ");
    screenShowCursor();
    screenUpdate();
    
    // habilita visualizacao das teclas pressionadas
    keyboardEcho();
    // ler teclado
    scanf("%8s", nomeJogador);
    // desabilita visualizacao das teclas pressionadas
    keyboardNoEcho();

    // converte em maiusculas
    for(int i = 0; i < sizeof(nomeJogador); i++) {
        nomeJogador[i] = toupper(nomeJogador[i]);
    }

    strcpy(nome, nomeJogador);
}

int pararContinuar() {
    int tecla;
    char mensagem[] = "Tecle F para sair ou qualquer tecla para continuar";
    char mensagemEspacos[] = "                                                  ";

    // posiciona o cursor na tela
    screenGotoxy((MAXX - strlen(mensagem))/2, MAXY/2 + 12);
    printf("%s", mensagem);

    screenUpdate();
    
    // zera buffer do teclado
    while(keyhit()) {
        readch();
    }

    // aguarda tecla pressionada do usuario
    while(1) {
        if(keyhit()) {
            tecla = readch();
            tecla = toupper(tecla);
            break;
        }
    }
    // posiciona o cursor na tela
    screenGotoxy((MAXX - strlen(mensagem))/2, MAXY/2 + 12);
    printf("%s", mensagemEspacos);

    return tecla;
}

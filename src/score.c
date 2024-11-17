#include <score.h>
#include <stdlib.h>

// Função para salvar o ponto de um jogador no arquivo
int salvarJogador(JogadorPonto jogador) {
    FILE *arquivo = fopen("scores.txt", "a");
    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return -1;
    }

    fprintf(arquivo, "%s %d\n", jogador.nome, jogador.ponto);
    fclose(arquivo);
    return 0;
}

// Função de comparação para ordenar os jogadores em ordem decrescente de pontos
int comparaPontos(const void *a, const void *b) {
    JogadorPonto *jogadorA = (JogadorPonto *)a;
    JogadorPonto *jogadorB = (JogadorPonto *)b;
    return jogadorB->ponto - jogadorA->ponto;
}

// Função para contar a quantidade de jogadores no arquivo
int quantidadeJogadores() {
    FILE *arquivo = fopen("scores.txt", "r");
    if (arquivo == NULL) {
        return -1;
    }

    int contador = 0;
    char nome[9];
    int ponto;

    // Conta o número de linhas (jogadores) no arquivo
    while (fscanf(arquivo, "%9s %d", nome, &ponto) == 2) {
        contador++;
    }
    fclose(arquivo);
    return contador;
}

// Função para ler o arquivo e retornar um vetor com os cinco jogadores de maior pontuação
JogadorPonto *lerJogadores() {
    FILE *arquivo = fopen("scores.txt", "r");
    if (arquivo == NULL) {
        return NULL;
    }

    // ler quantidade de jogadores no arquivo
    int quantidade = quantidadeJogadores();
    // se quantidade <= 0 finaliza
    if (quantidade <= 0) {
        fclose(arquivo);
        return NULL;
    }

    // Aloca memória para o vetor de jogadores com base na quantidade obtida
    JogadorPonto *jogadores = malloc(quantidade * sizeof(JogadorPonto));
    if (jogadores == NULL) {
        fclose(arquivo);
        return NULL;
    }

    int i = 0;
    while (fscanf(arquivo, "%9s %d", jogadores[i].nome, &jogadores[i].ponto) == 2) {
        i++;
    }

    fclose(arquivo);

    // Ordena os jogadores em ordem decrescente de pontos
    qsort(jogadores, i, sizeof(JogadorPonto), comparaPontos);

    // Aloca um novo vetor para armazenar apenas os top 5 jogadores
    JogadorPonto *topJogadores = malloc(i * sizeof(JogadorPonto));
    if (topJogadores == NULL) {
        free(jogadores);  // Libera a memória do vetor original
        return NULL;
    }

    // Copia os top jogadores para o novo vetor
    for (int j = 0; j < i; j++) {
        topJogadores[j] = jogadores[j];
    }

    // Libera a memória do vetor original
    free(jogadores);

    return topJogadores;  // Retorna o vetor com os top jogadores. Lembrar de executar free(topJogadores) após imprimi-los
}


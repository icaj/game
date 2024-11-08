#include <score.h>
#include <stdlib.h>

// Função para salvar o ponto de um jogador no arquivo
void salvarJogador(JogadorPonto jogador) {
    FILE *arquivo = fopen("scores.txt", "a");
    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    fprintf(arquivo, "%s %d\n", jogador.nome, jogador.ponto);
    fclose(arquivo);
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
        printf("Erro na abertura do arquivo!\n");
        exit(1);
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
JogadorPonto *lerJogadores(int quantidade) {
    FILE *arquivo = fopen("scores.txt", "r");
    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    // Aloca memória para o vetor de jogadores com base na quantidade obtida
    JogadorPonto *jogadores = malloc(quantidade * sizeof(JogadorPonto));
    if (jogadores == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(arquivo, "%9s %d", jogadores[i].nome, &jogadores[i].ponto) == 2) {
        i++;
    }

    fclose(arquivo);

    // Ordena os jogadores em ordem decrescente de pontos
    qsort(jogadores, quantidade, sizeof(JogadorPonto), comparaPontos);

    // Determina o número de jogadores a retornar (5 ou menos, se houver menos jogadores)
    int limite;
    if (quantidade < 5) {
        limite = quantidade;
    } else {
        limite = 5;
    }

    // Aloca um novo vetor para armazenar apenas os top 5 jogadores
    JogadorPonto *topJogadores = malloc(limite * sizeof(JogadorPonto));
    if (topJogadores == NULL) {
        printf("Erro ao alocar memória para topJogadores!\n");
        free(jogadores);  // Libera a memória do vetor original
        exit(1);
    }

    // Copia os top jogadores para o novo vetor
    for (int j = 0; j < limite; j++) {
        topJogadores[j] = jogadores[j];
    }

    // Libera a memória do vetor original
    free(jogadores);

    return topJogadores;  // Retorna o vetor com os top jogadores. Lembrar de executar free(topJogadores) após imprimi-los
}


#include <stdio.h>


#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Tabuleiro do jogo
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

// Função para inicializar o tabuleiro
void inicializaTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }
}

// Função para posicionar um navio horizontalmente
void posicionaNavioHorizontal(int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // Navio
    }
}

// Função para posicionar um navio verticalmente
void posicionaNavioVertical(int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // Navio
    }
}

// Função para exibir o tabuleiro
void exibeTabuleiro() {
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    // Inicializa o tabuleiro
    inicializaTabuleiro();

    // Posiciona os navios
    int linhaNavio1 = 2;
    int colunaNavio1 = 3;
    posicionaNavioHorizontal(linhaNavio1, colunaNavio1);

    int linhaNavio2 = 5;
    int colunaNavio2 = 8;
    posicionaNavioVertical(linhaNavio2, colunaNavio2);

    // Exibe o tabuleiro
    exibeTabuleiro();

    return 0;
}
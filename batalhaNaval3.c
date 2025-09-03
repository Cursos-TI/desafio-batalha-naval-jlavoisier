
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

void inicializaTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }
}

void criaMatrizCone() {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE - 1) / 2 - i && j <= (TAMANHO_HABILIDADE - 1) / 2 + i) {
                cone[i][j] = 1; // Área afetada
            } else {
                cone[i][j] = 0; // Área não afetada
            }
        }
    }
}

void criaMatrizCruz() {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == (TAMANHO_HABILIDADE - 1) / 2 || j == (TAMANHO_HABILIDADE - 1) / 2) {
                cruz[i][j] = 1; // Área afetada
            } else {
                cruz[i][j] = 0; // Área não afetada
            }
        }
    }
}

void criaMatrizOctaedro() {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - (TAMANHO_HABILIDADE - 1) / 2) + abs(j - (TAMANHO_HABILIDADE - 1) / 2) <= (TAMANHO_HABILIDADE - 1) / 2) {
                octaedro[i][j] = 1; // Área afetada
            } else {
                octaedro[i][j] = 0; // Área não afetada
            }
        }
    }
}

void aplicaHabilidade(int linha, int coluna, int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1 && linha + i - (TAMANHO_HABILIDADE - 1) / 2 >= 0 && linha + i - (TAMANHO_HABILIDADE - 1) / 2 < TAMANHO_TABULEIRO && coluna + j - (TAMANHO_HABILIDADE - 1) / 2 >= 0 && coluna + j - (TAMANHO_HABILIDADE - 1) / 2 < TAMANHO_TABULEIRO) {
                tabuleiro[linha + i - (TAMANHO_HABILIDADE - 1) / 2][coluna + j - (TAMANHO_HABILIDADE - 1) / 2] = 5; // Área afetada
            }
        }
    }
}

void imprimeTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("X "); // Área afetada
            }
        }
        printf("\n");
    }
}

int main() {
    inicializaTabuleiro();
    criaMatrizCone();
    criaMatrizCruz();
    criaMatrizOctaedro();

    // Posiciona umm navio no tabuleiro
    tabuleiro[5][5] = 3;
    tabuleiro[5][6] = 3;
    tabuleiro[5][7] = 3;

    // aplica a ahbilidade cone 
    aplicaHabilidade(5, 5, cone);


    // imprime o tabuleiro
    imprimeTabuleiro();

    return 0;

}

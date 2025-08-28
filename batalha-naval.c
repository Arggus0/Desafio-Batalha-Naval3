#include <stdio.h>

#define TAM 8

void zeraTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = 0;
}

void imprimeTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

/* Movimentação do Bispo (diagonais) */
void movimentaBispo(int tab[TAM][TAM], int lin, int col) {
    for (int i = 1; i < TAM; i++) {
        if (lin + i < TAM && col + i < TAM) tab[lin + i][col + i] = 1;
        if (lin - i >= 0 && col - i >= 0) tab[lin - i][col - i] = 1;
        if (lin + i < TAM && col - i >= 0) tab[lin + i][col - i] = 1;
        if (lin - i >= 0 && col + i < TAM) tab[lin - i][col + i] = 1;
    }
}

/* Movimentação da Torre (linha e coluna) */
void movimentaTorre(int tab[TAM][TAM], int lin, int col) {
    for (int i = 0; i < TAM; i++) {
        if (i != lin) tab[i][col] = 2; // coluna
        if (i != col) tab[lin][i] = 2; // linha
    }
}

/* Movimentação da Rainha (combina Torre + Bispo) */
void movimentaRainha(int tab[TAM][TAM], int lin, int col) {
    movimentaTorre(tab, lin, col);
    movimentaBispo(tab, lin, col);
    // Marca o centro como Rainha
    tab[lin][col] = 3;
}

/* Movimentação do Cavalo */
void movimentaCavalo(int tab[TAM][TAM], int lin, int col) {
    int movL[] = {2, 2, -2, -2, 1, -1, 1, -1};
    int movC[] = {1, -1, 1, -1, 2, 2, -2, -2};

    for (int i = 0; i < 8; i++) {
        int nl = lin + movL[i];
        int nc = col + movC[i];

        // se sair do tabuleiro, ignora e continua
        if (nl < 0 || nl >= TAM || nc < 0 || nc >= TAM) {
            continue;
        }

        // Exemplo de uso de break (parar após encontrar a primeira posição válida)
        // -> Se quiser ver só o primeiro movimento possível, descomente:
        // tab[nl][nc] = 4; break;

        tab[nl][nc] = 4;
    }
}

int main() {
    int tab[TAM][TAM];

    printf("=== Movimentação do Bispo (posição central [3,3]) ===\n");
    zeraTabuleiro(tab);
    movimentaBispo(tab, 3, 3);
    tab[3][3] = 9; // marca a posição da peça
    imprimeTabuleiro(tab);

    printf("\n=== Movimentação da Torre (posição central [3,3]) ===\n");
    zeraTabuleiro(tab);
    movimentaTorre(tab, 3, 3);
    tab[3][3] = 9;
    imprimeTabuleiro(tab);

    printf("\n=== Movimentação da Rainha (posição central [3,3]) ===\n");
    zeraTabuleiro(tab);
    movimentaRainha(tab, 3, 3);
    imprimeTabuleiro(tab);

    printf("\n=== Movimentação do Cavalo (posição central [3,3]) ===\n");
    zeraTabuleiro(tab);
    movimentaCavalo(tab, 3, 3);
    tab[3][3] = 9;
    imprimeTabuleiro(tab);

    return 0;
}
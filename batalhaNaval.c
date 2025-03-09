#include <stdio.h>

void exibe_tabuleiro(int tabuleiro[10][10]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" 0 "); 
            else if (tabuleiro[i][j] == 3)
                printf(" 3 "); 
            else if (tabuleiro[i][j] == 5)
                printf(" 5 "); 
        }
        printf("\n");
    }
}

void habilidade_cone(int tabuleiro[10][10], int x, int y) {
    int tamanho = 3;

    for (int i = 0; i < tamanho; i++) {
        for (int j = -i; j <= i; j++) {
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
                tabuleiro[nx][ny] = 5;
            }
        }
    }
}

void habilidade_cruz(int tabuleiro[10][10], int x, int y) {

    for (int i = 0; i < 10; i++) {
        if (x + i < 10 && x + i >= 0) {
            tabuleiro[x + i][y] = 5; 
        }
        if (y + i < 10 && y + i >= 0) {
            tabuleiro[x][y + i] = 5; 
        }
    }
}

void habilidade_octaedro(int tabuleiro[10][10], int x, int y) {
    int tamanho = 3;

    for (int i = -tamanho; i <= tamanho; i++) {
        for (int j = -tamanho; j <= tamanho; j++) {
            if (abs(i) + abs(j) <= tamanho) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
                    tabuleiro[nx][ny] = 5;
                }
            }
        }
    }
}

int main() {

    int tabuleiro[10][10] = {{0}};
    

    tabuleiro[5][2] = 3;
    tabuleiro[5][3] = 3;
    tabuleiro[5][4] = 3;

    tabuleiro[2][8] = 3;
    tabuleiro[3][8] = 3;
    tabuleiro[4][8] = 3;


    int origem_cone_x = 2, origem_cone_y = 4;
    int origem_cruz_x = 5, origem_cruz_y = 5;
    int origem_octaedro_x = 6, origem_octaedro_y = 6;


    habilidade_cone(tabuleiro, origem_cone_x, origem_cone_y);
    habilidade_cruz(tabuleiro, origem_cruz_x, origem_cruz_y);
    habilidade_octaedro(tabuleiro, origem_octaedro_x, origem_octaedro_y);
    

    exibe_tabuleiro(tabuleiro);

    return 0;
}

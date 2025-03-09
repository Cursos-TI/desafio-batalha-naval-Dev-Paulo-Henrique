#include <stdio.h>

// Função para verificar se a posição do navio está dentro dos limites do tabuleiro
int valida_posicao(int tabuleiro[10][10], int x, int y, int tamanho, char direcao) {
    // Verifica se a posição do navio está dentro do tabuleiro e se não há sobreposição
    if (direcao == 'H') {  // Horizontal
        if (y + tamanho > 10) return 0;  // Sai do limite
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x][y + i] != 0) return 0;  // Há sobreposição
        }
    } else if (direcao == 'V') {  // Vertical
        if (x + tamanho > 10) return 0;  // Sai do limite
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y] != 0) return 0;  // Há sobreposição
        }
    } else if (direcao == 'D') {  // Diagonal (crescente)
        if (x + tamanho > 10 || y + tamanho > 10) return 0;  // Sai do limite
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y + i] != 0) return 0;  // Há sobreposição
        }
    } else if (direcao == 'A') {  // Diagonal (decrescente)
        if (x + tamanho > 10 || y - tamanho < -1) return 0;  // Sai do limite
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y - i] != 0) return 0;  // Há sobreposição
        }
    }
    return 1;  // Posição válida
}

// Função para posicionar o navio no tabuleiro
void posiciona_navio(int tabuleiro[10][10], int x, int y, int tamanho, char direcao) {
    if (direcao == 'H') {  // Horizontal
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x][y + i] = 3;
        }
    } else if (direcao == 'V') {  // Vertical
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x + i][y] = 3;
        }
    } else if (direcao == 'D') {  // Diagonal (crescente)
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x + i][y + i] = 3;
        }
    } else if (direcao == 'A') {  // Diagonal (decrescente)
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[x + i][y - i] = 3;
        }
    }
}

int main() {
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {{0}};
    
    // Tamanho dos navios
    int tamanho_navio = 3;
    
    // Posicionando navios horizontalmente
    if (valida_posicao(tabuleiro, 5, 2, tamanho_navio, 'H')) {
        posiciona_navio(tabuleiro, 5, 2, tamanho_navio, 'H');
    }
    
    // Posicionando navios verticalmente
    if (valida_posicao(tabuleiro, 2, 8, tamanho_navio, 'V')) {
        posiciona_navio(tabuleiro, 2, 8, tamanho_navio, 'V');
    }
    
    // Posicionando navios diagonalmente (crescente)
    if (valida_posicao(tabuleiro, 1, 1, tamanho_navio, 'D')) {
        posiciona_navio(tabuleiro, 1, 1, tamanho_navio, 'D');
    }
    
    // Posicionando navios diagonalmente (decrescente)
    if (valida_posicao(tabuleiro, 3, 7, tamanho_navio, 'A')) {
        posiciona_navio(tabuleiro, 3, 7, tamanho_navio, 'A');
    }
    
    // Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("  %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

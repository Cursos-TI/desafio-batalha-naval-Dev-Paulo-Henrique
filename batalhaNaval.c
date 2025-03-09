#include <stdio.h>

int main(){

int tabuleiro[10][10] = {{0}};

int navio_1[3] = {3, 3, 3};   

int navio_2[3] = {3, 3, 3};   

tabuleiro[5][2] = navio_1[0]; 
tabuleiro[5][3] = navio_1[1];   
tabuleiro[5][4] = navio_1[2];

tabuleiro[2][8] = navio_1[0]; 
tabuleiro[3][8] = navio_1[1];   
tabuleiro[4][8] = navio_1[2];


for (int i = 0; i < 10 ; i++){
         for (int j = 0; j < 10; j++)
            printf("  %d", tabuleiro[i][j]);
         printf("\n");
}
    


    return 0;
}
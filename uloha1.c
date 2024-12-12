#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv){

    if(argc != 3){
        printf("chyba");
        return 1;
    }

    int m = atoi(argv[1]);
    int p = atoi(argv[2]);

    if(m <= 0){
        printf("velikost matice musi byt kladne cislo\n");
        return 1;
    }

    char matice[100][100];

    if(m > 100){
        printf("chyba");
    }

    char x[101];
    for(int i = 0; i < m; i++) {
        if(fgets(x, sizeof(x), stdin) != NULL){
            for(int j = 0; j < m; j++){
                matice[j][i] = x[j];
            }
        }
    }

    printf("zadal si: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf(" %c", matice[j][i]);
        }
        printf("\n");
    }

    int px = 0;
    int py = 0;
    char smer;

    for(int i = 0; i < p; i++){
        if(fgets(x, sizeof(x), stdin) != NULL){

            char *token = strtok(x, " ");
            if(token != NULL){
                px = atoi(token);
            }

            token = strtok(NULL, " ");
            if(token != NULL){
                py = atoi(token);
            }

            token = strtok(NULL, " ");
            if(token != NULL){
                smer = token[0];
            }
            printf("px %d py %d smer %c\n", px, py, smer);
        }

        if(smer == 'H'){
            for(int i = px; i < m; i++){
                if(matice[i][py] == 'X'){
                    break;
                }

                if(matice[i][py] == 'T'){
                    matice[i][py] = '.';
                }
            }
        }

        else if(smer == 'V'){
            for(int j = py; j < m; j++){
                if(matice[px][j] == 'X'){
                    break;
                }

                if(matice[px][j] == 'T'){
                    matice[px][j] = '.';
                }
            }
        }

        else if (smer == 'L') { // Diagonála zleva nahoře do prava dole
            for (int i = 0; px + i < m && py + i < m; i++) {
                if (matice[px + i][py + i] == 'X') {
                    break;
                }

                if (matice[px + i][py + i] == 'T') {
                    matice[px + i][py + i] = '.';
                }
            }
        }

        else if (smer == 'R') { // Diagonála zprava nahoře do leva dole
            for (int i = 0; px - i >= 0 && py + i < m; i++) {
                if (matice[px - i][py + i] == 'X') {
                    break;
                }

                if (matice[px - i][py + i] == 'T') {
                    matice[px - i][py + i] = '.';
                }
            }
        }

        else{
            break;
        }
    }

    printf("vysledek je: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf(" %c", matice[j][i]);
        }
        printf("\n");
    }

    // Výpis pozic zbývajících 'T'
    printf("\nPozice nezmenenych T:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(matice[j][i] == 'T'){
                printf("(%d, %d)\n", j, i);
            }
        }
    }


    
    return 0;
}
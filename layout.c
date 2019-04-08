#include <string.h>
#include "layout.h"
#include "main.h"

void inputKomponen(char *layout[42][42][2], int M, int N, int kakiMax, int jarakMin, char komponen[2]){

}

void layoutManual(char *layout[42][42][2], int M, int N){
    char komponen[20][2];
    int i, j;
    int kakiMax;
    int jarakMin;
    int statusLayout;
    // Konvensi statusLayout
    // 1 = baca nama komponen
    // 2 = baca koordinat komponen
    // Selain itu keluar dari program

    emptyLayout(layout);
    printf("Isi 'q' atau 'Q' untuk kembali ke menu");
    i=0;

    statusLayout = 1;
    do{
        printf("Pilih Komponen (R,C,T,J): ");
        scanf("%s", &komponen[i]);
        if (strcmp(komponen[i], "q") == 0 || strcmp(komponen[i], "Q")==0){
            statusLayout = 3;
            break;
        }
        
        j = 0;
        while (j<=i){
            if (strcmp(komponen[i],komponen[j]) == 0){
                statusLayout = 1;
                printf("Nama komponen tidak bisa degnan nama komponen yang telah ada sebelumnya");
                break;
            }
        }
        
        if (statusLayout == 1){
            break;
        }

        switch(komponen[i][0]){
            case 'R':
                kakiMax = 2;
                jarakMin = 3;
                inputKomponen(layout, M, N, kakiMax, jarakMin, komponen[i]);
                i++;
                break;
            case 'C':
                kakiMax = 2;
                jarakMin = 1;
                inputKomponen(layout, M, N, kakiMax, jarakMin, komponen[i]);
                i++;
                break;
            case 'J':
                kakiMax = 2;
                jarakMin = 0;
                inputKomponen(layout, M, N, kakiMax, jarakMin, komponen[i]);
                i++;
                break;
            case 'T':
                kakiMax = 3;
                jarakMin = 1;
                inputKomponen(layout, M, N, kakiMax, jarakMin, komponen[i]);
                i++;
                break;
            default:
                printf('Tidak ada komponen dengan keyword tersebut');
                statusLayout = 1;
        }
    } while (statusLayout == 1);
}
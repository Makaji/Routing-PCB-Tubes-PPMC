#include <string.h>
#include "layout.h"
#include "main.h"

void inputKomponen(char layoutFunc[42][42][3], int M, int N, int kakiMax, int jarakMin, char komponen[3]){
    char layout[42][42][3];
    int i;
    int j;
    int k;
    char strKoor[5];
    koordinat_t kaki[3];
    int arah;
    int jarak;
    int isValid;
    // Konvensi arah
    // 0 = Inisiasi
    // 1 = Atas (x tetap, y berkurang)
    // 2 = Bawah (x tetap, y bertambah)
    // 3 = Kanan (x bertambah, y tetap)
    // 4 = Kiri (x berkurang, y tetap)

    for(i = 1; i<=M; i++){
        for(j = 1; j<=N; j++){
            for(k=1;k<3;k++){
                layout[i][j][k]=layoutFunc[i][j][k];
            }
        }
    }

    i = 0;
    arah = 0;

    do{
        printf("Koordinat kaki %d: ", i+1);
        scanf("%s", &strKoor);
        konversiKoor(strKoor, &kaki[i].x, &kaki[i].y);
        if ((kaki[i].x>=1 && kaki[i].x <= M) && (kaki[i].y>=1 && kaki[i].y <= N)){
            switch (i){
            case 0:
                strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                i++;
                break;
            case 1:
                if (kaki[i].x==kaki[i-1].x){
                    jarak = kaki[i].y-kaki[i-1].y;
                    if (jarak>jarakMin){
                        strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                        i++;
                        arah = 2;
                    }
                    else{
                        if (jarak<((-1)*jarakMin)){
                            strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                            i++;
                            arah = 1;
                        }
                        else{
                            printf("Jarak kurang dari syarat\n");
                        }
                    }
                }
                else {
                    if (kaki[i].y==kaki[i-1].y){
                        jarak = kaki[i].x-kaki[i-1].x;
                        if (jarak>jarakMin){
                            strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                            i++;
                            arah = 3;
                        }
                        else{
                            if (jarak<((-1)*jarakMin)){
                                strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                                i++;
                                arah = 4;
                            }
                            else{
                                printf("Jarak kurang dari syarat\n");
                            }
                        }
                    }
                    else{
                        printf("Komponen tidak boleh miring");
                    }
                }
                break;
            case 2:
                isValid = 1;
                switch (arah){
                case 1:
                    if(kaki[i].y-kaki[i-1].y>0){
                        isValid = 0;
                        printf("Sesuaikan dengan arah\n");
                    }
                    break;
                case 2:
                    if(kaki[i].y-kaki[i-1].y<0){
                        isValid = 0;
                        printf("Sesuaikan dengan arah\n");
                    }
                    break;
                case 3:
                    if(kaki[i].x-kaki[i-1].x<0){
                        isValid = 0;
                        printf("Sesuaikan dengan arah\n");
                    }
                    break;
                case 4:
                    if(kaki[i].x-kaki[i-1].x>0){
                        isValid = 0;
                        printf("Sesuaikan dengan arah\n");
                    }
                    break;
                default:
                    isValid = 0;
                }
                if (isValid == 1){
                    if (kaki[i].x==kaki[i-1].x){
                        jarak = kaki[i].y-kaki[i-1].y;
                        if (jarak>jarakMin){
                            strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                            i++;
                            arah = 2;
                        }
                        else{
                            if (jarak<((-1)*jarakMin)){
                                strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                                i++;
                                arah = 1;
                            }
                            else{
                                printf("Jarak kurang dari syarat\n");
                            }
                        }
                    }
                    else {
                        if (kaki[i].y==kaki[i-1].y){
                            jarak = kaki[i].x-kaki[i-1].x;
                            if (jarak>jarakMin){
                                strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                                i++;
                                arah = 3;
                            }
                            else{
                                if (jarak<((-1)*jarakMin)){
                                    strcpy(layout[kaki[i].x][kaki[i].y], komponen);
                                    i++;
                                    arah = 4;
                                }
                                else{
                                    printf("Jarak kurang dari syarat\n");
                                }
                            }
                        }
                        else{
                            printf("Komponen tidak boleh miring");
                        }
                    }
                }
            }
        }
        else{
            printf("Koordinat tidak boleh melewati batas\n");
        }
    }while (i<kakiMax);

    for(i = 1; i<=M; i++){
        for(j = 1; j<=N; j++){
            for(k=0;k<3;k++){
                layoutFunc[i][j][k]=layout[i][j][k];
            }
        }
    }
    return;
}

void layoutManual(char layoutFunc[42][42][3], int M, int N){
    char layout[42][42][3];
    char komponen[20][3];
    int i, j, k;
    int kakiMax;
    int jarakMin;
    int statusLayout;
    int isValid;
    // Konvensi statusLayout
    // 1 = baca nama komponen
    // 2 = baca koordinat komponen
    // Selain itu keluar dari program

    for(i = 1; i<=M; i++){
        for(j = 1; j<=N; j++){
            strcpy(layout,layoutFunc);
        }
    }

    // Mereset array
    for(i = 0; i<=M; i++){
        for(j = 0; j<=N; j++){
            for(k=0;k<3;k++){
                layout[i][j][k]=0;
            }
        }
    }

    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    i=0;
    for(j = 0;j<20;j++){
        for (k = 0;k<3;k++){
            komponen[j][k] = 0;
        }
    }
    isValid = 1;
    statusLayout = 1;
    do{
        isValid = 1;
            printf("Pilih Komponen (R,C,T,J): ");
            scanf("%s", &komponen[i]);

            if (strcmp(komponen[i], "q") == 0 || strcmp(komponen[i], "Q")==0){
                return 0;
            }

        for(j = 0;j<3;j++){
            printf("%c\n", komponen[i][j]);
        }
        switch(komponen[i][0]){
            case 'R':
                kakiMax = 2;
                jarakMin = 3;
                inputKomponen(layout, M, N, kakiMax, jarakMin, komponen[i]);
                i++;
                statusLayout = 1;
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
                statusLayout = 1;
                break;
            case 'T':
                kakiMax = 3;
                jarakMin = 1;
                inputKomponen(layout, M, N, kakiMax, jarakMin, komponen[i]);
                i++;
                statusLayout = 1;
                break;
            default:
                printf("Tidak ada komponen dengan keyword tersebut\n");
                statusLayout = 1;
            }
            cetakLayout(layout, M, N);
    }while (statusLayout == 1);

    for(i = 1; i<=M; i++){
        for(j = 1; j<=N; j++){
            strcpy(layoutFunc,layout);
        }
    }
}
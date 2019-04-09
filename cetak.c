#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cetak.h"

int i, j, m, n;
char L[42][42][3];
char R[42][42];

void cetakLayout(char L[42][42][3],int m, int n){
    printf("  ");
    for (i=1;i<=m;i++){
        printf("%10d",(i));
    }
    printf("\n");
    for (i=1;i<=n;i++){
        if (i<10){
            for (j=0;j<1;j++){
                printf("%d",i);
            }
            for (j=1;j<=m;j++){
                printf(" %10s",L[i][j]);
            }
        } else{
            for (j=0;j<1;j++){
                printf("%d",i);
            }
            for (j=1;j<=m;j++){
                printf("%10s",L[i][j]);
            }
        }
        printf ("\n");
    }
}

void cetakRouting(char R[42][42], int m, int n){
    //R[10][1]='@'; buat ngetes doang
    //R[10][10]='*'; buat ngetes doang
    printf("  ");
    for (i=0;i<m;i++){
        printf("%10d",(i+1));
    }
    printf("\n");
    for (i=1;i<=n;i++){
        printf("%d",i);
        for (j=1;j<=m;j++){
            printf("%10c",R[i][j]);
        }
        printf("\n");
    }
}

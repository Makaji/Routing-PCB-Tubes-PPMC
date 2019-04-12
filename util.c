//**********************************************************//
//						[Source Code]						//
//															//
// Institution		: Institut Teknologi Bandung			//
// Name				: <Nama Praktikan>						//
// File Name		: util.c								//
// Dependency		: stdio.h, string.h, stdlib.h, main.h	//
//															//
// Description:												//
//	This program declares the utility functions that may be	//
//	called by multiple functions in multiple files.			//
//															//
// Status:													//
// 1. Gede Satya A D 	- 13217016 : Membuat file			//
// 2. <Nama Praktikan> 	- <NIM>	   : Fix the bug where num-	//
//	  ber 2 is printed twice								//
//															//
//**********************************************************//

#include "main.h"

// Implementasi fungsional
void konversiKoor(char strIn[50], int *aIn, int *bIn){
// Program ini mengkonversi input koordinat dari bentuk string menjadi dua integer terpisah
// jika salah satu nilai integer bernilai 0, maka input invalid.
	// Deklarasi variabel lokal
	char str[50];
	char *token;
    const char delim[2]=",";
    int a;
    int b;

	// Algoritma fungsi
	strcpy(str, strIn);
	token = strtok(str, delim);
    a = atoi(token);
    *aIn = a;

    token = strtok(NULL, delim);
    b = atoi(token);
    *bIn = b;
    return;
}

// Utilitas
void emptyRoute(routing_t route[42][42]){
    int i;
    int j;
    for (i=0;i<42;i++){
        for(j=0;j<42;j++){
            route[i][j].sym=32;
            route[i][j].node = 0;
        }
    }
}

void emptyLayout(char layout[42][42][3]){
    int i, j, k;
        for(i = 1; i<42; i++){
        for(j = 1; j<42; j++){
            for(k=0;k<3;k++){
                layout[i][j][k]=0;
            }
        }
    }
}

void cetakRoutingNode(routing_t R[42][42], int m, int n){
    //R[10][1]='@'; buat ngetes doang
    //R[10][10]='*'; buat ngetes doang
    int i;
    int j;

    printf("  ");
    for (i=0;i<m;i++){
        printf("%5d",(i+1));
    }
    printf("\n");
    for (i=1;i<=n;i++){
        printf("%2d",i);
        for (j=1;j<=m;j++){
            printf("%5d",R[j][i].node);
        }
        printf("\n");
    }
    return;
}
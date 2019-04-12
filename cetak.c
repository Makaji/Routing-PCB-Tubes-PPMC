//**********************************************************//
//						[Source Code]						//
//															//
// Institution		: Institut Teknologi Bandung			//
// Name				: <Nama Praktikan>						//
// File Name		: mode.c								//
// Dependency		: stdio.h, string.h, stdlib.h, main.h,	//
// cetak.h, layout.h, routing.h								//
//															//
// Description:												//
//	This program executes the features that is included in	//
//	the whole program after a file is declared in menu.		//
//	The program returns after the operator is inputted to 	//
//	save and exit											//
// 															//
// Status:													//
// 1. <Nama Praktikan>	- <NIM>    : Membuat file			//
// 2. Gede Satya A D 	- 13217016 : Fix the bug where num-	//
//	  ber 2 is printed twice								//
//															//
//**********************************************************//

#include "main.h"
#include "cetak.h"
#include "main.h"

void cetakLayout(char L[42][42][3],int m, int n){
    int i;
    int j;

    printf("  ");
    for (i=1;i<=m;i++){
        printf("%5d",(i));
    }
    printf("\n");
    for (i=1;i<=n;i++){
            for (j=0;j<1;j++){
                printf("%2d",i);
            }
            for (j=1;j<=m;j++){
                printf(" %4s",L[j][i]);
            }
        printf ("\n");
    }
    return;
}

void cetakRouting(routing_t R[42][42], int m, int n){
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
            printf("%5c",R[j][i].sym);
        }
        printf("\n");
    }
    return;
}
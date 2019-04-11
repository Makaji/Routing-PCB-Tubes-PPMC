//
//  HasilKaliDuaFungsi.c
//  Wicak
//
//  Created by RIDHWAN AW on 29/01/19.
//  Copyright © 2019 RIDHWAN AW. All rights reserved.
//

#include<stdio.h>
#include<math.h>


void loadRouting(char arr[42][42],int* m, int* n,char NamaFile[20])
{
    FILE *f1;
    f1 =fopen(NamaFile,"r");
    //Membuka file yang ingin ditulis dengan fungsi
    int i,j,M,N;
    char s[40];
    char arrayC[42][42];
    if (f1 != NULL)
    {
        //Create Code to Read that fucking file
        // into an array of char
        fscanf(f1,"%d,%d,%s",&M,&N,&s);
        printf("%d %d \n",M,N);
        //printf("%s",&s);
        for (i=0;i<1+N;i++){
            for (j=0;j<1+M;j++){
                fscanf(f1,"%c,",&arrayC[i+1][j]);
            }
        }
        for (i=0;i<N;i++){
            for (j=0;j<M;j++){
                printf("%d.%d :%c  ",i+1,j+1,arrayC[i+1][j+1]);
            }
            printf("\n");
            // printf("\n");
        }
    } else {
        printf("Failed to write file\n");
    }

    for (i=0;i<=N;i++){
            for (j=0;j<=M;j++){
				arr[i][j] = arrayC[i][j];
                //copyChar(arr[i][j],&arrayC[i][j]);
            }
        }
    *m=M;
    *n=N;
    printf ("\n\n %d %d \n\n",M,N);
    for (i=1;i<=N;i++){
        for (j=1;j<=M;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }

    //Closing file
    fclose(f1);
    //Print array di sini dengna iterasi MN int
}

int main(){
	char arr[42][42];
	int baris,kolom;
	int i,j;
	char NamaFile [20];
	strcpy(NamaFile,"mode.csv");
	arr[0][0] = 'a';
	loadRouting(arr,&baris,&kolom,&NamaFile);
	printf ("\n\n\n");
	for (i=1;i<=kolom;i++){
        for (j=1;j<=baris;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }

	return 0;
}

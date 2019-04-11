//
//  HasilKaliDuaFungsi.c
//  Wicak
//
//  Created by RIDHWAN AW on 29/01/19.
//  Copyright � 2019 RIDHWAN AW. All rights reserved.
//

#include<stdio.h>
#include<math.h>
#include<string.h>

float vc (float x);

void saveRouting(char arr[42][42],char NamaFile[20], int* m, int* n)
{
    FILE *f1;
    f1 =fopen(NamaFile,"w");
    //Membuka file yang ingin ditulis dengan fungsi
    int i,j,M,N;
    char arrayC[42][42];
    M=*m;
    N=*n;
    for (i=0;i<=N;i++){
            for (j=0;j<=M;j++){
				 arrayC[i][j]=arr[i][j];
                //copyChar(arr[i][j],&arrayC[i][j]);
            }
        }

    if (f1 != NULL)
    {
        fprintf(f1,"%d,%d\n",M,N);
        for (i=1;i<=N;i++){
            for (j=1;j<=M;j++){
                fprintf(f1,"%c,",arrayC[i][j]);
            }
            fprintf(f1,"\n");
        }


    } else {
        printf("Failed to write file.\n");
    }
    //Closing file
    fclose(f1);
    //Print array di sini dengna iterasi MN int
}

int main(){
    char NamaFile[20];
    char arrayC[42][42];
    arrayC[1][1]='!';
    arrayC[1][2]='1';
    arrayC[1][3]='1';
    arrayC[1][4]='1';
    arrayC[1][5]='1';
    arrayC[1][6]='1';
    arrayC[1][7]='2';
    arrayC[2][1]='3';
    arrayC[2][2]='4';
    arrayC[2][3]='5';
    arrayC[2][4]='6';
    arrayC[2][5]='7';
    arrayC[2][6]='1';
    arrayC[2][7]=' ';
    arrayC[3][1]='2';
    arrayC[3][2]=' ';
    arrayC[3][3]=' ';
    arrayC[3][4]='4';
    arrayC[3][5]='5';
    arrayC[3][6]=' ';
    arrayC[3][7]=' ';
    arrayC[4][1]='!';
    arrayC[4][2]='!';
    arrayC[4][3]='!';
    arrayC[4][4]='$';
    arrayC[4][5]='$';
    arrayC[4][6]='!';
    arrayC[4][7]='!';
    arrayC[5][1]='!';
    arrayC[5][2]='1';
    arrayC[5][3]='2';
    arrayC[5][4]='5';
    arrayC[5][5]='9';
    arrayC[5][6]='!';
    arrayC[5][7]='!';
    strcpy(NamaFile,"mode.csv");
    int M=7;
    int N=5;
    saveRouting(arrayC,&NamaFile,&M,&N);
    return 0;
}

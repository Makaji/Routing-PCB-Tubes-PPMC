// scanf("%*[^,]%*c");
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


int main()
{
    FILE *f1;
    f1 =fopen("save_layout.csv","w");
    //Membuka file yang ingin ditulis dengan fungsi
    int i,j,M,N;
    M=7;
    N=5;
    char arrayC[42][42][3];
    strcpy(arrayC[1][1],"C1");
    strcpy(arrayC[1][2]," ");
    strcpy(arrayC[1][3]," ");
    strcpy(arrayC[1][4]," ");
    strcpy(arrayC[1][5]," ");
    strcpy(arrayC[1][6],"C1");
    strcpy(arrayC[1][7],"F1");
    strcpy(arrayC[2][1],"F1");
    strcpy(arrayC[2][2]," ");
    strcpy(arrayC[2][3]," ");
    strcpy(arrayC[2][4]," ");
    strcpy(arrayC[2][5]," ");
    strcpy(arrayC[2][6]," ");
    strcpy(arrayC[2][7]," ");
    strcpy(arrayC[3][1]," ");
    strcpy(arrayC[3][2]," ");
    strcpy(arrayC[3][3]," ");
    strcpy(arrayC[3][4],"L1");
    strcpy(arrayC[3][5],"L1");
    strcpy(arrayC[3][6]," ");
    strcpy(arrayC[3][7]," ");
    strcpy(arrayC[4][1]," ");
    strcpy(arrayC[4][2]," ");
    strcpy(arrayC[4][3]," ");
    strcpy(arrayC[4][4]," ");
    strcpy(arrayC[4][5]," ");
    strcpy(arrayC[4][6]," ");
    strcpy(arrayC[4][7]," ");
    strcpy(arrayC[5][1]," ");
    strcpy(arrayC[5][2]," ");
    strcpy(arrayC[5][3]," ");
    strcpy(arrayC[5][4]," ");
    strcpy(arrayC[5][5]," ");
    strcpy(arrayC[5][6]," ");
    strcpy(arrayC[5][7]," ");

    if (f1 != NULL)
    {
        fprintf(f1,"%d,%d\n",M,N);
        for (i=1;i<=N;i++){
            for (j=1;j<=M;j++){
                fprintf(f1,"%s,",arrayC[i][j]);
            }
            fprintf(f1,"\n");
        }


    } else {
        printf("Failed to write file\n");
    }
    //Closing file
    fclose(f1);
    //Print array di sini dengna iterasi MN int

    return 0;
}

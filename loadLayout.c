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

//float vc (float x);
void loadLayout(char arrayC2[42][42][3], int *m, int *n)
{
    FILE *f1;
    char arrayC[42][42][3];
    f1 =fopen("save_layout.csv","r");
    //Membuka file yang ingin ditulis dengan fungsi
    int i,j,M,N;
    char s[40];
    if (f1 != NULL)
    {
        //Create Code to Read that fucking file
        // into an array of char
        fscanf(f1,"%d,%d,%s",&M,&N,&s);
        fscanf(f1,"%c",&s[0]);
        printf("%d %d \n",M,N);
        //printf("%s",&s);
		char kar;
		for (i=0;i<N;i++){
            for (j=0;j<M;j++){
				for(int z = 0; z<3;z++){
					arrayC[i][j][z]= ' ';
				}
            }
        }
        for (i=0;i< N;i++){
            for (j=0;j<M;j++){
				fscanf(f1,"%c", &kar);
				int z=-1;
				while(kar!=',' && kar !='.' && kar!='\n') {
					z= z+1;
					arrayC[i][j][z] = kar;
					fscanf(f1,"%c", &kar);
				}
                //fscanf(f1,"%[^,]%*c",&arrayC[i+1][1+j]);
            }
        }
        for (i=0;i<N;i++){
            for (j=0;j<M;j++){
				printf("%d.%d :",i+1,j+1);
				for(int z = 0; z<3;z++){
                    arrayC2[i+1][j+1][z] = arrayC[i][j][z];
					printf("%c",arrayC2[i+1][j+1][z]);
				}
            }
            printf("\n");
        }
    } else {
        printf("Failed to write file\n");
    }
    //Closing file
    fclose(f1);
    //Print array di sini dengna iterasi MN int
    *m = M;
    *n = N;

    return ;
}

int main(){
    char lay[42][42][3];
    int M = 7;
    int N = 5;
    int i,j,k;

    for(i = 0;i<=N;i++){
        for (j = 0;j<=M;j++){
            for(k = 0;k<3;k++){
                lay[i][j][k]=32;
            }
        }
    }

    loadLayout(lay, &M, &N);


    printf("%d %d\n", M, N);

    for(i = 1 ; i<=N ; i++){
        for (j = 1; j<=M; j++){
            for(k = 0; k<3; k++){
                printf("%c", lay[i][j][k]);
            }
            printf(";");
        }
        printf("\n");
    }
}

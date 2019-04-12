//**********************************************************//
//						[Source Code]						//
//															//
// Institution		: Institut Teknologi Bandung			//
// Name				: <Nama Praktikan>						//
// File Name		: menu.c								//
// Dependency		: stdio.h, stdlib.h, menu.h, mode.h		//
//															//
// Description:												//
//	This file functions as the menu operator, which can		//
//	create a new file, read an existing file, and let the 	//
//	main program know what to do after this function re-	//
//	turns with status										//
//															//
// Status:													//
// 1. Gede Satya A D 	- 13217016 : Membuat file			//
// 2. Ridhwan Athallah W- 13217010 : Melengkapi fungsional	//
//	  newFile dan loadFile									//
//															//
//**********************************************************//


#include "main.h"
#include "menu.h"

// Konvensi status
// 1 = menu, main akan menjalankan menu jika status berada 
// pada kondisi menu
// 2 = mode, main akan menjalankan mode jika status berada 
// pada kondisi mode
// 3 = end,  main akan mengakhiri program

void loadLayout(char arrayC2[42][42][3], int *m, int *n, char NamaFile[50])
{
    FILE *f1;
    char arrayC[42][42][3];
    f1 =fopen(NamaFile,"r");
    //Membuka file yang ingin ditulis dengan fungsi
    int i,j,M,N;
    char s[40];
    if (f1 != NULL)
    {
        //Create Code to Read file
        // into an array of char
        fscanf(f1,"%d,%d,%s",&M,&N,&s);
        fscanf(f1,"%c",&s[0]);
        printf("%d %d \n",M,N);
        //printf("%s",&s);
		char kar;
		for (i=0;i<N;i++){
            for (j=0;j<M;j++){
				for(int z = 0; z<3;z++){
					arrayC[j][i][z]= ' ';
				}
            }
        }
        for (i=0;i< N;i++){
            for (j=0;j<M;j++){
				fscanf(f1,"%c", &kar);
				int z=-1;
				while(kar!=',' && kar !='.' && kar!='\n') {
					z= z+1;
					arrayC[j][i][z] = kar;
					fscanf(f1,"%c", &kar);
				}
                //fscanf(f1,"%[^,]%*c",&arrayC[i+1][1+j]);
            }
        }
        for (i=0;i<N;i++){
            for (j=0;j<M;j++){
				//printf("%d.%d :",i+1,j+1);
				for(int z = 0; z<3;z++){
                    arrayC2[j+1][i+1][z] = arrayC[j][i][z];
					//printf("%c",arrayC2[i+1][j+1][z]);
				}
            }
            //printf("\n");
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

void loadRouting(routing_t arr[42][42],int* m, int* n,char NamaFile[50])
{
//  Wicak
//
//  Created by RIDHWAN AW on 29/01/19.
//  Copyright � 2019 RIDHWAN AW. All rights reserved.
    FILE *f1;
    f1 =fopen(NamaFile,"r");
    //Membuka file yang ingin ditulis dengan fungsi
    int i,j,M,N;
    char s[40];
    char arrayC[42][42];
    if (f1 != NULL)
    {
        //Create Code to Read file
        // into an array of char
        fscanf(f1,"%d,%d,%s",&M,&N,&s);
        //printf("%d %d \n",M,N);
        //printf("%s",&s);
        for (i=0;i<1+N;i++){
            for (j=0;j<1+M;j++){
                fscanf(f1,"%c,",&arrayC[i+1][j]);
            }
        }
        for (i=0;i<N;i++){
            for (j=0;j<M;j++){
                //printf("%d.%d :%c  ",i+1,j+1,arrayC[i+1][j+1]);
            }
            //printf("\n");
            // printf("\n");
        }
    } else {
        //printf("Failed to write file\n");
    }

    for (i=0;i<=N;i++){
            for (j=0;j<=M;j++){
				arr[j][i].sym = arrayC[j][i];
                //copyChar(arr[i][j],&arrayC[i][j]);
            }
        }
    *m=M;
    *n=N;
    //printf ("\n\n %d %d \n\n",M,N);
    for (i=1;i<=N;i++){
        for (j=1;j<=M;j++){
            //printf("%c ",arr[i][j]);
        }
        //printf("\n");
    }

    //Closing file
    fclose(f1);
    //Print array di sini dengan iterasi MN int
}


void menu(int *status, char fileName1[50], char fileName2[50], int *M, int *N, routing_t routing[42][42], char layout[42][42][3]){
	// Deklarasi
	int ope;
	int i;
	int j;
	int k;
	do {
        printf("Menu:\n   1. Buat Proyek Baru\n   2. Muat Proyek dari Berkas\n   3. Keluar\n");
        printf("Masukan: ");
		scanf("%d", &ope);

		if (ope > 3 || ope < 1){
			printf("Input tidak valid\n");
		}
	} while (ope > 3 || ope < 1);

	//Nama File agar tidak usah dideclare berkali kali
	char NamaFile [50];

	if(ope == 1){
		// Algoritma membuat file baru
		printf("====== Membuat Proyek Baru ======\n");
		printf("Masukkan nama proyek: ");
		scanf("%s", &NamaFile);
		printf("Masukkan ukuran PCB NxM (N,M<40): ");
		scanf("%d %d",M,N);
		strcpy(fileName1,NamaFile);
		strcpy(fileName2,NamaFile);
		strcat(fileName1,"_layout.csv");
		strcat(fileName2,"_routing.csv");
		emptyRoute(routing);
		emptyLayout(layout);

		//Passing program yang ada di laptop becky ke program ini tq satya

		*status = 2;
	}
	else {
		if(ope == 2){
			// Algoritma membuka file lama
			printf("====== Memuat Proyek Lama ======\n");
			printf("Masukkan nama proyek: ");
			scanf("%s", &NamaFile);
			strcpy(fileName1,NamaFile);
			strcpy(fileName2,NamaFile);
			strcat(fileName1,"_layout.csv");
			strcat(fileName2,"_routing.csv");

			emptyRoute(routing);
			for(i = 0;i<=*N;i++){
				for (j = 0;j<=*M;j++){
					for(k = 0;k<3;k++){
						layout[i][j][k]=32;
					}
				}
			}

			loadRouting(routing, M, N, fileName2);
			loadLayout (layout, M, N, fileName1);

			*status = 2;
		}
		else {
			// Membuat status menjadi keluar, karena status
			// yang akan dikenali pada main akan mengarahkan
			// untuk keluar dari program.
			*status = 3;
		}
	}
}

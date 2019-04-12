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
// 1. Gede Satya A D 	- 13217016 : Membuat file			
// 2. <Nama Praktikan> 	- <NIM>	   : Fix the bug where num-	
//	  ber 2 is printed twice								
//															
//**********************************************************

#include "main.h"
#include "mode.h"
#include "cetak.h"
#include "layout.h"
#include "routing.h"

// Deklarasi fungsional untuk eksekusi mode, Design Rule
// Checker, dan penyimpanan File


void mode(int *status, char fileName1[50], char fileName2[50], routing_t route[42][42], char layout[42][42][3], int M, int N){
	int ope;
	int isValid;



	isValid = 0;
	do{
        printf("[Menu Utama]\n");
        printf("Pilih Mode:\n");
        printf("  1. Tampilkan Layout\n");
        printf("  2. Layouting Manual\n");
        printf("  3. Tampilkan Routing\n");
        printf("  4. Routing Manual\n");
        printf("  5. Design Rule Checker\n");
        printf("  6. Simpan Proyek dan Keluar\n");
		printf("Pilih mode : ");
		scanf("%d", &ope);

		switch (ope){
			case 1:
				cetakLayout(layout, M, N);
				isValid = 1;
				break;
			case 2:
				layoutManual(layout, M, N);
				cetakLayout(layout, M, N);
				isValid = 1;
				break;
			case 3:
				cetakRouting(route, M, N);
				isValid = 1;
				break;
			case 4:
				routingManual(route, M, N);
				isValid = 1;
				break;
			case 5:
				drc(route, layout, M, N);
				isValid = 1;
				break;
			case 6:
				saveLayout(layout, M, N, fileName1);
				saveRouting (route, fileName2, &M, &N);
				*status = 1;
				isValid = 1;
				break;
			default:
				printf("Operator tidak valid");
				isValid = 0;
		}
	}while (*status == 2);

}

void drc (routing_t routing[42][42], char layout[42][42][3], int M, int N){
	// Deklarasi variabel lokal
	char data[50];
	char filename[50];
	char components[102][10],node[10][102][10];
	int sz=0;
	FILE *fp;
	int rule = 0;
	int i,j,a,b;

	// Algoritma fungsional Design Rule Check
	memset(node, 0, sizeof node);
	scanf("%s", filename);
	fp = fopen(filename, "r");
	// parse external file to array of components and 2 nodes
	while (fgets(data, 50, fp) != NULL) {
		i = 0, j = 0;
		while (i < 50 && data[i] != ' ') {
			components[sz][j] = data[i];
			++i; ++j;
		}
		components[sz][j] = 0;
		j = 0; ++i;
		int cur_node = 0;
		while (i < 50 && data[i] != 13 && data[i] != 0) {
			if (data[i] == ' ') {
				node[cur_node][sz][j] = 0;
				++cur_node;
				j = 0;
				++i;
			} else {
				node[cur_node][sz][j] = data[i];
				++i; ++j;
			}
		}
		node[cur_node][sz][j] = 0;
		++sz;
	}

	// check components with each other
	for (i = 0; i < sz; ++i) {
		int cnt = 0;
		for (j = 0; j < sz; ++j) {
			if (i == j) {
				continue;
			}
			int match = 0;
			for (a = 1; a <= M; ++a) {
				for (b = 1; b <= N; ++b) {
					if (strcmp(layout[a][b], components[i]) == 0) {
						int now = b+1;
						char c = routing[a][b].sym;
						int found = 0;
						while (found == 0 && now <= N && routing[a][now].sym == c) {
							if (strcmp(layout[a][now], components[j]) == 0) {
								found = 1;
								break;
							}
							++now;
						}
						now = b-1;
						while (found == 0 && now >= 1 && routing[a][now].sym == c) {
							if (strcmp(layout[a][now], components[j]) == 0) {
								found = 1;
								break;
							}
							--now;
						}
						now = a+1;
						while (found == 0 && now <= M && routing[now][b].sym == c) {
							if (strcmp(layout[now][b], components[j]) == 0) {
								found = 1;
								break;
							}
							++now;
						}
						now = a-1;
						while (found == 0 && now >= 1 && routing[now][b].sym == c) {
							if (strcmp(layout[now][b], components[j]) == 0) {
								found = 1;
								break;
							}
							--now;
						}
						if (found) {
							match = 1;
							break;
						}
					}
				}
				if (match) {
					break;
				}
			}

			int same = 0, k, l;
			for (k = 0; k < 10; ++k) {
				for (l = 0; l < 10; ++l) {
					if (strcmp(node[k][i], node[l][j]) == 0) {
						same = 1;
						break;
					}
				}
			}

			if ((match && same) || (!match && !same)) {
				++cnt;
			}
		}

		if (cnt == sz - 1) {
			++rule;
		}
	}

	// print result
	printf("%d/%d rule is checked\n", rule, sz);
}

void saveLayout(char layout[42][42][3], int M, int N, char NamaFile[50])
{
    FILE *f1;
    f1 =fopen(NamaFile,"w");
    //Membuka file yang ingin ditulis dengan fungsi
    int i,j,k;
    char arrayC[42][42][3];

	for (i = 0;i<=N;i++){
		for (j=0;j<=M;j++){
			for(k=0;k<3;k++){
				arrayC[i][j][k] = layout[i][j][k];
			}
		}
	}
    /*strcpy(arrayC[1][1],"C1");
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
    strcpy(arrayC[5][7]," ");*/

    if (f1 != NULL)
    {
        fprintf(f1,"%d,%d\n",M,N);
        for (i=1;i<=N;i++){
            for (j=1;j<=M;j++){
                fprintf(f1,"%s,",arrayC[j][i]);
            }
            fprintf(f1,"\n");
        }

	printf("Layout saved successfully\n");
    } else {
        printf("Failed to write file\n");
    }
    //Closing file
    fclose(f1);
    //Print array di sini dengna iterasi MN int

    return;
}

void saveRouting(routing_t arr[42][42],char NamaFile[50], int* m, int* n)
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
				 arrayC[i][j]=arr[i][j].sym;
                //copyChar(arr[i][j],&arrayC[i][j]);
            }
        }

    if (f1 != NULL)
    {
        fprintf(f1,"%d,%d\n",M,N);
        for (i=1;i<=N;i++){
            for (j=1;j<=M;j++){
                fprintf(f1,"%c,",arrayC[j][i]);
            }
            fprintf(f1,"\n");
        }

	printf("Routing saved successfully\n");
    } else {
        printf("Failed to write file.\n");
    }
    //Closing file
    fclose(f1);
    //Print array di sini dengna iterasi MN int
}

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
// 2. <Nama Praktikan> 	- <NIM>	   : Fix the bug where num-	//
//	  ber 2 is printed twice								//
//															//
//**********************************************************//

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

// Konvensi status
// 1 = menu, main akan menjalankan menu jika status berada 
// pada kondisi menu
// 2 = mode, main akan menjalankan mode jika status berada 
// pada kondisi mode
// 3 = end,  main akan mengakhiri program

void menu(int *status, FILE **file1, FILE **file2, int *M, int *N){
	// Deklarasi
	int ope;

	do {
		fscan("%d", &ope);

		if (ope > 3 && ope < 1){
			fprint("Input tidak valid.");
		}
	} while (ope != 3);

	if(ope == 1){
		// Algoritma membuat file baru
		char NamaFile1 [50];
		char NamaFile2 [50];
		printf("====== Membuat Proyek Baru ======\n");
		printf("Masukkan nama proyek: ");
		gets (NamaFile1);
		printf("Masukkan ukuran PCB NxM (N,M<40): ");
		scanf("%d %d",&M,&N);
		strcpy(NamaFile2,NamaFile1);
		strcat(NamaFile1,"_layout.csv");
		strcat(NamaFile2,"_routing.csv");
		file1=fopen(NamaFile1,"w+");
		file2=fopen(NamaFile2,"w+");
		isEmpty(
		isEmpty(
		
		*status = 2;
	}
	else {
		if(ope == 2){
			// Algoritma membuka file lama

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

//**********************************************************//
//						[Source Code]						//
//															//
// Institution		: Institut Teknologi Bandung			//
// Name				: <Nama Praktikan>						//
// File Name		: main.c								//
// Dependency		: stdio.h, main.h, menu.h, mode.h		//
//															//
// Description:												//
//	This main program functions as the high level stage of	//
//	the program, which let the program decide wheter the 	//
//	program is executing menu, mode, or exiting accordingly //
//	to the status variable, which will be specificcaly ex-	//
//	plained later in the program.							//
//															//
// Status:													//
// 1. Gede Satya A D 	- 13217016 : Membuat file			//
// 2. <Nama Praktikan> 	- <NIM>	   : Fix the bug where num-	//
//	  ber 2 is printed twice								//
//															//
//**********************************************************//

#include <stdio.h>
#include "main.h"
#include "menu.h"
#include "mode.h"

// Konvensi status
// 1 = menu, main akan menjalankan menu jika status berada 
// pada kondisi menu
// 2 = mode, main akan menjalankan mode jika status berada 
// pada kondisi mode
// 3 = end, main akan mengakhiri program

int main() {
	// Deklarasi
	int status;
	FILE *file1;
	FILE *file2;
	routing_t routing[42][42];
	char layout[42][42][3];
	int *M;
	int *N;

	// Algoritma
	status = 1;

	do {
		if (status == 1){
			menu(&status, &file1, &file2, M, N, routing, layout);
		}
		if (status == 2){
			mode(&status, &file1, routing, layout, M, N);
		}
	} while (status != 3);

	return (0);
}

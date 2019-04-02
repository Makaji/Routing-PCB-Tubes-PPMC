#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

// Konvensi status
// 1 = menu, main akan menjalankan menu jika status berada pada kondisi menu
// 2 = mode, main akan menjalankan mode jika status berada pada kondisi mode
// 3 = end,  main akan mengakhiri program

void menu(int *status, FILE **file, int *M, int *N){
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

		*status = 2;
	}
	else {
		if(ope == 2){
			// Algoritma membuka file lama

			*status = 2;
		}
		else {
			// Membuat status menjadi keluar, karena status yang akan dikenali pada main
			// akan mengarahkan untuk keluar dari program.
			*status = 3;
		}
	}
}
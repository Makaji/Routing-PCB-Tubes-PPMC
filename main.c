#include <stdio.h>
#include "main.h"
#include "menu.h"
#include "mode.h"

// Konvensi status
// 1 = menu, main akan menjalankan menu jika status berada pada kondisi menu
// 2 = mode, main akan menjalankan mode jika status berada pada kondisi mode
// 3 = end,  main akan mengakhiri program

int main() {
	// Deklarasi
	int status;
	FILE *file;
	int *M;
	int *N;

	// Algoritma
	status = 1;

	do {
		if (status == 1){
			menu(&status, &file, &M, &N);
		}
		if (status == 2){
			mode(&status, &file, M, N);
		}
	} while (status != 3);

	return (0);
}


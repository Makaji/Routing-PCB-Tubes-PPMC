//**********************************************************//
//						[Source Code]						//
//															//
// Institution		: Institut Teknologi Bandung			//
// Name				: <Nama Praktikan>						//
// File Name		: util.c								//
// Dependency		: stdio.h, string.h, stdlib.h, main.h	//
//															//
// Description:												//
//	This program declares the utility functions that may be	//
//	called by multiple functions in multiple files.			//
//															//
// Status:													//
// 1. Gede Satya A D 	- 13217016 : Membuat file			//
// 2. <Nama Praktikan> 	- <NIM>	   : Fix the bug where num-	//
//	  ber 2 is printed twice								//
//															//
//**********************************************************//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

// Implementasi fungsional
void konversiKoor(char str[5], int *a, int *b){
// Program ini mengkonversi input koordinat dari bentuk string menjadi dua integer terpisah
// jika salah satu nilai integer bernilai 0, maka input invalid.
	// Deklarasi variabel lokal
	char *token[5];

	// Algoritma fungsi
	*token = strtok(str,",");
	*a = atoi(*token);

	*token = strtok(str,",");
	*b = atoi(*token);
}

void backdoorCheckNode(){

// Program ini menentukan apakah antara dua titik terhubung atau tidak.
// Jika terhubung, maka akan ditandai dengan nilai node yang sama.
	// Deklarasi variabel lokal

	// Algoritma fungsi

}

void
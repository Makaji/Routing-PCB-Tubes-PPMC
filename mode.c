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
// 1. Gede Satya A D 	- 13217016 : Membuat file			//
// 2. <Nama Praktikan> 	- <NIM>	   : Fix the bug where num-	//
//	  ber 2 is printed twice								//
//															//
//**********************************************************//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mode.h"
#include "main.h"
#include "cetak.h"
#include "layout.h"
#include "routing.h"

// Deklarasi fungsional untuk eksekusi mode, Design Rule
// Checker, dan penyimpanan File
void mode(int *status, FILE **file, int M, int N){

}

void drc (routing_t routing[42][42], char layout[42][42][2], int M, int N){
	// Deklarasi variabel lokal

	// Algoritma fungsional Design Rule Check
}

void saveFile (FILE **file, routing_t routing[42][42], char layout[42][42][2], int M, int N, int *status){
	// Deklarasi variabel lokal

	// Algoritma fungsional Penyimpan File

}

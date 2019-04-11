#ifndef LAYOUT_H
#define LAYOUT_H

// Deklarasi fungsional layouting manual dan otomatis
void inputKomponen(char layoutFunc[42][42][3], int M, int N, int kakiMax, int jarakMin, char komponen[3]);
void layoutManual(char layoutFunc[42][42][3], int M, int N);

// Untuk auto, dapat dinonaktifkan dengan membuat deklarasi line, implementasi, dan pemanggilan
// menjadi komentar program untuk sementara.

//void layoutAuto (char *layout[42][42][2], int M, int N);

#endif

#ifndef MODE_H
#define MODE_H

// Deklarasi fungsi mode.c
void drc (routing_t routing[42][42], char layout[42][42][3], int M, int N);
void saveFile (FILE **file, routing_t routing[42][42], char layout[42][42][3], int M, int N);
void saveLayout(char layout[42][42][3], int M, int N, char NamaFile[50]);
void saveRouting(routing_t arr[42][42],char NamaFile[50], int* m, int* n);
void mode(int *status, char fileName1[50], char fileName2[50], routing_t route[42][42], char layout[42][42][3], int M, int N);

#endif

#ifndef MENU_H
#define MENU_H



// Deklarasi fungsi pada menu.c
void loadLayout(char arrayC2[42][42][3], int *m, int *n, char NamaFile[50]);
void loadRouting(routing_t arr[42][42],int* m, int* n,char NamaFile[50]);
void menu(int *status, char fileName1[50], char fileName2[50], int *M, int *N, routing_t routing[42][42], char layout[42][42][3]);

#endif

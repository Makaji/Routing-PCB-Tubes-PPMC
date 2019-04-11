#ifndef MODE_H
#define MODE_H

// Deklarasi fungsi mode.c
void drc (routing_t routing[42][42], char layout[42][42][3], int M, int N);
void saveFile (FILE **file, routing_t routing[42][42], char layout[42][42][3], int M, int N);
void mode(int *status, FILE **file, routing_t route[42][42], char layout[42][42][3], int M, int N);

#endif

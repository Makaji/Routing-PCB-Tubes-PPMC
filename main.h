#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Deklarasi tipe bentukan
typedef struct koordinat{
	int x;
	int y;
}koordinat_t;

typedef struct routing{
	char sym;
	int node;
}routing_t;

// Deklarasi fungsi utilitas pada header ini
void konversiKoor(char str[5], int *a, int *b);
void emptyRoute(routing_t route[42][42]);
void emptyLayout(char layout[42][42][3]);
void cetakRoutingNode(routing_t R[42][42], int m, int n);

#endif

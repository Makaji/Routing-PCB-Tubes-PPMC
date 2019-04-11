#ifndef MAIN_H
#define MAIN_H

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

#endif

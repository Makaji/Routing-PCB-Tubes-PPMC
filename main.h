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
void backdoorCheckNode();

#endif

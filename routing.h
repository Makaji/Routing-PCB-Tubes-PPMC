#ifndef ROUTING_H
#define ROUTING_H

// Deklarasi fungsional routing manual dan otomatis
void routingManual (routing_t *routing[42][42], int M, int N);

// Untuk auto, dapat dinonaktifkan dengan membuat deklarasi line, implementasi, dan pemanggilan
// menjadi komentar program untuk sementara.

void routingAuto (routing_t *routing[42][42], int M, int N);

#endif

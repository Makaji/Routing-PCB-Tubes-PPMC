#include "routing.h"
#include "main.h"
#include <string.h>

int checkRoute(routing_t routing[42][42], char sym, koordinat_t koor1, koordinat_t koor2, int M, int N, int node){
    int i,j;
    int temp;
    int jMin, jMax;
    int iMin, iMax;
    temp = 1;

    if (koor1.x == koor2.x){
        if (koor1.y>koor2.y){
            iMin = koor2.y-1;
            iMax = koor1.y+1;
            jMin = koor2.x-1;
            jMax = koor1.x+1;
        }
        else{
            iMin = koor1.y-1;
            iMax = koor2.y+1;
            jMin = koor1.x-1;
            jMax = koor2.x+1;
        }
        for (i=iMin; i<=iMax; i++){
            for (j=jMin; j<=jMax; j++){
                if (routing[j][i].sym == sym && routing[j][i].node != node){
                    // Pengecekan untuk yang bukan di ujung, karena tidak terhubung jika diagonal
                    if ((i != iMin && i != iMax) || (j != jMin && j != jMax)){
                        temp = 0;
                    }
                } // else tidak melakukan apa-apa
            }
        }
        for (i=iMin+1; i<=iMax-1; i++){
                if (routing[koor1.x][i].node != node && routing[koor1.x][i].node != 0){
                    temp = 0;
                } // else tidak melakukan apa-apa
            }
    }
    else{
        if (koor1.y == koor2.y){
            if (koor1.x>koor2.x){
                iMin = koor2.x-1;
                iMax = koor1.x+1;
                jMin = koor2.y-1;
                jMax = koor1.y+1;
            }
            else{
                iMin = koor1.x-1;
                iMax = koor2.x+1;
                jMin = koor1.y-1;
                jMax = koor2.y+1;
            }
            for (i=iMin; i<=iMax; i++){
                for (j=jMin; j<=jMax; j++){
                    if (routing[i][j].sym == sym && routing[i][j].node != node){
                        // Pengecekan hanya di ujung
                        if ((i != iMin && i != iMax) || (j != jMin && j != jMax)){
                            temp = 0;
                        }
                    } // else tidak melakukan apa-apa
                }
            }
            // Pengecekan jalur bertabrakan atau tidak
            for (i=iMin+1; i<=iMax-1; i++){
                if (routing[i][koor1.y].node != node && routing[i][koor1.y].node != 0){
                    temp = 0;
                } // else tidak melakukan apa-apa
            }
        }
        else{
            temp = 0;
        }
    }
    return temp;
}

void assignRoute (routing_t routing[42][42], char sym, koordinat_t koor1, koordinat_t koor2, int M, int N, int node){
    routing_t routingFunc[42][42];
    int iMin;
    int iMax;
    int i;
    int j;
    for(i = 1; i<=M; i++){
        for(j = 1; j<=N; j++){
            routingFunc[i][j] = (routing[i][j]);
        }
    }

    if (koor1.x== koor2.x){
        if (koor1.y>koor2.y){
            iMin = koor2.y;
            iMax = koor1.y;
            j = koor1.x;
        }
        else{
            iMin = koor1.y;
            iMax = koor2.y;
            j = koor1.x;
        }
        for (i = iMin; i<=iMax; i++){
            routingFunc[j][i].sym = sym;
            routingFunc[j][i].node = node;
        }
    }
    else
    {
        if (koor1.x>koor2.x){
            iMin = koor2.x;
            iMax = koor1.x;
            j = koor1.y;
        }
        else{
            iMin = koor1.x;
            iMax = koor2.x;
            j = koor1.y;
        }
        for (i = iMin; i<=iMax; i++){
            routingFunc[i][j].sym = sym;
            routingFunc[i][j].node = node;
        }
    }
    for(i = 1; i<=M; i++){
        for(j = 1; j<=N; j++){
            (routing[i][j]) = routingFunc[i][j];
        }
    }
    return;
}

void routeManual (routing_t routingFunc[42][42], int M, int N){
    routing_t routingFunc[42][42];
    int iMin;
    int iMax;
    int i;
    int j;
    for(i = 1; i<=M; i++){
        for(j = 1; j<=N; j++){
            routingFunc[i][j] = (routing[i][j]);
        }
    }

    if (koor1.x== koor2.x){
        if (koor1.y>koor2.y){
            iMin = koor2.y;
            iMax = koor1.y;
            j = koor1.x;
        }
        else{
            iMin = koor1.y;
            iMax = koor2.y;
            j = koor1.x;
        }
        for (i = iMin; i<=iMax; i++){
            routingFunc[j][i].sym = sym;
            routingFunc[j][i].node = node;
        }
    }
    else
    {
        if (koor1.x>koor2.x){
            iMin = koor2.x;
            iMax = koor1.x;
            j = koor1.y;
        }
        else{
            iMin = koor1.x;
            iMax = koor2.x;
            j = koor1.y;
        }
        for (i = iMin; i<=iMax; i++){
            routingFunc[i][j].sym = sym;
            routingFunc[i][j].node = node;
        }
    }
    for(i = 1; i<=M; i++){
        for(j = 1; j<=N; j++){
            (routing[i][j]) = routingFunc[i][j];
        }
    }
    return;
}

int main (routing_t routingFunc[42][42], int M, int N){
    M = 15;
    N = 15;
    routing_t routing[42][42];
    char sym;
    int countNode;
    koordinat_t koor[20];
    int check;
    int i,j,k;
    char strKoor[5];
    int statusRoute;
    // Konvensi statusRoute
    // 1 = Menerima simbol
    // 2 = Menerima koordinat
    // Selain itu menandakan bahwa fungsi akan direturn

    for (i=0;i<42;i++){
        for(j=0;j<42;j++){
            routing[i][j].sym=32;
        }
    }

    countNode = 1;

    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    printf("Isi 'n' atau 'N' untuk memulai pada simpul (node) baru\n");

    statusRoute = 1;

    do{
        printf("(Pilih Simbol (!,@,#,$,%%,^,&,*(,)): ");
        scanf("%c", &sym);
        switch (sym){
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':
            case '^':
            case '&':
            case '*':
            case '(':
            case ')':
                i = 1;
                statusRoute = 2;
            default:
                if (statusRoute==1){
                    printf("Input harus sesuai simbol yang diberikan (Shift + 1-0)\n");
                }
        }

        while (statusRoute == 2){
            printf("Koordinat %d: ", i);
            scanf("%s", &strKoor);

            switch(strKoor[0]){
                case 'q':
                case 'Q':
                    statusRoute = 3;
                    break;
                case 'n':
                case 'N':
                    statusRoute = 1;
                    countNode++;
                    break;
                default:
                    konversiKoor(strKoor, &(koor[i-1].x), &(koor[i-1].y));
                    if ((koor[i-1].x>=1 && koor[i-1].x <= M) && (koor[i-1].y>=1 && koor[i-1].y <= N)){
                        if (i>1){
                            check = checkRoute(routing, sym, koor[i-2], koor[i-1], M, N, countNode);
                            if (check == 1){
                                assignRoute(routing, sym, koor[i-2], koor[i-1], M, N, countNode);
                                cetakRouting(routing, M, N);
                                cetakRoutingNode(routing, M, N);
                                i++;
                            }
                            else{
                                printf("Invalid, aturan:\n 1. Jalur tidak bisa bersimbol sama dengan node lain\n    yang bersebelahan\n 2. Koordinat tidak bisa miring\n");
                            }
                        }
                        else {
                            check = checkRoute(routing, sym, koor[i-1], koor[i-1], M, N, countNode);
                            if (check == 1){
                                routing[koor[i-1].x][koor[i-1].y].sym = sym;
                                routing[koor[i-1].x][koor[i-1].y].node = countNode;
                                cetakRouting(routing, M, N);
                                cetakRoutingNode(routing, M, N);
                                i++;
                            }
                            else{
                                printf("Invalid, aturan:\n 1. Jalur tidak bisa bersimbol sama dengan node lain\n    yang bersebelahan\n 2. Koordinat tidak bisa miring\n");
                            }
                        }
                    }
                    else{
                        printf("Koordinat tidak boleh melewati batas\n");
                    }
            }
        }
    } while (statusRoute == 1);

    for (i=0;i<42;i++){
        for(j=0;j<42;j++){
            routingFunc[i][j]=routing[i][j];
        }
    }

    return;
}

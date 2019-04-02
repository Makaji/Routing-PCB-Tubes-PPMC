#include <stdio.h>

int i, j, m, n;
char R[40][40];

void tampilRouting(){
    R[2][2]='@';
    for (i=0;i<m;i++){
        printf("\t%d",(i+1));
    }
    printf("\n");
    for (i=1;i<=n;i++){
        printf("%d",i);
        for (j=1;j<=m;j++){
            printf("\t%c",R[i][j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d",&m);//kolom
    scanf("%d",&n);//baris
    tampilRouting();
    return 0;
}

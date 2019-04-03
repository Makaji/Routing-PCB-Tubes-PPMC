#include <stdio.h>

int i, j, m, n;
char R[42][42];

void cetakRouting(){
    //R[10][1]='@'; cuma buat ngetes doang
    //R[10][10]='*'; 
    printf("  ");
    for (i=0;i<m;i++){
        printf("%10d",(i+1));
    }
    printf("\n");
    for (i=1;i<=n;i++){
        printf("%d",i);
        for (j=1;j<=m;j++){
            printf("%10c",R[i][j]);
        }
        printf("\n");
    }
}

/*int main(){
    scanf("%d",&m);//kolom
    scanf("%d",&n);//baris
    cetakRouting();
    return 0;
}*/

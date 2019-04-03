#include <stdio.h>
#include <string.h>

int i, j, m, n;
char L[42][42][2];

void cetakLayout(){
    printf("  ");
    for (i=1;i<=m;i++){
        printf("%10d",(i));
    }
    printf("\n");
    for (i=1;i<=n;i++){
        if (i<10){
            for (j=0;j<1;j++){
                printf("%d",i);
            }
            for (j=1;j<=m;j++){
                printf(" %10s",L[i][j]);
            }
            printf("\n");
        } else{
            for (j=0;j<1;j++){
                printf("%d",i);
            }
            for (j=1;j<=m;j++){
                printf("%10s",L[i][j]);
            }
            printf("\n");
        }
    }
}

/*int main(){
    scanf("%d",&m);//kolom
    scanf("%d",&n);//baris
    //strcpy(L[3][1],"R2");
    //strcpy(L[10][1],"R1");
    //strcpy(L[15][1],"R3");
    cetakLayout();
    return (0);
}*/


#include <stdio.h>

int main (){

    int a,i,j,k,b;
    do{
    printf("Masukan Jumlah Bintang Yang Ingin Dikeluarkan : ");
    scanf ("%d", &a);

    if (a <=8){


    for (i=a;i>=1;i--){
        for (j=0;j<a;j++){
            for(k=0;k<a;k++){
                if(k<i-1){
                    printf("  ");
                }else printf(" *");
            }
            printf ("  ");
            }
        printf ("\n");
        }
    }
    }while (a != 0);
    //getch();
    return 0;
}
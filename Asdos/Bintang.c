#include <stdio.h>
#include <windows.h>

void main(){
    system("cls");
    int i,j,k,l;
    int n;

    printf("Masukan Angka: ");
    scanf("%d",&n);

    for (i = 0; i <= n; i++){
        for (k = n; k > i; k--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }
    
    



}
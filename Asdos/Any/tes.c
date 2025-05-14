#include <stdio.h>
#include <windows.h>


void Bintang(int n){
    int i,j; // loop var 
    int px = n/2+1; // print controls (mid) 
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if (j == px || j == n-px+1 ){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        
        if(i <= n/2)
            px--;
        else
            px++;
            printf("\n");
    }
}

int main(){
    int n; // size 
    int p;

    for (int a=0;a<=p;a++){
        system("cls");
        printf("Masukan Bilangan Ganjil:");
        scanf("%d",&n);
        
        if (n%2==0){
            printf("Bilangan Tidak Ganjil! Ulangi\n");
            system("pause");
        }
        if (n%2==1){
            Bintang(n);
            break;
        }
        p++;
    }

    return 0;
} 
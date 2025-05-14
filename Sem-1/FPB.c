#include <stdio.h>
#include <windows.h>

int main(){
    int n1, n2, i, hasil, p;

    for (int j = 0; j <= p; j++){
        printf("Masukan Angka 1 : ");
        scanf("%d", &n1);
        printf("Masukan Angka 2 : ");
        scanf("%d", &n2);
        if (n1==0 || n2==0){
            printf("Masukan Angka Yang Benar!\n");
        }
        else{
            for (i = 1; i<=n1; i++){
                if(n1 % i == 0 && n2 % i == 0){
                    hasil = i;
                }
            }
            printf("FPB dari %d dan %d adalah %d\n", n1, n2, hasil);
            break;
        }
        p++;
    }
}
#include <stdio.h>

int main(){
    int n1, n2, i, hasil;

    printf("Masukan Angka 1 : ");
    scanf("%d", &n1);
    printf("Masukan Angka 2 : ");
    scanf("%d", &n2);
    for (i = 1; i<=n1; i++){
        if(n1 % i == 0 && n2 % i == 0){
            hasil = i;
        }
    }
    printf("FPB dari %d dan %d adalah %d", n1, n2, hasil);
}
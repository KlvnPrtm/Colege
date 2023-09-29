#include <stdio.h>

#include <stdio.h>

void prosedurPenjumlahan(){
    int bilangan1;
    int bilangan2;
    int jumlah, kurang, kali, bagi, modulus;
    printf("Masukkan bilangan 1: ");
    scanf("%i", &bilangan1);
    printf("Masukkan bilangan 2: ");
    scanf("%i", &bilangan2);
    jumlah = bilangan1+bilangan2;
    printf("Hasil %i + %i = %i \n\n", bilangan1, bilangan2,jumlah);

}
void main(){
    prosedurPenjumlahan();
}

/*
int main(){
    int a=2,x;
    int n;
    printf("Masukan Angka:");
    scanf("%d",&n);
    x=n+a;
    printf("Total Angka: %d",x);

}
*/
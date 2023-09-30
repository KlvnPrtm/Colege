#include <stdio.h>

void f(int x){
    int Hasil = x/2;
    printf("%d / 2 = %d\n",x,Hasil);
}

int main(){
    int x=10;
    f(x);

    return 0;
}
    // printf("Masukan Angka Pertama: ");
    // scanf("%d",&a);
    // printf("Masukan Angka Kedua: ");
    // scanf("%d",&b);
// void Parameter(char Nama[20]){
//     printf("Hai %s\n",Nama);
// // }
//     char Nama[20];
//     scanf(" %[^\n]",&Nama);
//     Parameter(Nama);
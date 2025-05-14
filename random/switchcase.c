#include <stdio.h>

int main(){
    char Pilihan;

    printf("Masukan Angka: ");
    scanf("%s",&Pilihan);
    switch (Pilihan){
        case '1':
            printf("Angka 1");
        break;
        
        case '2':
            printf("Angka 2");
        break;
        
        default:
            printf("Tidak Ada Pilihan");
        break;
    }
}
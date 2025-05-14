#include <stdio.h>
#include <string.h>
#include <windows.h>

void Tugas1(){
    int harga,diskon,hasil;
    printf("Harga setelah diskon: ");
    scanf(" %d",&diskon);
    printf("Besar Diskon: ");
    scanf(" %d",&harga);
    hasil=diskon+harga;
    printf("Harga sebelum diskon: %d", hasil);
}

void Quiz1(){
    char kata[100];
    int i, j;
    printf("Masukan kata: ");
    scanf("%s", kata);
    int panjang = strlen(kata);
        for (i = 0; i < panjang; i++) {
            for (j = 0; j <= i; j++) { 
        printf("%c", kata[j]);
    }
    printf("\n");
    }
    for (i = panjang - 2; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            printf("%c", kata[j]);
    }
    printf("\n");
    }
}

void Quiz3(){
    int angka,i;
    printf("Masukkan angka: ");
    scanf("%d", &angka);
    for (i = 1; i <= angka; i++) {
        printf("%d, ", i * angka);
    }
    printf("... \n");
}

int input;
void Menu(){
    system("cls");
    printf("\n1. Tugas 1\n");
    printf("2. Quiz 1\n");
    printf("3. Quiz 3\n");
    printf("Pilih Menu: ");
    scanf(" %d",&input);
}

int main(){
    for (;;){
        Menu();
        if (input == 1){
            printf("\n");
            Tugas1();
            printf("\n");
            system("pause");
            Menu();
        }else if (input == 2){
            printf("\n");
            Quiz1();
            printf("\n");
            system("pause");
            Menu();
        }else if (input == 3){
            printf("\n");
            Quiz3();
            printf("\n");
            system("pause");
            Menu();
        }else{
            printf("Pilihan Tidak Sesuai! Ulangi\n");
            system("pause");
            Menu;
        }
    }
    return 0;
}
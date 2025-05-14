#include <stdio.h>
#include <string.h>

int main(){

    char Nama[30];

    int Angka[10];
    // printf("%d", Angka[4]);
    // printf("%c", Nama[2]);


    // printf("Masukan Nama: ");
    // scanf("%s",&Nama);
    // printf("Nama Anda Adalah: %s",Nama);
    
    for (int i = 1; i <= 3; i++){
        printf("Masukan Angka %d: ", i);
        scanf("%d",&Angka[i]);
    }
    printf("\n");
    for (int i = 1; i <= 3; i++){
        printf("Angka %d Anda Adalah : %d\n", i, Angka[i]);
    }
    
    

    // char String[7]={'a', 'b', 'c', 'd', 'e', 'f'};
    // for (int i = 0; i < 6; i++){
    // printf("String: %c\n", String[i]);
    // }
    
}
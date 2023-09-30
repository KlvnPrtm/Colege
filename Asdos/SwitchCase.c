#include <stdio.h>

int main(){

    int inti;
    int a,b,c,d,e;

    printf("Pilih Angka 1-5: ");
    scanf("%d",&inti);
    switch (inti){
        case 1:
            printf("Ini Pilihan Ke-1");
            break;
        case 2:
            printf("Ini Pilihan Ke-2");
            break;
        case 3:
            printf("Ini Pilihan Ke-3");
            break;
        case 4:
            printf("Ini Pilihan Ke-4");
            break;
        case 5:
            printf("Ini Pilihan Ke-5");
            break;
        default:
            printf("Ngaco");
            break;
    }
}
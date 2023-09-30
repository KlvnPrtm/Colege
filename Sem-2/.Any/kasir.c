#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int no[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char nama[10][20]={"Mouse", "Keyboard", "Monitor", "Printer", "CPU", "VGA", "RAM", "SSD", "HDD", "PSU"};
int harga[10]={200000, 500000, 1000000, 700000, 3000000, 10000000, 1700000, 2000000, 1000000, 1000000};

void menu(){
    printf("SELAMAT DATANG DI TOKO KOMPUTER CINA KO KEPIN\n\n");
    printf("==============================================\n");
    printf("|  NO |\t Jenis Barang\t|\tHarga\t     |\n");
    printf("==============================================\n");
    for(int i= 0; i < 10; i++){
        if (i>0&&i<4){
            printf("|  %d  |\t  %s\t|\t%d\t     |\n", no[i], nama[i], harga[i]);  
        }
        else if(i==5){
            printf("|  %d  |\t  %s\t\t|\t%d     |\n", no[i], nama[i], harga[i]);  
        }
        else if(i==9){
            printf("|  %d |\t  %s\t\t|\t%d\t     |\n", no[i], nama[i], harga[i]);
        }
        else{
            printf("|  %d  |\t  %s\t\t|\t%d\t     |\n", no[i], nama[i], harga[i]);
        }
    }
    printf("==============================================\n");
}
int main(){
    menu();
    int a;
    int l=1;
    do{
        printf("Anda ingin membeli berapa jenis barang: ");
        scanf("%d", &a);
        if(a>10){
            printf("Maaf, input melebihi batas! Silahkan ulangi!\n\n");
        }
        else if(a<1){
            printf("Maaf, input salah! Silahkan ulangi!\n\n");
        }
    }while(a>10||a<1);

    int c;

    for(int i=0; i<l; i++){
        for(int j=0; j<a; j++){
            printf("\nSilahkan masukkan nomor barang yang ingin anda beli: ");
            scanf("%d", &c);

        }
        
    }
}
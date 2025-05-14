#include <stdio.h>

int main(){
    char Nama[50][50]={"Rafiq Widya Pratama"};
    char Nim[50][50]={"231011700153"};
    char Kelas[50][50]={"01SIFP003"};
    int Bilangan;
    printf("Nama : %s\n",Nama);
    printf("Nim  : %s\n",Nim);
    printf("Kelas: %s\n",Kelas);
    printf("======================\n");
    
    printf("Masukan Bilangan : ");
    scanf("%d",&Bilangan);
    Bilangan = Bilangan % 2;
    printf("Sisa Bagi : %d\n",Bilangan);
    if (Bilangan == 0){
        printf("adalah bilangan genap\n");
    }
    else if (Bilangan == 1){
        printf("adalah bilangan ganjil\n");
    }

    printf("----------------------\n");
    
    printf("Masukan Bilangan : ");
    scanf("%d",&Bilangan);
    Bilangan = Bilangan % 2;
    printf("Sisa Bagi : %d\n",Bilangan);
    if (Bilangan == 0){
        printf("adalah bilangan genap\n");
    }
    else if (Bilangan == 1){
        printf("adalah bilangan ganjil\n");
    }
    
    printf("----------------------\n");
    
    return 0;
}
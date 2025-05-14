#include <stdio.h>
#include <string.h>
#include <windows.h>

void ganjil_genap(){
    int angka;
    printf("Masukkan angka: ");
    scanf("%d", &angka);
    if (angka == 0){
        printf("Invalid");
    }
    else if (angka % 2 == 0){
        printf("Angka %d adalah angka genap", angka);
    }
    else{
        printf("Angka %d adalah angka ganjil", angka);
    }
    printf("\n");
    system("pause");
    menu();
}

void Buzz(){
    int maxAngka;
    printf("Masukkan batasan angka: ");
    scanf("%d", &maxAngka);
    for (int i = 1; i <= maxAngka; i++)
    {
        if ((i%3 == 0)&&(i%5 == 0))
        {
            printf("Buzz Lightyear\n");
        }
        else if (i%3 == 0)
        {
            printf("Buzz\n");
        }
        else if (i%5 == 0)
        {
            printf("Lightyear\n");
        }
        else{
            printf("%i\n", i);
        }
    }
    printf("\n");
    system("pause");
    menu();
}

void Ketupat(){
    int tinggi;

    printf("Masukkan Tinggi Segitiga: ");
    scanf("%d", &tinggi);

    for (int i = 0; i < tinggi; i++){
        for (int j = 0; j < tinggi-i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < ((i+1)*2)-1; k++)
        {
            if (k == 0 || k == (((i+1)*2)-1)-1)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }
    for (int i = 0; i < (tinggi*2)+1; i++){
        printf("*");
    }
    printf("\n");
    system("pause");
    menu();
}

char nama[50], nim[12];

void menu(){
    int pilihan;
    system("cls");
    do{
        printf("** Selamat datang, %s-%s **\n\n", nama, nim);
        printf("1. Ganjil/Genap\n");
        printf("2. Buzz Lightyear\n");
        printf("3. Diamond kematian\n");          
        printf("4. Keluar\n\n");
        printf("Masukkan inputan anda: ");
        scanf("%d", &pilihan);
        if (pilihan == 1){
            system("cls");
            ganjil_genap();
        }
        else if (pilihan == 2){
            system("cls");
            Buzz();
        }
        else if (pilihan == 3){
            system("cls");
            Ketupat();
        }
        else if (pilihan == 4){
            exit(0);
            system("cls");
        }
        else{
            system("cls");
            printf("inputan invalid\n");
            system("pause");
        }
    }while (pilihan != 4); 
}

int main(){
    system("cls");
    printf("Masukkan nama: ");
    scanf(" %[^\n]", &nama);
    printf("Masukkan nim: ");
    scanf(" %[^\n]", &nim);
    system("pause");
    menu();
    
    return 0;
}
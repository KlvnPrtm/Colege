#include <stdio.h>
#include <windows.h>

void BMI(){
    float tinggi, berat;
    float bmi;
    system("cls");
    printf("Masukkan tinggi badan (cm): ");
    scanf("%f", &tinggi);
    printf("Masukkan berat tubuh (kg): ");
    scanf("%f", &berat);
    bmi = berat/((tinggi/100)*(tinggi/100));
    printf("\nIndeks Massa Tubuh anda adalah %.1f\n", bmi);
    if (bmi < 18.5)
    {
        printf("Berat badan anda di bawah normal\n\n");
    }
    else if (bmi < 25)
    {
        printf("Berat badan anda normal\n\n");
    }
    else if (bmi < 30)
    {
        printf("Berat badan anda berlebihan\n\n");
    }
    else if (bmi < 35)
    {
        printf("Anda obesitas\n\n");
    }
    else{
        printf("Anda obesitas ekstrim\n\n");
    }
    system("pause");  
    main();  
}

void Segi3(){
    int tinggi;
    printf("Masukan Angka: ");
    scanf("%d", &tinggi);
    for (int i = 0; i < tinggi; i++){
        for (int j = 0; j < tinggi-i; j++){
            printf(" ");
        }
        for (int k = 0; k < i+1; k++){
            printf("* ");
        }
        printf("\n");
    }
    system("pause");
    main();
}

int main(){
    int menu;
    system("cls");
    printf("1. Indeks Masa Tubuh\n");
    printf("2. Segitiga\n");
    printf("3. Keluar\n");
    printf("Pilihan anda: ");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        BMI();
        break;
    case 2:
        Segi3();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Pilihan tidak dikenali\n");
        system("pause");
        main();
    }
    system("pause");
}
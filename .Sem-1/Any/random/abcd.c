#include <stdio.h>

int main(){

    float a,b,hasil;
    char aritmatika;
    //float Hasil;
    printf("Selamat Datang Di Program Calculator Sederhana \n \n");

    /*printf("Masukan Nilai = ");
    scanf ("%d",&a);
    printf("Pilih Operator +,-,/,* = ");
    scanf ("%c", aritmatika);
    printf("Masukan Nilai = ");
    scanf ("%d",&b);

    printf("\nHasil Perhitungan: ");
    printf( a, aritmatika, b);
    */
    printf("+ Penjumlahan\n");
    printf("- Pengurangan\n");
    printf("* Perkalian\n");
    printf("/ Pembagian\n");
    printf("sisa bagi\n");
    printf("masukan pilihan : ");
    scanf("%c",&aritmatika);

    switch (aritmatika){
        case '+':
        printf ("masukan nilai pertama : ");
        scanf ("%d",&a );
        printf ("masukan nilai kedua : ");
        scanf ("%d",&b);
        hasil = a+b;
        //Hasil = a/b;
        printf ("hasilnya adalah : %d", hasil);
        break;

        case '/':
        printf ("masukan nilai pertama : ");
        scanf ("%d",&a );
        printf ("masukan nilai kedua : ");
        scanf ("%d",&b);
        hasil = a/b;
        printf ("hasilnya adalah : %f ", hasil);
        break;

        case '*':
        printf ("masukan nilai pertama : ");
        scanf ("%d",&a );
        printf ("masukan nilai kedua : ");
        scanf ("%d",&b);
        hasil = a*b;
        printf ("hasilnya adalah : %d", hasil);
        break;

        /*case '%':
        printf ("masukan nilai pertama : ");
        scanf ("%d",&a );
        printf ("masukan nilai kedua : ");
        scanf ("%d",&b);
        hasil = a%b;
        printf ("hasilnya adalah : %d", hasil);
        break;*/

        case '-':
        printf ("masukan nilai pertama : ");
        scanf ("%d",&a );
        printf ("masukan nilai kedua : ");
        scanf ("%d",&b);
        hasil = a-b;
        printf ("hasilnya adalah : %d", hasil);
        break;

        default:
        printf ("Nilai tidak diketahui");
    }
}
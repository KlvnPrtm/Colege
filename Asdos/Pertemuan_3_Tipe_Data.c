#include <stdio.h>

int main(){
    int i;
    float f;
    char c;
    double d;

    printf("Masukan Angka Untuk Integer: ");
    scanf("%d",&i);
    printf("Masukan Huruf Untuk Char: ");
    scanf(" %c",&c);
    printf("Masukan Angka Untuk Float: ");
    scanf("%f",&f);
    printf("Masukan Angka Untuk Double: ");
    scanf("%lf",&d);

    printf("%d\n",i);
    printf("%c\n",c);
    printf("%.2f\n",f);
    printf("%.2lf\n",d);

    return 0;
}
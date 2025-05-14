#include <stdio.h>

int main(){
    //print angka dari 1-10
    for (int i = 1; i < 10; i++){
        printf("%d",i);
    }
    //print bintang sesuai inputan user
    int p;
    int Inputan;
    printf("Masukan Angka: ");
    scanf("%d",&Inputan);

    for (p = 0; p < Inputan; p++){
        printf("*");
    }
    //print bintang 3x3
    for (int i = 0; i < 3; i++){
        for (int p = 0; p < 3; p++){
            printf("*");
        }
        printf("\n");
    }
    //print bintang 
    for (int i = 0; i < 3; i++){
        for (int j = i; j < 3; j++){
        printf("* ");
        }
        printf("\n");
    }
    return 0;
}
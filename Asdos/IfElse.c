#include <stdio.h>

int main(){
    int angka1 = 12;

    if(angka1 > 5){
        printf("Angka 1 lebih dari 5");
    }
    else if (angka1 <= 10){
        printf("angka 1 kurang dari 10");
    }
    else if (angka1  < 15){
        printf("angka 1 kurang dari 15");
    }
    else{
        printf("angka 1 lebih dari 15");
    }

    return 0;
}
#include <stdio.h>

int main(){

    int a,b,c,d;

    for (a=1;a<=5;a++){
        for (b=a;b<=5;b++){
        printf (" ");
    }
    for (b=1;b<=a;b++){
        printf("* ");
    }
    // for (b=1;b<a;b++){
        // printf("*");
    // }
    printf("\n");
}
}
#include <stdio.h>

int main(){
    int a=15;
    int b=10;
    int c=5;
    int bonus=100;
    int bonus2=200;
    int bonus3=300;

    if (a>b){
        if (b<c){
            printf("%d",bonus2);
        }else{
            printf("%d",bonus3);
        }
    }else{
        printf("%d",bonus);
    }
}
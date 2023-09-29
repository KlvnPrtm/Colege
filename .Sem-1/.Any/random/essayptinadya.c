#include <stdio.h>

int main(){

    int input;
    scanf("%d",&input);
    for(int i=1;i<=input;i+=2){
        printf("i=%d\n",i);
    }
    printf("selesai");
}
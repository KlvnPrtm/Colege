#include <stdio.h>

int main(){
    int bil=3,input,i;
    printf("Masukan Angka : ");
    scanf ("%d", &input);
    for(i=1;i<=input;i++){
        printf("%d ",bil);
        bil=2*bil+1;
    }

}
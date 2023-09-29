#include <stdio.h>
int main(){
    int bil1=3,bil2=2,input,i;
    printf("Masukan Angka : ",);
    scanf("%d ",&input);
    for(i=1;i<=input;i++){
        if(i%2==1){
            printf("%d ",bil1);
            bil1+=2;
        }
        else{
            printf("%d ",bil2);
            bil2+=4;
        }
    }
}
#include <stdio.h>

int main(){
    int a = 30;
    int b = 10;
    int c = 20;
    int x;


    if (a<b){
        a=2+a;

    }else{
        if (a<c){
            b=b+c;
        }else{
            c=c+10;
            b=b+c;
        }
    }
    x=a+b+c;
    printf("%d",x);

}
#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    int temp = 0;
    
    scanf("%d", &n);
    for (int i = 0; i <= n; i++){
        for (int j = 1; j <= i; j++){
            printf("%d",temp%10);
            temp++;
        }
        printf("\n");
    }
    
}
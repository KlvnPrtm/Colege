#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    scanf ("%d",&n);
    for (int i = 0; i < n; i++){
        printf ("%d\n", i+1);
        if (n == 1) {
            printf ("BUKAN\n");
        }else if (n /= 2) {       
            printf("YA\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#define KIW 100

int main(){
    char test[KIW];
    // scanf("%s", &test);
    // printf("%s", test);
    while (scanf("%s", &test) >= 1)
    {
        printf("%s", test);
    }
    
}
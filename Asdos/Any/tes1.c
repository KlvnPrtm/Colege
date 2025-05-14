#include <stdio.h>

int main(){
    int tinggi=10;
    for (int i = 0; i < tinggi; i++)
    {
        for (int j = 0; j < tinggi-i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < ((i+1)*2)-1; k++)
        {
            if (k == 0 || k == (((i+1)*2)-1)-1)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }
    for (int i = 0; i < (tinggi*2)+1; i++)
    {
        printf("*");
    }
}
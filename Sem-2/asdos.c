#include <stdio.h>

int main(){

    int n,x=1;
    int b=1;
    printf("Masukan tinggi segitiga : ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n*2;j++){
            if(j>=n-i+1 && j<=n+i-1)
            printf("%2d ",x++);
            else
            printf("   ");
        }
        // if(x<10){
        //     printf("  ");
        // }
        printf("\n");
    }
    
    printf ("Kalau DIbalik Jadi Gini Ngab\n");
    
    for(int i=n;i>=1;i--){
        for(int j=n*2;j>=1;j--){
            if(j>=n-i+1 && j<=n+i-1)
            printf("%2d ",b++);
            else if(j>=n*2)
            printf("");
            else
            printf("   ");
        }
        // if(x<10){
        //     printf("  ");
        // }
        printf("\n");
    }
    
    return 0;
}

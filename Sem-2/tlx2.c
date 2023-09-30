#include<stdio.h>
#define M 20

int main(){
    int input;
    // scanf("%d %d",&,&);
    int a[M][M];
    
    printf("\n");
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
        scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3 ; j++){
        printf("%d",a[j][i]);
        }
        printf("\n");
    }
    


}
#include <stdio.h>

int main(){

    int i=1;
    int j=1;
    int k;
    int l=0;
    int n;

    printf("Masukan Angka : ");
    scanf("%d",&n);

    for (i=1;i<=n;i++){
        for (j=n-1;j>=i;j--){
            printf("\t");
        }
        for(k=1;k<=(i+l)*2;k++){
        if ((i%2==1&&k%2==0)){
            printf("\t%d",k);
            }        
            else if (i%2==0&&k%2==1){
            printf("\t%d",k);
            }
        }
        l++;
        printf ("\n");
    }

}
#include <stdio.h>

int main()
{
    int n;
    start:

    printf ("Masukan Angka : ");
    scanf("%d", &n);
    if (n>5||n<1){
        printf("Data Tidak Sesuai!\n");
        goto start;
    }
    int j=n-1, num=1;
    printf("\n");
    for (int i=1; i<=n; i++){
        int l = i%2;
        for (int a=1; a<=j; a++){
            printf("  ");
        }
        if (l == 1){
            for (int k = 1;k<=num*2;k+=2){
                printf (" %d",k);
            }
        }else{
        for (int k = 2;k<=num*2;k+=2){
            printf (" %d",k);
            }
        }
        if(j > i){
            j = j-1;
            num = num+2;
        }
        if(j < i){
            j = j+1;
            num = num-2;
        }
        printf("\n");
    }
    char p;
    printf ("Apakah Anda Ingin Mengulangi (y/t)? ");
    scanf ("%s",&p);
    if(p=='t'||p=='T'){
      goto start;
      // goto menu;
      printf ("s");
    }
    // else
    // (p=='y'||p=='Y');{
    // goto start;
    // }
}

#include <stdio.h>

int main() 
{ 
  start:

    printf ("\n\nMasukkan Angka : ");
    int n;
    int c;
    scanf ("%d",&n);
    int x, y = 1; 
    if(n>5||n<1){
      printf ("Data Tidak Sesuai");
      goto start;
    }
    x = n/2;

      for (int i = 1; i<=n ; i++){
      int l = i%2;
      for (int j = 1; j<=x ; j++){
          printf ("  ");
      }
      if (l == 1){
          for (int k = 1;k<=y*2;k+=2){
              printf (" %d",k);
          }
      }
      if (c == 1){
          for (int k = 2;k<=y*2;k+=2){
              printf (" %d",k);
          }
      }
      
      if (i <= n/2) { 
        x--; 
        y += 2; 
      } else { 
        x++; 
        y -= 2; 
      }
      printf ("\n");
      }
      char p;
      printf ("Apakah Anda Ingin Mengulangi (y/t)");
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
     
  return 0; 
} 

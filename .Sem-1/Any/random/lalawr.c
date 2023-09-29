#include <stdio.h>

int main() 
{ 
  int n ; // prefer odd 
  int i,j,k,l;
//  char p;
  int x, y = 1; 

  // start:
  printf ("\n\nMasukkan Angka : ");
  scanf ("%d",&n);
  // if(n>5||n<1){
  //   printf ("Data Tidak Sesuai");
  //   // goto start;
  // }
  x = n/2;

    for (i = 1; i<=n ; i++){
    l = i%2;
    for (j = 1; j<=x ; j++){
        printf ("  ");
    }
    if (l == 1){
        for (k = 1;k<=y*2;k+=2){
            printf (" %d", k);
        }
    } else {
        for (k = 2;k<=y*2;k+=2){
            printf (" %d", k);
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

     
  return 0; 
} 


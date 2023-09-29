#include <stdio.h>
int main ()

{
 int n, i, j, s, x;
 printf ("Program membuat belah ketupat\n");
 printf ("Masukan jumlah kolom = ");
 scanf ("%d",&x);
 n = x / 2;
 for (i = 1; i <= n; i++)
 
 {
  for (j = n; j >= i; j--)
  printf ("  ");
  
  for (s = 1; s <= i + (i - 1); s++)
  printf (" *");
  printf ("\n");
 }
  for (i = 0; i <= n; i++)
 {
  for (j = 1; j <= i; j++)
  printf ("  ");
  for (s = 0; s >= (i - n) ; s--)
  printf (" *");
  for (s = 1; s <= (n - i) ; s++)
  printf (" *");
  printf ("\n");
 }
 
// return 0;
}
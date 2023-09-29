#include <iostream>
#include <conio.h>
using namespace std;

int main() 
{ 
  int n=7; // prefer odd 
  int i,j; 
  int x = n / 2, y = 1; 
  int k;
  char a;

  // ulang : 
  printf("Masukan Angka : ");
  scanf("%d",&n);

  for(i = 1; i <= n; i++) 
  { 
    for (j = 1; j <= x; j++) 
    { 
      cout << "  ";
    } 
    for (k = 1; k <= y; k++) 
    { 
      cout << " " << k; 
    } 
    if (i <= n/2) 
    { 
      x--; 
      y += 2; 
    } 
    else if(n%2==0)
    {
      cout << " " << k;
    }
    else
    { 
      x++; 
      y -= 2; 
    } 

    cout << endl; 
  } 
  return 0; 
} 
#include <iostream>
#include <conio.h>
using namespace std;

int main() 
{ 
  int n ; // prefer odd 
  int i,j,k,l,p; 
  int x, y = 1; 

  start:
  cout <<"\n\nMasukkan Angka : ";
  cin >> n;
  if(n>5||n<1){
    cout << "Data Tidak Sesuai";
    goto start;
  }
  x = n/2;

    for (i = 1; i<=n ; i++){
    l = i%2;
    for (j = 1; j<=x ; j++){
        cout <<"  ";
    }
    if (l == 1){
        for (k = 1;k<=y*2;k+=2){
            cout <<" "<< k;
        }
    } else {
        for (k = 2;k<=y*2;k+=2){
            cout <<" "<< k;
        }
    }
    if (i <= n/2) { 
      x--; 
      y += 2; 
    } else { 
      x++; 
      y -= 2; 
    } 
    cout <<endl;
    
    }
  return 0; 
} 

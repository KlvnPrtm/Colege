#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{


  cout << "##  Program C++ Belah Ketupat ##" << endl;
  cout << "=========================================" << endl;
  cout << endl;
 
  int lebar_belah_ketupat,i,j,k,l,m;
  int a=1;
  string user;
 
 awal:
  cout << "Input lebar belah ketupat: ";
  cin >> lebar_belah_ketupat;
 
  cout << endl;
 
  for(i=1;i<=lebar_belah_ketupat;i++) {
 
    for(j=1;j<=lebar_belah_ketupat-i;j++) {
      cout << " ";
    }
 
    for(k=1;k<=i;k++) {
      cout << a<<" ";
      a=a+2;
    }
    a=a-1;
    cout << endl;
  }
 
  for(i=1;i<lebar_belah_ketupat;i++) {
 
    for(j=1;j<=i;j++) {
      cout << " ";
    }
 
    for(k=1;k<=lebar_belah_ketupat-i;k++) {

               cout << a << " ";
               a=a+2;

    }
    a=a-1;
    cout << endl;
  }
  cout<<"Ingin mengulang program(T=Iya, F=Tidak) :";
  cin>>user;
  if(user=="T" or user=="t"){
      goto awal;
  }

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    
	int i,n,batas=102,jumlah;
	
	cout<<"program menampilkan bilangan perkalian"<<endl;
	cout<<"======================================"<<endl;
	cout<<"bilangan yang akan dikalikan : ";
	cin>>n;
	cout<<"======================================"<<endl;
	cout<<"menampilkan hasil perkalian :"<<endl;
	
	for(i=0;i<=batas;i++)
	{jumlah=i*n;
	cout<<i<<"*"<<n<<"="<<jumlah<<endl;
	}
	return 0;
}
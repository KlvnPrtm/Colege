#include<stdio.h>
#include <windows.h>


int main(){

char a[]={"AUTHOR"}; 
char b[]={"YOSUA CHRISTIAN PRASETIO / 672022102 "};
char c[]={"MARCELLINUS BRENDAN HANANTA / 672022301 "};
char d[]={"KELVIN HALIM PRATAMA / 672022302 "};

int i,j;
const int panjangNama = sizeof(a);
const int panjangNama1 = sizeof(b);
const int panjangNama2 = sizeof(c);
const int panjangNama3 = sizeof(d);

	for(i=0;i<panjangNama;i++){
		for(j=0;j<1;j++){
			printf("%c", a[i]);
			Sleep(50);
		}
	}
	printf("\n");
	for(i=0;i<panjangNama1;i++){
		for(j=0;j<1;j++){
			printf("%c", b[i]);
			Sleep(50);
		}
	}
	printf("\n");
	for(i=0;i<panjangNama2;i++){
		for(j=0;j<1;j++){
			printf("%c", c[i]);
			Sleep(50);
		}
	}
	printf("\n");
	for(i=0;i<panjangNama3;i++){
		for(j=0;j<1;j++){
			printf("%c", d[i]);
			Sleep(50);
		}
	}
}

#include <stdlib.h>

void tambah(int a, int b, int *c){
	*c = a + b;	
	a = 100;
	b = 200;
}

int add (int a, int b){
	int c;
	c = a + b;
	return c;
}

int sub(int a, int b){
	int c;
	c = a-b;
	return c;
}


int main(){
	int a,b,c,e;
	c = 0;
	int d = 0;
	printf("A = ");
	scanf("%i", &a);
	
	printf("B = ");
	scanf("%i", &b);
	
	printf("E = ");
	scanf("%i", &e);

	tambah(a,b,&c);
	
	printf("\n A= %i",a);
	printf("\n B= %i",b);
	printf("\n C = %i",c);
	
	d = sub(add(a,b),e);
	printf("\n D = %i",d);
	
	printf("\n");	
	
}
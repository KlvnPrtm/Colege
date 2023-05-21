#include <stdlib.h>
#include <stdio.h>

void cetak(int i){
	if (i<=10){
		printf(" %i", i);
		i++;
		cetak(i);		
	} else {
		//printf("Rekursif Selesai!");
	}
}

int factorial(int n, int i, int k){
	if (i<k){
		i++;
		n = n * i;
		factorial(n, i, k);
	} else {
		return (n);
	}
}

int main(){
	//cetak(1);
	int i, hasil;
	hasil=1;
	for (i=5;i>=1;i--){
		//printf(" %i",i);
		hasil*=i;
	}
	printf("\n 5! = %i", hasil);
	
	printf("\nTanpa for:\n");
	
	printf(" P 5 terhadap 2 = %i", factorial(1,1,5) / factorial(1,1,3));
}
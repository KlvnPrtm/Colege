#include<stdio.h>
#include<windows.h>

void setcolor(unsigned short color){
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hCon,color);
}

int main(){
	
	char komponen;
	int tinggi;
	
	printf("Masukkan Tinggi dari cerobong, atap, dan dinding : ");
	scanf("%d", &tinggi);
	printf("Masukkan komponen rumah : ");
	scanf(" %c", &komponen);
	
	//cerobong
	for(int i = 1; i <= tinggi; i++){
		for(int j = 1; j <= tinggi; j++){
			printf(" ");
		}
		for(int j = 0; j <= tinggi; j++){
			setcolor(15);
			printf("%c", komponen);
		}
		printf("\n");
	}
	//atap 
	for(int i = 1; i <= tinggi; i++){
		//atap segitiga
		for(int j = tinggi ; j > i; j--){
			printf(" ");
		}
		for(int k = 1; k<= (2*i - 1); k++){
			setcolor(6);
			printf("%c", komponen);
		}
	//atap jajargenjang
		for(int j = 0; j <= tinggi * 3; j++){
			setcolor(1);
			printf("%c", komponen);
		}
		printf("\n");
	}
	//tembok
	for(int i = 1; i <= tinggi; i++){
		//tembok depan
		for(int j = 1; j <= tinggi*2-1; j++){
			setcolor(5);
			printf("%c", komponen);
		}
		//tembok belakang
		for(int j = 0; j <= tinggi*3; j++){
			setcolor(2);
			printf("%c", komponen);
		}
		printf("\n");
	}
	
}

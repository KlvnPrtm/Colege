#include<stdio.h>
#include<windows.h>

void setcolor(unsigned short color){
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,color);
}

void printBendera(int input){
	int i;
	for(i=1; i<=3; i++){
		int row;
		for (row = input; row>=1; row--){
			int Segitiga;
			for (Segitiga = 1; Segitiga <= 3; Segitiga++){
				int nChar;
				for(nChar = 1; nChar <= input+1; nChar++){
					if ( nChar <= row - 2 ){
						setcolor(3);
						printf("* ");
					}else {
						setcolor(6);
						printf("X ");
					}		
					}
				printf(" ");
			}
			printf("\n");
		}
	}
}
int main(){
	char key=0;
	int isExit=0;
	while(!isExit){
		int input;
		printf("Masukan Bendera : ");
		scanf("%d", &input);
		printBendera(input);
		setcolor(7);
		printf("Press Any Key to go Back");
		key=getch();
		isExit=1;
	}	
}

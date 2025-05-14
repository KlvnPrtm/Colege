#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMenu(int pilihan){
	system("cls");
		
	gotoxy(30,2);
	printf("------------------");
	gotoxy(37,3);
	printf("TR DDP");
	gotoxy(30,4);
	printf("------------------");
	gotoxy(30,5);
	if (pilihan == 1) {
		printf("--> 1.Rumah Pola");	
	}else {
		printf("    1.Rumah Pola");	
	}
	gotoxy(30,6);
	if (pilihan == 2) {
		printf("--> 2.Toko FTI");	
	}else {
		printf("    2.Toko FTI");	
	}
	gotoxy(30,7);
	if (pilihan == 3) {
		printf("--> 3.Bendera");	
	}else {
		printf("    3.Bendera");	
	}
	gotoxy(30,8);
	if (pilihan == 4) {
		printf("--> 4.Author");	
	}else {
		printf("    4.Author");	
	}
	gotoxy(30,9);
	if (pilihan == 5) {
		printf("--> 5.Exit");	
	}else {
		printf("    5.Exit");	
	}
	gotoxy(30,10);
	printf("------------------");
}


int Pilihan = 1;
int i, j;

int main(){
    char key=0;
	int isDone=0;
	while(isDone != 1){
		int Keluar=0;
		while(!Keluar){
			if(kbhit()){
				key=getch();
			}
			
			if(key == '1'){
				Pilihan = 1;
			}
			if(key == '2'){
				Pilihan = 2;
			}
			if(key == '3'){
				Pilihan = 3;
			}
			if(key == '4'){
				Pilihan = 4;
			}
			if(key == '5'){
				Pilihan = 5;
			}
			if(key == 13 || key == 27){
				Keluar = 1;
			}
			printMenu(Pilihan);
			
			// key = 0;
			for(i=0; i <=5000; i++){
				for(j=0; j<=1000; j++){
				}
			}
		}
}
}
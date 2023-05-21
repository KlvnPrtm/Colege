#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
	char key=0;
	int x,y,dx,dy;
	int i,j;
	dx=1;
	dy=1;
	x=5; y=5;
	gotoxy(x,y);
	printf("*");
	while (key!=27){
		if (kbhit()){
			key = getch();
		}
		//Ngapain kita disini?
		system("cls");
		x+=dx;
		y+=dy;
		//if (x>=80) dx=-1;
		//if (x<=1) dx=1;
		if ((x<=1) || (x>=80)) dx=-dx;
		if ((y<=1) || (y>=25)) dy=-dy;
		gotoxy(x,y);
		//printf("O");
		//cetak kotak
		for (i=1;i<=4;i++){
			for (j=1;j<=4;j++){
				gotoxy(x+j, y+i);
				printf("*");
			}
			//printf("\n");
		}
		
		//tunda
		for (i=1;i<=5000;i++)
			for (j=1;j<=10000;j++);
	}//end while
}
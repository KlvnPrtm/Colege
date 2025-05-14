#include <stdio.h>
#include <windows.h>
#include <conio.h>


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
    system("cls");
    char a[]={"Menu-1"};
	gotoxy(75,18);
    printf ("%s",a);
    char b[]={"Menu-2"};
	gotoxy(75,19);
    printf ("%s",b);
    char c[]={"->"};
	gotoxy(72,18);
    printf ("%s",c);
}
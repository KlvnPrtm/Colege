#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(int a){
    for(int x=0;x<a*100;x++){
        for(int y=0;y<a*100;y++){
        }
    }
}

// void exit(int pilihan){

// }

int main(){

    char a[]={"SEE YOU"};
    char b[]={"BYE BYE"};
    char c[]={"THANK YOU"};
    int i; 
    double j;
    char key=0;
    int keluar=0;

    system("cls");

    gotoxy(30,2);
    delay(100);
    for(i=0;a[i];i++){
        printf("%c",a[i]);
        Sleep(20);
        for(j=0;j<=9990000;j++){
        }
    }
    gotoxy(20,5);
    delay(100);
    for(i=0;b[i];i++){
        printf("%c",b[i]);
        Sleep(20);
        for(j=0;j<=9990000;j++){
        }
    }
    gotoxy(35,5);
    delay(100);
    for(i=0;c[i];i++){
        printf("%c",c[i]);
        Sleep(20);
        for(j=0;j<=9990000;j++){
        }
    }

    // key = getch();
    // if(key == 27){
    //     keluar =1;
    //     key=0;
    // }
}
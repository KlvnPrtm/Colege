#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
	char key=0;
	int i,j;
	
	//untuk kepala snake
	int x,y;
	x=20;y=5;
	int dx=0;
	int dy=0;
	
	//untuk ekor snake
	int xe[100];
	int ye[100];
	int pjg=5;
	for (i=1;i<=pjg;i++){
		ye[i]=y;
		xe[i]=x-i;
	}
	
	//untuk makanan
	int xmkn=10;
	int ymkn=20;
	
	//untuk score
	int score=0;
	
	while (key!=27){
		if (kbhit()){
			key=getch();
			if (key=='w'){
				if (dy!=1){
					dx=0;dy=-1;
				}
			} else if (key=='a'){
				if (dx!=1){
					dx=-1;dy=0;
				}
			} else if (key=='s'){
				if (dy!=-1){
					dx=0;dy=1;
				}
			} else if (key=='d'){
				if (dx!=-1){
					dx=1;dy=0;
				}
			}
			
		}
		//hapus
		system("cls");
		//gerak
		//gerak ekor
		if (dx!=0 || dy!=0){
			for (i=pjg;i>1;i--){
				xe[i]=xe[i-1];
				ye[i]=ye[i-1];
			}
			xe[1] = x;
			ye[1] = y;
		}
		
		//gerak kepala
		x+=dx;
		y+=dy;
			
		if (x<1) x=80;
		if (x>80) x=1;
		if (y<1) y=25;
		if (y>25) y=1;
		
		if (xmkn==x && ymkn==y){
			pjg++;
			xmkn = (rand() % 80) + 1;
			ymkn = (rand() % 25) + 1;
			score+=10;
		} 
		
		//cetak
		//cetak score
		//gotoxy(1,1);
		COORD coord;
		coord.X = 1;
		coord.Y = 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
		printf("Score: %i", score);
		
		//cetak makanan
		gotoxy(xmkn, ymkn);
		printf("$");
		
		//cetak ekor
		for (i=1;i<=pjg;i++){
			gotoxy (xe[i],ye[i]);
			printf("*");
		}

		//cetak kepala
		gotoxy(x,y);
		printf("O");
		
		//tunda
		for(i=1;i<=15000;i++){
			for (j=1;j<=15000;j++);
		}
		
		//cek game over
		for (i=1;i<=pjg;i++){
			if (x==xe[i] && y==ye[i]){
				key=27;
				gotoxy(20,5);
				printf("Game Over!");
			}
		}//end for
	}//end while
}
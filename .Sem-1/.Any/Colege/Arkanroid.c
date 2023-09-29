#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
	//untuk bola
	int x,y,dx,dy;
	int i,j;
	x=33; y=22; dx=0; dy=0;
	int game=0;
	
	//untuk papan
	int xp, yp, pjg;
	pjg = 10;
	xp=30;
	yp=23;
	
	//untuk makanan
	int jml_mkn=40;
	int xm[100];
	int ym[100];
	int power[100];
	
	//untuk score
	int score=0;
	
	//inisialisasi
	for (i=1;i<=jml_mkn;i++){
		xm[i] = 20 + i;
		ym[i] = 5;
		power[i]=3;
	}
	
	char key=0;
	while (key!=27){
		if (kbhit()){
			key=getch();
			if (key=='a'){
				if (xp>=4){					
					xp-=3;
					if (game==0){
						x-=3;
					}
				}
			} else if(key=='d'){
				if (xp+pjg<=80){				
					xp+=3;
					if (game==0){
						x+=3;
					}
				}
			} else if (key==' '){
				game=1;
				dx=1; dy=-1;
			}
		}
		// clear / hapus
		system("cls");
		
		// gerak
		x+=dx;
		y+=dy;
		//cek batas layar
		if (x<=1 || x>=80) dx=-dx;
		if (y<=1) dy=-dy;
		
		//cek bawah
		if (x>=xp && x<=xp+pjg && y==yp-1){
			dy=-dy;
		} else if (y>=25){
			//game over
			gotoxy (30, 10);
			printf("G A M E    O V E R ! ! !");
			key=27;
		}
		
		//cek kena makanan
		for (i=1;i<=jml_mkn;i++){
			if (power[i]>0 && x==xm[i] && y==ym[i]){
				score+=10;
				dy=-dy;
				power[i]-=1;
			}
		}
		
		// cetak
		gotoxy(x,y);
		printf("O");
		
		//cetak papan
		for (i=1;i<=pjg;i++){
			gotoxy(xp+i,yp);
			printf("#");
		}
		
		//cetak makanan
		for (i=1;i<=jml_mkn;i++){
			if (power[i]>0){
				gotoxy(xm[i],ym[i]);
				if (power[i]==3){
					printf("$");
				} else if (power[i]==2){
					printf("@");
				} else if (power[i]==1){
					printf("&");
				}
				
			}
		}//end for makanan
		
		//cetak score
		gotoxy(1,1);
		printf("Score: %i", score);
		
		//tunda
		for (i=1;i<=10000;i++)
			for (j=1;j<=10000;j++);
	}//end while
}
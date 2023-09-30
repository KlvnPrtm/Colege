#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void printBorder(){
	int i, j;

	// Print top border	
	for (i = 0; i <= 77; i++){
		gotoxy(0+i,2);
		printf("=");
	}
	
	// Print middle part	  	  
	for (i = 0; i <= 20; i++){
		gotoxy(40,3+i);
	    printf("| \n", i);
	}
				
	// Print bottom border	
	for (i = 0; i <= 77; i++){
		gotoxy(0+i,24);
		printf("=");
	}

}

void printBola(int x, int y){
	gotoxy(x,y);
	printf("O");
}

void printPapan(int x, int y){
	int i;
	for(i=1; i<=5; i++){
		gotoxy(x, y+i);
		printf("#");
	}
}

void printMenu(int menuPil){
	system("cls");
	gotoxy(41,2);
	printf("=====================");
	gotoxy(45,3);
	printf("Ping Pong Game");
	gotoxy(41,4);
	printf("=====================");
	gotoxy(42,5);
	if( menuPil == 1 ){
		printf("  => Play 1 Player");
	}else{
		printf("    Play 1 Player");
	}
	gotoxy(42,6);
	if( menuPil == 2 ){
		printf("  => Play 2 Player");
	}else{
		printf("    Play 2 Player");
	}
	gotoxy(42,7);
	if( menuPil == 3 ){
		printf("  => Exit");
	}else{
		printf("    Exit");
	}
	gotoxy(41,8);
	printf("=====================");
}

void loading(){
	system("cls");
	char a[]={"L O A D I N G . . ."}; 

	int i,j;
	const int loading = sizeof(a);

	gotoxy(45,13);
	for(i=0;i<loading;i++){
		for(j=0;j<1;j++){
			printf("%c", a[i]);
			Sleep(50);
		}
	}
}

void printExit(){
	system("cls");
	char b[]={"SEE YOU "};
	char c[]={"<(^_^)> "};

	int i,j;
	const int panjangNama1 = sizeof(b);
	const int panjangNama2 = sizeof(c);

	gotoxy(47,10);
	for(i=0;i<panjangNama1;i++){
		for(j=0;j<1;j++){
			printf("%c", b[i]);
			Sleep(50);
		}
	}
	gotoxy(47,12);
	for(i=0;i<panjangNama2;i++){
		for(j=0;j<1;j++){
			printf("%c", c[i]);
			Sleep(50);
		}
	}


}

void play1Player(){
	int x=15;
	int y=10;
	int yBot=10;
	int dx=1;
	int dy=1;
	int dyBot=1;
	int xPapanP1=5;
	int yPapanP1=10;
	int xPapanP2=72;
	int yPapanP2=10;
	int geserPapan=2;
	int exit=0;
	int scoreP1=0;
	int scoreP2=0;
	char key=0;
	while(!exit){
		system("cls");
		if(kbhit()){
			key=getch();
			if(key == 'w' && yPapanP1 >= 4){
				yPapanP1 -= geserPapan;
			}
			if(key == 's' && yPapanP1 <=17){
				yPapanP1 += geserPapan;
			}
			if(key == 'a' && xPapanP1 >=2){
				xPapanP1 -= geserPapan;
			}
			if(key == 'd' && xPapanP1 <=10){
				xPapanP1 += geserPapan;
			}
		}
		gotoxy(22,1);
		printf("G E T  7   S C O R E   T O  W I N ! ! !");
		printBorder();
		printPapan(xPapanP1, yPapanP1);
		printPapan(xPapanP2, yPapanP2);
		
		x+=dx;
		y+=dy;
		yBot+=dyBot;

		yPapanP2=yBot;
		if(yPapanP2<=3){
			yPapanP2=yBot+2;
		}else{
			yPapanP2=yBot-2;
		}
		
		if ( x<=1 || x>=79) dx=-dx;
		if ( y<=4 || y>=23 ) dy=-dy;
		if ( yBot <=4 || yBot>=20) dyBot=-dyBot;
		
		if( y>=yPapanP1 && y<=yPapanP1+6 && x==xPapanP1+2 ){
			dx=-dx;			
		}else if(x==1){
			scoreP2+=1;
			x=15;
			y=10;
		}
		if( y>=yPapanP2 && y<=yPapanP2+6 && x==xPapanP2-2 ){
			dx=-dx;	
		}else if(x==79){
			scoreP1+=1;
			x=62;			
			if(y<=4 && y >=27 ){
				y=rand()%10;
			}
			
		}
		
		printBola(x,y);	
			
		gotoxy(30,6);
		printf("%d", scoreP1);
		gotoxy(50,6);
		printf("%d", scoreP2);
		
		if(scoreP1 == 7 ){
			exit=1;
			gotoxy(26,10);
			printf("P L A Y E R   1    W I N ! !");
			gotoxy(26,12);
			printf("PRESS  ANY  KEY  TO  CONTINUE");
			getch();
		}
		if(scoreP2 == 7){
			exit=1;
			gotoxy(26,10);
			printf("P L A Y E R   2    W I N ! !");
			gotoxy(26,12);
			printf("PRESS  ANY  KEY  TO  CONTINUE");
			getch();
		}
				
//		int i;
//		for(i=1; i<=3000; i++){
//			int j;
//			for(j=1; j<=5000; j++){
//			}
//		}
	}
}

void play2Player(){
	int x=15;
	int y=10;
	int dx=1;
	int dy=1;
	int xPapanP1=5;
	int yPapanP1=10;
	int xPapanP2=72;
	int yPapanP2=10;
	int geserPapan=2;
	int exit=0;
	int scoreP1=0;
	int scoreP2=0;
	char key=0;
	while(!exit){
		system("cls");
		if(kbhit()){
			key=getch();
			if(key == 'w' && yPapanP1 >= 4){
				yPapanP1 -= geserPapan;
			}
			if(key == 's' && yPapanP1 <=17){
				yPapanP1 += geserPapan;
			}
			if(key == 'a' && xPapanP1 >=2){
				xPapanP1 -= geserPapan;
			}
			if(key == 'd' && xPapanP1 <=10){
				xPapanP1 += geserPapan;
			}
			if(key == 'i' && yPapanP2 >=4){
				yPapanP2 -= geserPapan;
			}
			if(key == 'k' && yPapanP2 <=17){
				yPapanP2 += geserPapan;
			}
			if(key == 'j' && xPapanP2 >=67){
				xPapanP2 -= geserPapan;
			}
			if(key == 'l' && xPapanP2 <=75){
				xPapanP2 += geserPapan;
			}
		}
		gotoxy(22,1);
		printf("G E T  7   S C O R E   T O  W I N ! ! !");
		printBorder();
		printPapan(xPapanP1, yPapanP1);
		printPapan(xPapanP2, yPapanP2);
		x+=dx;
		y+=dy;
		
		if ( x<=1 || x>=79) dx=-dx;
		if ( y<=4 || y>=23 ) dy=-dy;
		
		if( y>=yPapanP1 && y<=yPapanP1+6 && x==xPapanP1+2 ){
			dx=-dx;			
		}else if(x==1){
			scoreP2+=1;
			x=15;
			if(y<=4 && y >=27 ){
				y=rand()%10;
			}
		}
		if( y>=yPapanP2 && y<=yPapanP2+6 && x==xPapanP2-2 ){
			dx=-dx;
		}else if(x==79){
			scoreP1+=1;
			x=62;
			if(y<=4 && y >=27 ){
				y=rand()%10;
			}
		}
		
		printBola(x,y);	
			
		gotoxy(30,6);
		printf("%d", scoreP1);
		gotoxy(50,6);
		printf("%d", scoreP2);
		
		if(scoreP1 == 7 ){
			exit=1;
			gotoxy(26,10);
			printf("P L A Y E R   1    W I N ! !");
			gotoxy(26,12);
			printf("PRESS  ANY  KEY  TO  CONTINUE");
			getch();
		}
		if(scoreP2 == 7){
			exit=1;
			gotoxy(26,10);
			printf("P L A Y E R   2    W I N ! !");
			gotoxy(26,12);
			printf("PRESS  ANY  KEY  TO  CONTINUE");
			getch();
		}
				
//		int i;
//		for(i=1; i<=3000; i++){
//			int j;
//			for(j=1; j<=5000; j++){
//			}
//		}
	}
}

main(){
	int done=0;
	int exit=0;
	int menuPil=1;
	char key=0;
	while(!done){
		while(!exit){
			if(kbhit()){
				key=getch();
			}
			if( key == 72 ){
				menuPil-=1;
				if(menuPil == 0){
					menuPil = 3;
				}
			}
			if( key == 80 ){
				menuPil+=1;
				if(menuPil == 4){
					menuPil = 1;
				}
			}
			if( key == 13 || key == 27 ){
				exit = 1;
			}
			printMenu(menuPil);	
			key = 0;		
		}
		if(menuPil==1){
			exit=0;
			loading();
			play1Player();
		}
		
		if(menuPil==2){
			exit=0;
			loading();
			play2Player();	
		}
		
		if(menuPil==3){
			printExit();
			done=1;
		}
//		int i;
//		for(i=1; i<=3000; i++){
//			int j;
//			for(j=1; j<=5000; j++){
//			}
//		}
	}
}

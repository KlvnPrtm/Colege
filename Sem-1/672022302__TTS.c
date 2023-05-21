#include <stdio.h>
#include <windows.h>
#include <conio.h>


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int x, y;
int i, j;
int Keluar = 0;
int Pilihan = 1;

void printMenu(int pilihan){
	system("cls");
		
	gotoxy(30,2);
	printf("------------------");
	gotoxy(37,3);
	printf("MENU");
	gotoxy(30,4);
	printf("------------------");
	gotoxy(33,5);
	if (pilihan == 1) {
		printf("--> 1.FPB");	
	}else {
		printf("    1.FPB");	
	}
	gotoxy(33,6);
	if (pilihan == 2) {
		printf("--> 2.KPK");	
	}else {
		printf("    2.KPK");	
	}
	gotoxy(33,7);
	if (pilihan == 3) {
		printf("--> 3.Keluar");	
	}else {
		printf("    3.Keluar");	
	}
	gotoxy(30,8);
	printf("------------------");
}

void printFpb(){
	system("cls");
	printf("FPB\n");
	int n1, n2; 
	int hasil;
	
	printf("Masukan Bilangan Bulat Pertama = ");
	scanf("%d", &n1);
	printf("Masukan Bilangan Bulat Kedua = ");
	scanf("%d", &n2);
	for (i = 1; i<=n1 && i<=n2; i++){
		if(n1 % i == 0 && n2 % i == 0){
			hasil = i;
		}
	}
	printf("Bilangan Bulat Pertama Adalah  %d\n", n1);
	printf("Bilangan Bulat Kedua Adalah %d\n", n2);
	printf("FPB Dari %d Dan %d Adalah %d", n1, n2, hasil);
}
	

void printKpk(){
	system("cls");
	printf("KPK\n");
	int a;
	int b;
	int kpk=0;
	int p=0;
	    printf("Masukkan Bilangan Bulat Pertama : "); 
		scanf("%d",&a);
	    printf("Masukkan Bilangan Bulat Kedua = "); 
		scanf("%d",&b);
		printf("\nBilangan Pertama = ");
		for(i=a;i<=150;i+=a){
        printf("%d ",i);
    	}
		printf("\nBilangan Kedua = ");
    	for(i=b;i<=150;i+=b){
        printf("%d ",i);
    	}
	    for(i = 1; i <= b; i++){
	        kpk+=a;
	        if(kpk % b==0){
	            printf("\n\nKelipatan Persekutuannya = %d", kpk);
	        }
	    }
		for(i=1;i<=b;i++){
        p=p+a;
            //x+=x;
            //y+=y;
            //printf ("%d, ",x);
            //printf ("%d, ",y);
        if(p%b==0){
            // printf ("Bilangan Pertama Adalah : ");
            // printf ("%d dan %d\n",y,kpk);
            // printf ("%d",kpk);

            printf("\n\nKelipatan Persekutuan Terkecilnya adalah %d",p);
            printf("\nJadi KPK dari %d dan %d adalah %d",a,b,p);
            break; //berhenti di hasil pertama
        }
    }
	}


int main(){
	char key=0;
		Keluar=0;
		while(Keluar != 1){
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
			if(key == 13){ 
				Keluar = 1;
			}
			printMenu(Pilihan);
			
			key = 0;
			for(i=0; i <=5000; i++){
				for(j=0; j<=10000; j++){
				}
			}
		}
		if(Pilihan == 1){
			Keluar=0;
			while(!Keluar) {
				printFpb();
				printf("\nPress Esc To Exit");
				key = getch();
				if(key == 27){
					Keluar = 1;
					key = 0;
				}
			}
		}
		if(Pilihan == 2){
			Keluar=0;
			while(Keluar != 1) {
				printKpk();
				printf("\nPress Esc To Exit");
				key = getch();
				if(key == 27){
					Keluar =1;
					key=0;
				}
			}
		}
		if(Pilihan==3){
			Keluar = 1;
		}
	}


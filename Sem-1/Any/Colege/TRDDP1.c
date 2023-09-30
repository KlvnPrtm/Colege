#include <stdio.h>
#include <windows.h>
#include <conio.h>


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(unsigned short color){
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,color);
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

void programRumah(){
	system("cls");
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
	setcolor(7);
	printf("Tekan Enter Untuk Keluar");
}

void MenuKasir(){
	system("cls");
	printf("--------------------------------------------------\n");
    printf("|       Daftar dan Harga Barang Toko FTI         |\n");
    printf("|------------------------------------------------|\n");
    printf("| ID    | Nama Barang            | Harga Barang  |\n");
    printf("|-------|------------------------|---------------|\n");
    printf("| 1.    | Flash Disk Toshiba 4 GB| Rp.  50000    |\n");
    printf("| 2.    | Flash Disk Toshiba 8 GB| Rp.  65000    |\n");
    printf("| 3.    | Flash Disk Toshiba 16GB| Rp.  90000    |\n");
    printf("| 4.    | Flash Disk Toshiba 32GB| Rp.  110000   |\n");
    printf("| 5.    | Flash Disk Sandisk 4 gb| Rp.  75000    |\n");
    printf("| 6.    | Hard Disk WD 500 GB    | Rp.  700000   |\n");
    printf("| 7.    | Hard Disk WD 1 TB      | Rp.  900000   |\n");
    printf("| 8.    | Hard Disk Dell 500 GB  | Rp.  670000   |\n");
    printf("| 9.    | Hard Disk Dell 1 TB    | Rp.  800000   |\n");
    printf("| 10.   | Tongsis                | Rp.  60000    |\n");
    printf("--------------------------------------------------\n");
}


void printBendera(int input){
	int i;
	system("cls");
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

void printAuthor(){
	char a[]={"AUTHOR"}; 
	char b[]={"YOSUA CHRISTIAN PRASETIO / 672022102 "};
	char c[]={"MARCELLINUS BRENDAN HANANTA / 672022301 "};
	char d[]={"KELVIN HALIM PRATAMA / 672022302 "};

	int i,j;
	const int panjangNama = sizeof(a);
	const int panjangNama1 = sizeof(b);
	const int panjangNama2 = sizeof(c);
	const int panjangNama3 = sizeof(d);
	system("cls");

	gotoxy(45,2);
	for(i=0;i<panjangNama;i++){
		for(j=0;j<1;j++){
			printf("%c", a[i]);
			Sleep(25);
		}
	}
	gotoxy(30,4);
	for(i=0;i<panjangNama1;i++){
		for(j=0;j<1;j++){
			printf("%c", b[i]);
			Sleep(25);
		}
	}
	gotoxy(30,6);
	for(i=0;i<panjangNama2;i++){
		for(j=0;j<1;j++){
			printf("%c", c[i]);
			Sleep(25);
		}
	}
	gotoxy(30,8);
	for(i=0;i<panjangNama3;i++){
		for(j=0;j<1;j++){
			printf("%c", d[i]);
			Sleep(25);
		}
	}
}

void printExit(){
	system("cls");
	char a[]={"THANK YOU"}; 
	char b[]={"SEE YOU "};
	char c[]={"<(^_^)> "};

	int i,j;
	const int panjangNama = sizeof(a);
	const int panjangNama1 = sizeof(b);
	const int panjangNama2 = sizeof(c);


	gotoxy(45,8);
	for(i=0;i<panjangNama;i++){
		for(j=0;j<1;j++){
			printf("%c", a[i]);
			Sleep(25);
		}
	}
	gotoxy(40,10);
	for(i=0;i<panjangNama1;i++){
		for(j=0;j<1;j++){
			printf("%c", b[i]);
			Sleep(25);
		}
	}
	gotoxy(50,10);
	for(i=0;i<panjangNama2;i++){
		for(j=0;j<1;j++){
			printf("%c", c[i]);
			Sleep(25);
		}
	}

}

int x, y;
int i, j;
// int Keluar = 0;
int Pilihan = 1;




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
		// Pilihan 1
		if(Pilihan == 1){
			Keluar=0;
			while(!Keluar){
				programRumah();
				setcolor(7);
				key=getch();
				if(key == 13){
					Keluar = 1;
					key = 0;
				}
			}
		}
		//Pilihan 2
		if(Pilihan == 2){
			Keluar=0;
			while(!Keluar){
				MenuKasir();
				int harga[11]={50000, 65000, 90000, 110000, 75000, 700000, 900000, 670000, 800000, 60000};
				char barang[100][100]={"Flash Disk Toshiba 4 GB", 
									"Flash Disk Toshiba 8 GB", 
									"Flash Disk Toshiba 16 GB", 
									"Flash Disk Toshiba 32 GB", 
									"Flash Disk Sandisk 4 GB",
									"Hard Disk WD 500 GB",
									"Hard Disk WD 1 TB",
									"Hard Disk Dell 500 GB",
									"Hard Disk Dell 1 TB",
									"Tongsis",};
				int input;
				int keranjang[10] = {0,0,0,0,0,0,0,0,0,0};
				int jumlah;
				int sum=0;
				int jumlahUang;
				int hasil;
				char opt='y'; //opt = option
				int exit = 0;
				MenuKasir();
				while(opt == 'y'){
					printf("Masukan Kode Barang : ");
					scanf("%d", &input);
					exit=0;
					if( input > 0 && input <=10 ){
						while(!exit){
							printf("Masukan Jumlah      : ");
							scanf("%d", &jumlah);
							if(jumlah > 0 ){
								keranjang[input-1]+=jumlah;
								exit=1;
							}else{
								printf("Isi Yang Benar!\n");
							}
						}
						printf("Mau Nambah? (y/n) : ");
						scanf(" %c", &opt);
					}else{
						printf("Barangnya Gak Ada\n");
					}		
				}
				
				int i;
				for(i=0; i<=10; i++){
					if(keranjang[i] != 0){
						// printf("%s x %d = Rp. %d\n", barang[i], keranjang[i], harga[i]*keranjang[i]);
						sum+=harga[i]*keranjang[i];
					}
				}
				printf("Total Yang Harus Dibayar : %d\n", sum);
				
				exit=0;
				while(!exit){
					printf("Masukan Uang Anda : ");
					scanf("%d", &jumlahUang);
					if(jumlahUang < sum){
						printf("Uang Anda Tidak Cukup & Ga Boleh Utang\n");
					}else{
						printf("Kembalian Anda : %d\n", jumlahUang-sum);
						printf("Terima Kasih");
						exit=1;
					}
					printf("\nTekan Enter/Esc Untuk Kembali");
				}
				key=getch();
				if(key == 13){
				Keluar = 1;
				key = 0;
				}
			}
		}
		//Pilihan 3
		if(Pilihan == 3){
			Keluar=0;
			while(!Keluar){
					system("cls");
					int input;
					printf("Masukan Ukuran Bendera : ");
					scanf("%d", &input);
					printBendera(input);
					setcolor(7);
					printf("Press Enter to go Back");
					key=getch();
					if(key == 13){
					Keluar = 1;
					key = 0;
				}
			}
		}
		//Pilihan 4
		if(Pilihan == 4){
			Keluar=0;
			while(!Keluar){
				printAuthor();
				key=getch();
					if(key == 13){
					Keluar = 1;
					key = 0;
				}
			}
		}
		//Pilihan 5
		if(Pilihan==5){
			printExit();
			isDone = 1;
		}
	}
}

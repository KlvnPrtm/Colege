#include<stdio.h>
#include<windows.h>

void setcolor(unsigned short color){
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hCon,color);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void programRumah(){
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
}

void printMenuKasir(){
	gotoxy(10,2);
	printf("--------------------------------------------------\n");
	gotoxy(10,3);
    printf("|       Daftar dan Harga Barang Toko FTI         |\n");
    gotoxy(10,4);
    printf("|------------------------------------------------|\n");
    gotoxy(10,5);
    printf("| ID    | Nama Barang            | Harga Barang  |\n");
    gotoxy(10,6);
    printf("|-------|------------------------|---------------|\n");
    gotoxy(10,7);
    printf("| 1.    | Flash Disk Toshiba 4 GB| Rp.  50000    |\n");
    gotoxy(10,8);
    printf("| 2.    | Flash Disk Toshiba 8 GB| Rp.  65000    |\n");
    gotoxy(10,9);
    printf("| 3.    | Flash Disk Toshiba 16GB| Rp.  90000    |\n");
    gotoxy(10,10);
    printf("| 4.    | Flash Disk Toshiba 32GB| Rp.  110000   |\n");
    gotoxy(10,11);
    printf("| 5.    | Flash Disk Sandisk 4 gb| Rp.  75000    |\n");
    gotoxy(10,12);
    printf("| 6.    | Hard Disk WD 500 GB    | Rp.  700000   |\n");
    gotoxy(10,13);
    printf("| 7.    | Hard Disk WD 1 TB      | Rp.  900000   |\n");
    gotoxy(10,14);
    printf("| 8.    | Hard Disk Dell 500 GB  | Rp.  670000   |\n");
    gotoxy(10,15);
    printf("| 9.    | Hard Disk Dell 1 TB    | Rp.  800000   |\n");
    gotoxy(10,16);
    printf("| 10.   | Tongsis                | Rp.  60000    |\n");
    gotoxy(10,17);
    printf("--------------------------------------------------\n");
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
				//printf(" ");
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

	gotoxy(45,2);
	for(i=0;i<panjangNama;i++){
		for(j=0;j<1;j++){
			printf("%c", a[i]);
			Sleep(100);
		}
	}
	gotoxy(30,4);
	for(i=0;i<panjangNama1;i++){
		for(j=0;j<1;j++){
			printf("%c", b[i]);
			Sleep(100);
		}
	}
	gotoxy(30,6);
	for(i=0;i<panjangNama2;i++){
		for(j=0;j<1;j++){
			printf("%c", c[i]);
			Sleep(100);
		}
	}
	gotoxy(30,8);
	for(i=0;i<panjangNama3;i++){
		for(j=0;j<1;j++){
			printf("%c", d[i]);
			Sleep(100);
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
			Sleep(100);
		}
	}
	gotoxy(40,10);
	for(i=0;i<panjangNama1;i++){
		for(j=0;j<1;j++){
			printf("%c", b[i]);
			Sleep(100);
		}
	}
	gotoxy(50,10);
	for(i=0;i<panjangNama2;i++){
		for(j=0;j<1;j++){
			printf("%c", c[i]);
			Sleep(100);
		}
	}

}

void printMenu(){
	system("cls");
	printf("======================\n");
	printf("         MENU         \n");
	printf("======================\n");
	printf("1. Rumah Pola\n");
	printf("2. Toko Warisan FTI\n");
	printf("3. Bendera\n");
	printf("4. Author\n");
	printf("5. Exit\n");
}

int pilihan, input;

int main(){
	char key = 0;
	int isExit = 0;
	while( isExit != 1){
		printMenu();
		printf("Masukan Pilihan : ");
		scanf("%d", &pilihan);
		int exit=0;
		switch(pilihan){
			case 1 :
				//Program Rumah Pola
				while (!exit){
					system("cls");
					programRumah();
					setcolor(7);
					printf("Press Enter to go Back");
					key=getch();
					exit = 1;
				}
				break;
			case 2 :
				//Toko Warisan FTI
				while (!exit){
				int harga[10]={50000, 65000, 90000, 110000, 75000, 700000, 900000, 670000, 800000, 60000};
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
				int keluar = 0;
				system("cls");
				printMenuKasir();
				while(opt == 'y'){
					printf("Masukan Kode Barang : ");
					scanf("%d", &input);
					keluar=0;
					if( input > 0 && input <=10 ){
						while(!keluar){
							printf("Masukan Jumlah      : ");
							scanf("%d", &jumlah);
							if(jumlah > 0 ){
								keranjang[input-1]+=jumlah;
								keluar=1;
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
						printf("%s x %d = Rp. %d\n", barang[i], keranjang[i], harga[i]*keranjang[i]);
						sum+=harga[i]*keranjang[i];
					}
				}
				printf("Total Yang Harus Dibayar : %d\n", sum);

				keluar=0;
				while(!keluar){
					printf("Masukan Uang Anda : ");
					scanf("%d", &jumlahUang);
					if(jumlahUang < sum){
						printf("Uang Anda Tidak Cukup & Ga Boleh Utang\n");
					}else{
						printf("Kembalian Anda : %d\n", jumlahUang-sum);
						printf("Terima Kasih");
						keluar=1;
					}
				}
				printf("\nPress Enter to go Back");
				key=getch();
				exit = 1;
			}
				break;		
			case 3 :
				//Bendera
				while(!exit){
					system("cls");
					int input;
					printf("Masukan Ukuran Bendera : ");
					scanf("%d", &input);
					printBendera(input);
					setcolor(7);
					printf("Press Enter to go Back");
					key=getch();
					exit=1;	
					}	
				break;
			case 4 :
				//Author
				while(!exit){
					system("cls");
					printAuthor();
					printf("\nPress Enter to go Back");
					key=getch();
					exit=1;
				}
				break;
			case 5 :
				//Exit
					system("cls");
					printExit();
					isExit = 1;
					getch();
				break;	
			default :
				//Proteksi
				printf("Hanya Bisa Memilih 1 - 5\n");
				printf("Press any key to Continue");
				getch();
				
		}
	}
}
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

void printMenu(){
	printf("TR DDP : \n");
	printf("1. Rumah\n");
	printf("2. Toko\n");
	printf("3. Bendera\n");
	printf("4. Author\n");
	printf("5. Exit\n");
}

void printMenuToko(){
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
    printf("--------------------------------------------------\n\n");
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
						printf("x ");
					}else {
						setcolor(6);
						printf("y ");
					}		
					}
				printf(" ");
			}
			printf("\n");
		}
	}
}

void rumah(){
	char komponen;
	int tinggi;
	int i, j, k;
	system("cls");
	printf("Masukkan Tinggi dari cerobong, atap, dan dinding : ");
	scanf("%d", &tinggi);
	printf("Masukkan komponen rumah : ");
	scanf(" %c", &komponen);
	
	//cerobong
	for(i = 1; i <= tinggi; i++){
		for(j = 1; j <= tinggi; j++){
			printf(" ");
		}
		for( j = 0; j <= tinggi; j++){
			setcolor(15);
			printf("%c", komponen);
		}
		printf("\n");
	}
	//atap 
	for( i = 1; i <= tinggi; i++){
		//atap segitiga
		for( j = tinggi ; j > i; j--){
			printf(" ");
		}
		for( k = 1; k<= (2*i - 1); k++){
			setcolor(6);
			printf("%c", komponen);
		}
	//atap jajargenjang
		for( j = 0; j <= tinggi * 3; j++){
			setcolor(1);
			printf("%c", komponen);
		}
		printf("\n");
	}
	//tembok
	for( i = 1; i <= tinggi; i++){
		//tembok depan
		for( j = 1; j <= tinggi*2-1; j++){
			setcolor(5);
			printf("%c", komponen);
		}
		//tembok belakang
		for( j = 0; j <= tinggi*3; j++){
			setcolor(2);
			printf("%c", komponen);
		}
		printf("\n");
	}
	setcolor(7);
	printf("Press Any Key to Go Back");
	getch();
	system("cls");

}

void toko(){
	system("cls");
	printMenuToko();
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
	int exit = 0;
	while(opt == 'y'){
		exit=0;
		printf("Masukan Kode Barang : ");
		scanf("%d", &input);
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
			printf("%s x %d = Rp. %d\n", barang[i], keranjang[i], harga[i]*keranjang[i]);
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
			getch();
			exit=1;
			system("cls");
		}
	}
}

void bendera(){
	char key=0;
	int isExit=0;
	system("cls");
	while(!isExit){
		int input;
		printf("Masukan Bendera : ");
		scanf("%d", &input);
		printBendera(input);
		setcolor(7);
		printf("Press Any Key to go Back");
		key=getch();
		system("cls");
		isExit=1;
	}
}
void printAuthor(){
	system("cls");
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

int main(){
	int input;
	int exit=0;
	while(!exit){
		printMenu();
		printf("Masukan Pilihan : ");
		scanf("%d", &input);
		switch(input){
			case 1:
				rumah();
				break;
			case 2:
				toko();
				break;	
			case 3:
				bendera();
				break;
			case 4:
				printAuthor();
				break;
			case 5:
				printExit();
				exit=1;
				break;
			default :
				printf("Menu Tidak Ada\n");
				printf("Press Any Key to Continue");
				getch();
				system("cls");
				
		}
	}
}

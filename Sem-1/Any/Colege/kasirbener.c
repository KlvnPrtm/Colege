#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void MenuKasir(){
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


int main(){
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
			exit=1;
		}
	}
}

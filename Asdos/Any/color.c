#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

int main(){
    char key=0;
    int exit=0;

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
}
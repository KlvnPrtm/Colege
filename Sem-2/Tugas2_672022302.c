#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define Bzz 90

int null=1;
int null1=0;
int HariBlotongan[Bzz];
int HariGrogol[Bzz];
int HariTegalrejo[Bzz];
int HariTingkir[Bzz];
char kk;

char Hari[Bzz][Bzz]={"Senin","Selasa","Rabu","Kamis","Jumat"};
char Ulang;

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Ulang1(){
    printf("\n\nPress Anything To Continue\n");
    Ulang=getch();
}

void Author(){
    system("cls");
    char a[]={"THANK YOU"}; 
	char b[]={"SEE YOU "};
	char c[]={"<(^_^)> "};
    char d[]={"KELVIN HALIM PRATAMA / 672022302 "};
    int i,j;
	const int panjangNama = sizeof(a);
	const int panjangNama1 = sizeof(b);
	const int panjangNama2 = sizeof(c);
    const int panjangNama3 = sizeof(d);
    gotoxy(35,8);
    for(i=0;i<panjangNama3;i++){
		for(j=0;j<1;j++){
			printf("%c", d[i]);
			Sleep(60);
		}
	}
	gotoxy(45,10);
	for(i=0;i<panjangNama;i++){
		for(j=0;j<1;j++){
			printf("%c", a[i]);
			Sleep(60);
		}
	}
	gotoxy(42,12);
	for(i=0;i<panjangNama1;i++){
		for(j=0;j<1;j++){
			printf("%c", b[i]);
			Sleep(60);
		}
	}
	gotoxy(52,12);
	for(i=0;i<panjangNama2;i++){
		for(j=0;j<1;j++){
			printf("%c", c[i]);
			Sleep(60);
		}
	}
}

void MasukanData(){
    system("cls");
    printf("Blotongan\n");
    for (int i = 0; i < 5; i++){
        printf("Jumlah Penumpang Hari %s\t: ", Hari[i]);
        scanf("%d",&HariBlotongan[i]);
    }
    printf("\nGrogol\n");

    for (int i = 0; i < 5; i++){
        printf("Jumlah Penumpang Hari %s\t: ", Hari[i]);
        scanf("%d",&HariGrogol[i]);
    }
    printf("\nTegalRejo\n");
    
    for (int i = 0; i < 5; i++){
        printf("Jumlah Penumpang Hari %s\t: ", Hari[i]);
        scanf("%d",&HariTegalrejo[i]);
    }
    printf("\nTingkir\n");

    for (int i = 0; i < 5; i++){
        printf("Jumlah Penumpang Hari %s\t: ", Hari[i]);
        scanf("%d",&HariTingkir[i]);
    }
    printf("\nData Berhasil Dimasukan\n\n");
    Ulang1();
}

void LihatData(){
    system("cls");
    printf("Data Penumpang Rute Blotongan \n");
    for (int i = 0; i < 5; i++){
        printf("%s\t:%d\n",Hari[i],HariBlotongan[i]);
    }
    printf("\nData Penumpang Rute Grogol\n");
    for (int i = 0; i < 5; i++){
        printf("%s\t:%d\n",Hari[i],HariGrogol[i]);

    }
    printf("\nData Penumpang Rute TegalRejo\n");
    for (int i = 0; i < 5; i++){
        printf("%s\t:%d\n",Hari[i],HariTegalrejo[i]);

    }
    printf("\nData Penumpang Rute Tingkir\n");
    for (int i = 0; i < 5; i++){
        printf("%s\t:%d\n",Hari[i],HariTingkir[i]);

    }
    Ulang1();
}

void Senin(){
    system("cls");
    int Hasil;
    Hasil = HariBlotongan[0]+HariGrogol[0]+HariTegalrejo[0]+HariTingkir[0];
    printf("Total Penumpang di Hari Senin adalah %d Penumpang",Hasil);
    Ulang1();
}

void Selasa(){
    system("cls");
    int min;
    min=HariBlotongan[1];
    if (HariGrogol[1]<min){
        min=HariGrogol[1];
    }
    if (HariTegalrejo[1]<min){
        min=HariTegalrejo[1];
    }
    if (HariTingkir[1]<min){
        min=HariTingkir[1];
    }
    printf("Nilai Terkecil Hari Selasa Adalah : %d",min);
    
    Ulang1();

}

void HapusData(){
    int l=1;
    for(int p=0;p<l;p++){
        system("cls");
        printf("Apakah Anda Yakin Ingin Menghapus Data (y/n) ?");
        scanf(" %c",&kk);
        if (kk == 'Y' || kk == 'y'){
            printf("Data Berhasil Dihapus");
            null=1;
            null1=0;
        }
        else if (kk == 'N' || kk == 'n'){
            printf("Pie Toh Maz");
        }
        else{
            printf("Input Yang Bener");
            l++;
        }
        Ulang1();
    }
    

}

void Menu(){
    system("cls");
    printf("1. Masukan Data\n");
    printf("2. Lihat Data\n");
    printf("3. Lihat Jumlah Penumpang di Hari Senin\n");
    printf("4. Cetaklah Jumlah Penumpang Paling Sedikit Pada Hari Selasa\n");
    printf("5. Hapus Data\n");
    printf("6. Keluar Program\n");
}



int main(){
    int PilihMenu;
    int p=1;
    for (int i = 1; i <= p; i++){
        Menu();
        printf("Pilih : ");
        scanf("%d", &PilihMenu);
        if(PilihMenu == 1){
            if (null1 == 1){
                printf("Silahkan Hapus Data Terlebih Dahulu");
                Ulang1();
            }else{
                MasukanData();
                null=0;
                null1=1;
            }
         }
        if (PilihMenu == 2){
            if (null==1){
                printf("Tidak Ada Data...");
                Ulang1();
            }else{
                LihatData();
            }
        }
        if (PilihMenu == 3){
            if (null==1){
                printf("Tidak Ada Data...");
                Ulang1();
            }else{
                Senin();
            }
        }
        if (PilihMenu == 4){
            if (null==1){
                printf("Tidak Ada Data...");
                Ulang1();
            }else{
                Selasa();
            }
        }
        if (PilihMenu == 5){
            if (null==1){
                printf("Tidak Ada Data...");
                Ulang1();
            }else{
                HapusData();
            }
        }
        if (PilihMenu == 6){
            Author();
            exit(0);
            break;
        }
        if (PilihMenu<=0||PilihMenu>=6){
            printf("Masukan Sesuai Yang Diinginkan ! ! !\n");
            Ulang=getch();
        }
        p++;
    }
    
}
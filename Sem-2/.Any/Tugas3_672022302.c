#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 90

char Ulang=0;
char Urutan[MAX][MAX]={"Pertama", "Kedua", "Ketiga", "Keempat", "Kelima"};
char InputBuah[MAX][MAX];
float Harga[MAX];
int *Harga1[MAX];
// struct TokoBuah Toko[i];
int Input;
int p=0;
char Search[MAX];
float SearchPrice;
char buah[5][MAX];
float harga[5];


typedef struct TokoBuah{
    char Buah[MAX];
    float Harga;
}TokoBuah;

TokoBuah Toko[5];

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

void Menu(){
    printf("1. Tampilan daftar buah sesuai inputan user (belum terurut)\n");
    printf("2. Tampilan daftar buah yang sudah di sorting berdasarkan nama\n");
    printf("3. Tampilkan daftar buah yang sudah di sorting berdasarkan harga\n");
    printf("4. Bisa searching berdasarkan nama (huruf kecil besar tidak pengaruh)\n");
    printf("5. Bisa searching berdasarkan harga\n");
    printf("6. Exit\n");
}

void Inputan(){
    for (int i = 0; i <= p; i++){
    printf("Masukan Berapa Banyak Buah Yang Ingin Anda Beli (Maksimal 5) : ");
    scanf ("%d",&Input);
        if(Input >= 1 && Input <= 5) {
            for (int i = 0; i < Input; i++){
                printf("Buah %s Yang Ingin Anda Beli = ", Urutan[i]);
                scanf(" %[^\n]s",&Toko[i].Buah);
                strcpy(buah[i],Toko[i].Buah);
                printf("Berapa Harga Buah %s Yang Anda Inginkan = ", Toko[i].Buah);
                scanf("%f",&Toko[i].Harga);
                harga[i]=Toko[i].Harga;
                printf("\n");
            }
        }else{
            printf("Manimal 1 dan Maksimal 5!!!\n");
            Ulang=getch();
            p++;
        }
        system("cls");
    }
}

void display(){
    for(int i=0; i<Input; i++){
        printf("Buah  : %s\n", Toko[i].Buah);
        printf("Harga : %.2f\n", Toko[i].Harga);
    }
}

void BelumUrut(){
    system("cls");

    puts("\nMenu Belanja Anda Adalah : ");
    for (int i = 0; i < Input; i++){
        printf("Buah :\t%s \nHarga:\t%.2f\n", buah[i], harga[i]);
    }
}

void swap(TokoBuah *a, TokoBuah *b ){
    TokoBuah temp=*a;
    *a=*b;
    *b=temp;
}

void InsertionSortFruit(struct TokoBuah *Toko, int n){
    system("cls");
    int Found=0;
    char Huruf[MAX];
    char Huruf1[MAX];
    for(int i = 1; i <n; i++){
        int j=i;
            strcpy(Huruf, Toko[j-1].Buah);
            strcpy(Huruf1, Toko[j].Buah);
            for (int k = 0; Huruf[k]; k++){
                Huruf[k]=tolower(Huruf[k]);
            }
            for (int k = 0; Huruf1[k]; k++){
                Huruf1[k]=tolower(Huruf1[k]);
            }
        while(j>0 && strcmp(Huruf,Huruf1)>0){
            swap(&Toko[j],&Toko[j-1]);
            j--;
        }
    }
}

void InsertionSortPrice(struct TokoBuah *Toko, int n){
    system("cls");
    for(int i = 0; i < n; i++){
        int j=i;
        while(j>=0 && Toko[j-1].Harga>Toko[j].Harga){
            swap(&Toko[j],&Toko[j-1]);
            j--;
        }
    }
}

void SequentialSearchFruit(){
    int Found;
    char Huruf[MAX];
    char Huruf1[MAX];
    TokoBuah Simpan;
    printf("Masukan Buah Yang Ingin Dicari : ");
    scanf("%s",&Search);
    int q=1;

    for(int i=0; i<q; i++){
        Found=0;
    }

    for (int i = 0; i < Input ; i++){
        strcpy(Huruf, Toko[i].Buah);
        strcpy(Huruf1, Search);
        for (int k = 0; Huruf[k]; k++){
            Huruf[k]=tolower(Huruf[k]);
        }
        for (int k = 0; Huruf1[k]; k++){

            Huruf1[k]=tolower(Huruf1[k]);
        }
        if(strcmp(Huruf, Huruf1) == 0){
            printf("Buah Ditemukan\n");
            Found=1;
            q++;
        }
    }
    if(Found==0){
        printf("Buah Tidak Ditemukan\n");
    }
}

void SequentialSearchPrice(){
    printf("Masukan Harga Yang Ingin Dicari : ");
    scanf("%f",&SearchPrice);
    int b;
    int q=1;

    for(int i=0; i<q; i++){
        b=0;
    }


    for (int i = 0; i <= Input ; i++){
        if (SearchPrice==Toko[i].Harga){
            printf("Harga Ditemukan\n");
            b=1;
            q++;
        }
    }
    if(b==0){
        printf("Harga Tidak Ditemukan\n");
    }
}

int main(){
    system("cls");
    Inputan();
    int Inp;
    
    for (int i = 0; i <= p; i++){
        system("cls");
        Menu();
        printf("Pilih : ");
        scanf("%d", &Inp);
        if (Inp == 1){
            BelumUrut();
            system("pause");
            p++;
        }
        else if (Inp == 2){
            InsertionSortFruit(Toko,Input);
            display();
            system("pause");
            p++;
        }
        else if (Inp == 3){
            InsertionSortPrice(Toko,Input);
            display();
            system("pause");
            p++;
        }
        else if (Inp == 4){
            SequentialSearchFruit();
            system("pause");
            p++;
        }
        else if (Inp == 5){
            SequentialSearchPrice();
            system("pause");
            p++;
        }
        else if (Inp == 6){
            Author();
            exit(0);
            break;
        }
        
        else{
            printf("Masukan Data Yang Benar!!!\n");
            Ulang=getch();
            p++;
        }
        
    }
    
}
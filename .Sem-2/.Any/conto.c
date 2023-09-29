#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


#define MAX 2300
#define WIDTH 100
void gotoxy(int x, int y);
void sort();
COORD coord;

typedef struct Bank {
    char nama[50];
    char alamat[100];
    int saldo;
    int no_account;
    char jenis_kelamin[30];
    char pekerjaan[30];
    struct Bank* next;
} Bank;


void stuck(){
	puts("Loading...");
	Sleep(1800);
	system("cls");	
}

void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void loading(){
    long i;
	float progress = 0.0;
	int c  = 0, x=0, last_c=0;

	system("cls");
	system("color 72");

	double j;
	int u = 50,uu=41,uuu=50,lu=58,cc;

	char a[]={"|   Bank System Management   |\n"};
	for(i = 0;i < 46;i++){
		gotoxy(uu,0);printf("=");
		Sleep(60);
		uu++;
	}
	for(i=0;a[i];i++) { 
        gotoxy(u,1);printf("%c",a[i]);
        u++;
        Sleep(60);
	}
	for(i=0;a[i];i++) { 
        gotoxy(uuu,2);printf("%c",'-');
        uuu++;
        Sleep(60);
	}

	char b[]={"LOGIN BERHASIL"};
	for(i = 0;b[i];i++){
		gotoxy(lu,14);printf("%c",b[i]);
		Sleep(60);
		lu++;
	}
	gotoxy(12,28);fprintf(stderr, "%3d%% [", (int)progress);
	for (x = 0; x < c; x++){
		fprintf(stderr, "=");
	}
	for (x = c; x < WIDTH; x++){
		fprintf(stderr, " ");
	}
	fprintf(stderr, "]");
	for(i = 1; i < MAX+1; i++){
		progress = i*100.0/MAX;
		c = (int) progress;
		
		fprintf(stderr, "\n\033[F");
		gotoxy(12,28);fprintf(stderr, "%3d%%", (int)progress);
		fprintf(stderr, "\033[1C");
		fprintf(stderr, "\033[%dC=", last_c);
		for (x = last_c; x < c; x++){
		    fprintf(stderr, "=");
		}
		if(x<WIDTH){
		    fprintf(stderr, ">");
		}
		last_c = c;
	}
    Sleep(1000);
}


Bank* head = NULL;

int kosong(){
    Bank* ptr = head;
    
    if(ptr == NULL){
        return 1;
    }else{
        return 0;
    }
}

// Fungsi untuk menambah data
void create() {
    Bank* baru = (Bank*) malloc(sizeof(Bank));
    
    printf("Masukkan Nama           : ");
    scanf(" %[^\n]", baru->nama);
    printf("Masukkan Alamat         : ");
    scanf(" %[^\n]", baru->alamat);
    printf("Masukkan Saldo          : ");
    scanf("%d", &baru->saldo);
    printf("Masukkan Jenis Kelamin  : ");
    scanf(" %[^\n]", baru->jenis_kelamin);
    printf("Masukkan Pekerjaan      : ");
    scanf(" %[^\n]", baru->pekerjaan);
    baru->no_account = rand() + 672022132;
    baru->next = NULL;
    if (head == NULL) {
        head = baru;
    } else {
        Bank* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = baru;
    }
    printf("\nData Berhasil Diinput\n");
    system("pause");
    sort();
}

// Fungsi untuk mencari data
void search() {
    char nama[50];

    if(kosong()){
        printf("Data Masih Kosong\n");
        system("pause");
    }else{
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", nama);
    Bank* ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->nama, nama) == 0) {
            printf("\nData %s ditemukan\n\n", ptr->nama);
            printf("Masukkan No Account     : %d\n",ptr->no_account);
            printf("Nama                    : %s\n", ptr->nama);
            printf("Alamat                  : %s\n", ptr->alamat);
            printf("Saldo                   : %d\n", ptr->saldo);
            printf("Masukkan Jenis Kelamin  : %s\n",ptr->jenis_kelamin);
            printf("Masukkan Pekerjaan      : %s\n",ptr->pekerjaan);
            getch();
            return;
        }
        ptr = ptr->next;
    }
    printf("\nData tidak ditemukan\n");
    system("pause");
    }
}

// Fungsi untuk mengupdate data
void update() {
    char nama[50];

    if(kosong()){
        printf("Data Masih Kosong\n");
        system("pause");
    }else{
    printf("Masukkan Nama: ");
    scanf("%s", nama);
    Bank* ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->nama, nama) == 0) {
            printf("\nData %s ditemukan\n\nUpdate Data Baru\n", ptr->nama);
            printf("Masukkan Alamat Baru: ");     scanf(" %[^\n]", ptr->alamat);
            printf("Masukkan Saldo Baru: ");      scanf("%d", &ptr->saldo);
            printf("Masukkan Jenis Kelamin  : "); scanf(" %[^\n]", &ptr->jenis_kelamin);
            printf("Masukkan Pekerjaan      : "); scanf(" %[^\n]", &ptr->pekerjaan);
            printf("\nData berhasil diupdate\n");
            getch();
            return;
        }
        ptr = ptr->next;
    }
    printf("\nData tidak ditemukan\n");
    system("pause");
    }
}

// Fungsi untuk menghapus data
void delete() {
    char nama[50];

    if(kosong()){
        printf("Data Masih Kosong\n");
        system("pause");
    }else{
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", nama);
    Bank* ptr = head;
    Bank* prev = NULL;
    while (ptr != NULL) {
        if (strcmp(ptr->nama, nama) == 0) {
            if (prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("\nData berhasil dihapus\n");
    
            system("pause");
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("\nData tidak ditemukan\n");
    system("pause");
    }
}

void sort() {
	Bank *temp1, *temp2;
	int swapped=  1;
	while (swapped) {
    Bank* ptr = head;
    Bank* previous = NULL;
        swapped = 0;
        while (ptr != NULL && ptr->next != NULL) {
            if (strcmpi(ptr->nama,ptr->next->nama)>0) {
                if (previous != NULL) {
                    previous->next = ptr->next;
                } else {
                    head = ptr->next;
                }
                Bank* temp = ptr->next->next;
                ptr->next->next = ptr;
                ptr->next = temp;
                previous = ptr->next;
                swapped = 1;
            } else {
                previous = ptr;
                ptr = ptr->next;
            }
        }
    }
}

// Fungsi untuk menampilkan semua data
void display() {
    Bank* ptr = head;

    if(kosong()){
        printf("Data Masih Kosong\n");
        system("pause");
    }else{
    while (ptr != NULL) {
        printf("No Account     : %d\n",ptr->no_account);
        printf("Nama           : %s\n", ptr->nama);
        printf("Alamat         : %s\n", ptr->alamat);
        printf("Saldo          : %d\n", ptr->saldo);
        printf("Jenis Kelamin  : %s\n",ptr->jenis_kelamin);
        printf("Pekerjaan      : %s\n\n",ptr->pekerjaan);
        ptr = ptr->next;
    }
    system("pause");
    }
}

// Fungsi untuk menyimpan data ke dalam file
void save() {
    int i;
    FILE* file = fopen("data_bank.txt", "w");
    Bank* ptr = head;
        for (i = 0; i < 128; i++)
        fprintf(file, "=");
        fprintf(file,"\n");
        fprintf(file, "%c %-6s%c %-34s%c %-17s%c %-16s%c %-20s%c %-17s| %c",
                '|', "No. Account", '|', "Nama", '|', "Alamat", '|', "Saldo",
                '|', "Jenis Kelamin", '|', "Pekerjaaan", '|');
        for (i = 0; i < 127; i++)
        fprintf(file, "=");
    while (ptr != NULL) {
        fprintf(file,"\n");
        fprintf(file,
                "%c %-11d%c %-34s%c %-17s%c %-16d%c %-20s%c %-17s| ",
                '|', ptr->no_account, '|', ptr->nama, '|', ptr->alamat, '|', ptr->saldo,
                '|', ptr->jenis_kelamin, '|', ptr->pekerjaan);
    for (i = 0; i < 128; i++)
    fprintf(file, "=");
    	ptr = ptr->next;
	}
	fclose(file);
	printf("\nData berhasil disimpan ke dalam file\n");
    system("pause");
}

// Fungsi untuk membaca data dari file
void load() {
    int i;
    if(kosong()){
        printf("Data Masih Kosong\n");

        system("pause");
    }else{
	FILE* file = fopen("data_bank.txt", "r");
	if (file == NULL) {
		printf("File tidak ditemukan\n");
		return;
	}
	system("data_bank.txt");
	printf("Data berhasil dibaca dari file\n");
    system("pause");
    }
}

// Fungsi untuk login
// int login() {
// 	char username[50], password[50];
//     while(1){
//     system("cls");
// 	printf("Masukkan Username: ");
// 	scanf("%s", username);
// 	printf("Masukkan Password: ");
// 	scanf("%s", password);
// 	if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
// 		return 1;
// 	} else {
// 		printf("Username atau Password salah\n");
//         getch();
// 	}
//     }
// }


int login(){
    char username[MAX], password[MAX];
    int a = 0;
    for (int j = 0; j <= a; j++){
    system("cls");
        printf("Masukkan username: ");
        scanf("%s", username);
        printf("Masukkan password: ");
        fflush(stdin);

        char ch;
        int i = 0;
        
        while(1){
            ch = getch();
            if(ch == 13){
                password[i] = '\0';
                break;
            }
            else if(ch == 8){
                if(i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else{
                password[i] = ch;
                i++;
                printf("*");
            }
        }

        printf("\n");

        if(strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0){
            printf("Login berhasil!\n");
        return 1;
        }
        else{
            printf("Login gagal!\n");
            a++;
            system("pause");
        }
    }
}

int main() {
   
	if (!login()) {
		return 0;
	}
    //loading();
	int pilihan;
	while (1) {
        system("cls");
		printf("Menu:\n");
		printf("1. Tambah Data\n");
		printf("2. Cari Data\n");
		printf("3. Update Data\n");
		printf("4. Hapus Data\n");
		printf("5. Tampilkan Data\n");
		printf("6. Simpan ke File\n");
		printf("7. Baca dari File\n");
		printf("8. Keluar\n");
		printf("Pilih: ");
		scanf("%d", &pilihan);
		switch (pilihan) {
			case 1:
				create();
				break;
			case 2:
				search();
				break;
			case 3:
				update();
				break;
			case 4:
				delete();
				break;
			case 5:
                sort();
				display();
				break;
			case 6:
				save();
				break;
			case 7:
				load();
				break;
			case 8:
				return 0;
			default:
				printf("Pilihan tidak tersedia\n");
		}
		printf("\n");
	}
	return 0;
}
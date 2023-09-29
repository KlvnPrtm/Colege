#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>


#define MAX 2300
#define WIDTH 100
void gotoxy(int x, int y);
void sort();
COORD coord;
int tries = 1;

typedef struct Bank {
    char nama[50];
    char alamat[100];
    int saldo;
    int no_account;
    char jenis_kelamin[30];
    char pekerjaan[30];
    struct Bank* next;
} Bank;

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

void head_display(){
    system("cls");
    gotoxy(45,1);printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Bank Management \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3\n\n");
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
    system("color 2");
    printf("\nData Berhasil Diinput");
    getch();
    sort();
}

// Fungsi untuk mencari data
void search() {
    char nama[50];

    if(kosong()){
        system("cls && color 4");
        printf("Data Masih Kosong\n");
        getch();
    }else{
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", nama);
    Bank* ptr = head;
    while (ptr != NULL) {
        if (strcmpi(ptr->nama, nama) == 0) {
            system("color 2");
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
    system("color 4");
    printf("\nData tidak ditemukan\n");
    getch();
    }
}

// Fungsi untuk mengupdate data
void update() {
    char nama[50];

    if(kosong()){
        system("cls && color 4");
        printf("Data Masih Kosong\n");
        getch();
    }else{
    printf("Masukkan Nama: ");
    scanf("%s", nama);
    Bank* ptr = head;
    while (ptr != NULL) {
        if (strcmpi(ptr->nama, nama) == 0) {
            printf("\nData %s ditemukan\n\nUpdate Data Baru\n", ptr->nama);
            printf("Masukkan Alamat Baru: ");     scanf(" %[^\n]", ptr->alamat);
            printf("Masukkan Saldo Baru: ");      scanf("%d", &ptr->saldo);
            printf("Masukkan Jenis Kelamin  : "); scanf(" %[^\n]", &ptr->jenis_kelamin);
            printf("Masukkan Pekerjaan      : "); scanf(" %[^\n]", &ptr->pekerjaan);
            system("color 2");
            printf("\nData berhasil diupdate\n");
            getch();
            return;
        }
        ptr = ptr->next;
    }
    system("color 4");
    printf("\nData tidak ditemukan\n");
    getch();
    }
}

// Fungsi untuk menghapus data
void delete() {
    char nama[50];

    if(kosong()){
        system("cls && color 4");
        printf("Data Masih Kosong\n");
        getch();
    }else{
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", nama);
    Bank* ptr = head;
    Bank* prev = NULL;
    while (ptr != NULL) {
        if (strcmpi(ptr->nama, nama) == 0) {
            if (prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            system("color 2");
            printf("\nData berhasil dihapus\n");
            getch();
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    system("color 4");
    printf("\nData tidak ditemukan\n");
    getch();
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
        system("cls && color 4");
        printf("Data Masih Kosong\n");
        getch();
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
    getch();
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
}

// Fungsi untuk membaca data dari file
void load() {
    int i;
    if(kosong()){
        system("cls && color 4");
        printf("Data Masih Kosong\n");
        getch();
    }else{
	FILE* file = fopen("data_bank.txt", "r");
	if (file == NULL) {
		printf("File tidak ditemukan\n");
		return;
	}

	system("data_bank.txt");
    system("cls && color 2");
	printf("Data berhasil dibaca dari file\n");
    getch();
    }
}

// Fungsi untuk login

    // fungsi untuk login
int login() {
    char username[32];
    char password[32];
    int attempts = 0;
    int a = 0;
    int kolom = 57;
    int space = 27;

    while (attempts < 3) {
        system("cls");
        for (int i = 0; i < kolom; i++) { //atas
        // Atas
        gotoxy(space + i, 2);
        printf("=");
        // Bawah
        gotoxy(kolom + space - i, 12);
        printf("=");
        Sleep(30);
        }
        for (int i = 0; i < 9; i++) { //samping
        gotoxy(kolom + space, 3 + i);
        printf("|");
        gotoxy(space, 11 - i);
        printf("|");
        Sleep(30);
        }
        
    
        gotoxy(space + 3, 5);
        printf("Enter username: ");
        scanf("%s", username);
        
        gotoxy(space + 3, 6);
        printf("Enter password: ");
        
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
        if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        return 1;
        }
        
        gotoxy(space + 3, 8);
        printf("Incorrect username or password.\n");
        ++attempts;

        if (attempts < 3) {
        gotoxy(space + 3, 9);
        printf("You have %d attempts left.\n", 3 - attempts);
        Sleep(1500);
        system("cls");
        } else {
        int lama = pow(2,tries)*5;
        gotoxy(space + 3, 13);
        printf("Too many attempts. Login blocked for %d seconds.\n", lama);
        sleep(lama);
        tries++;
        system("cls");
        login();
        }
    }
}
const char spasi[]={"                                                   "};


int main() {

	/*if (!login()) {
		return 0;
	}
    loading();*/
	int pilihan,i;
	char a[100] = {"Terima Kasih Buat Kalian Semua//////////"};

	while (1) {
        system("cls && color 76");
        head_display();
		printf("%sMenu:\n",spasi);
		printf("%s1. Tambah Data\n",spasi);
		printf("%s2. Cari Data\n",spasi);
		printf("%s3. Update Data\n",spasi);
		printf("%s4. Hapus Data\n",spasi);
		printf("%s5. Tampilkan Data\n",spasi);
		printf("%s6. Baca dari File\n",spasi);
		printf("%s7. Keluar\n",spasi);
		printf("%sPilih: ",spasi);
		scanf("%d", &pilihan);
		switch (pilihan) {
			case 1:
            system("cls");
            head_display();
				create();
				break;
			case 2:
            system("cls");
            head_display();
				search();
				break;
			case 3:
            system("cls");
            head_display();
				update();
				break;
			case 4:
            system("cls");
            head_display();
				delete();
				break;
			case 5:
            system("cls");
            head_display();
                sort();
				display();
				break;
			case 6:
				save();
                load();
				break;
			case 7:
            system("cls");
            gotoxy(50,15);for(i = 0; a[i];i++){
                printf("%c",a[i]);
                Sleep(90);
            }
            Sleep(2000);
            getch();
            	exit (0);
			default:
				printf("%sPilihan tidak tersedia!!!!\n",spasi);
                getch();
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
// NIM =1 Password =2


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

void Login(){
    system("cls");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X         ! ! ! LOGIN ! ! !         X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n");
}

void TampilanAwal(){
    char nim[12];
    char pass[12];
    int j=0;
    int f=0;
    while (f<=j)
    {
        Login();
        printf("Masukan NIM : ");
        scanf("%s", &nim);
        printf("Masukan Password : ");
        scanf("%s", &pass);
        
        if (strcmp(nim, "1") == 0){
            if (strcmp(pass, "2") == 0){
                printf("Login Berhasil, Selamat Datang Kelvin ! ! !");
                Ulang=getch();
                system ("cls");
            }else{
                printf("\nNim atau Password Salah");
                j++;
                Ulang=getch();
                system ("cls");
            }
        }else{
            printf("\nNIM atau Password Salah");
            j++;
            Ulang=getch();
            system ("cls");
        }
        f++;  
    }
    
}

void DaftarMatkul(){
    system("cls");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X  ! ! DAFTAR MATA KULIAH AiTi ! !  X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n\n");
    printf("TC111A\t\t PTI\t\t Agung Wibowo\n");
    printf("TC113D\t\t MATDIS\t\t Yessica Nataliani\n");
    printf("TC112I\t\t DDP\t\t Evangs Mailoa\n");
    printf("TC121B\t\t TBA\t\t Ineke A. Pakereng\n");
    printf("TC122C\t\t ASD\t\t Ramos Somya\n");
    printf("TC211D\t\t ALM\t\t Eryka Pandu Ekalia D\n");
    printf("TC212F\t\t PBO\t\t Yeremia Alfa Susetya\n");
    printf("TC214G\t\t SBD\t\t Hindriyanto D. Purnomo\n");
    printf("TC222A\t\t Etprof\t\t Roland T. Pallar\n");
    printf("TC223E\t\t PemrogWeb\t Christine Dewi\n");
    Ulang1();
}

void Menu(){
    system("cls");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X    ! ! ! SISTEM AKADEMIK ! ! !    X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n");
    printf("1. Data Matkul\n");
    printf("2. Pilih Matkul\n");
    printf("3. Cetak KST\n");
    printf("4. Exit\n");
}

void Matkul1(){
    system("cls");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X     ! ! PILIH MATA KULIAH  ! !    X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n\n");
    printf("Pilih 5 dari 10 Matkul yang terdapat pada menu Daftar Mata Kuliah AiTi ! !\nNOTE* MASUKKAN KODE MATKUL !\n\n");
}

void PreviewKST(){
    system("cls");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X      ! ! ! PREVIEW KST ! ! !      X X X X\n");
    printf("X X X X                                   X X X X\n");
    printf("X X X X X X X X X X X X X X X X X X X X X X X X X\n");
    printf("\nNIM\t: 672022302");
    printf("\nNama\t: Kelvin Halim Pratama\n");
    printf("\nData Mata Kuliah : \n");
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
			Sleep(100);
		}
	}
	gotoxy(45,10);
	for(i=0;i<panjangNama;i++){
		for(j=0;j<1;j++){
			printf("%c", a[i]);
			Sleep(100);
		}
	}
	gotoxy(42,12);
	for(i=0;i<panjangNama1;i++){
		for(j=0;j<1;j++){
			printf("%c", b[i]);
			Sleep(100);
		}
	}
	gotoxy(52,12);
	for(i=0;i<panjangNama2;i++){
		for(j=0;j<1;j++){
			printf("%c", c[i]);
			Sleep(100);
		}
	}
}

char Pilih[50][150];

void PilihMatkul(){
    char Kodematkul[10][10]={"TC111A","TC113D","TC112I","TC121B","TC122C","TC211D","TC212F","TC214G","TC222A","TC223E"};
    char *Matkul[]={"PTI","MATDIS","DDP","TBA","ASD","ALM","PBO","SBD","Etprof","PemrogWeb"};
    char *Dosen[]={"Agung Wibowo","Yessica Nataliani","Evangs Mailoa","Ineke A. Pakereng","Ramos Somya","Erika Pandu Ekalia D","Yeremia Alfa Susetya","Hindriyanto D. Purnomo","Roland T. Pallar","Christine Dewi"};
    char Lengkap[50][150]={"TC111A\t\tPTI\t\t Agung Wibowo", "TC113D\t\tMATDIS\t\t Yessica Nataliani", "TC112I\t\tDDP\t\t Evangs Mailoa", "TC121B\t\tTBA\t\t Ineke A. Pakereng", "TC122C\t\tASD\t\t Ramos Somya", "TC211D\t\tALM\t\t Eryka Pandu Ekalia D", "TC212F\t\tPBO\t\t Yeremia Alfa Susetya", "TC214G\t\tSBD\t\t Hindriyanto D. Purnomo", "TC222A\t\tEtprof\t\t Roland T. Pallar", "TC223E\t\tPemrogWeb\t Christine Dewi"};
    char input[50];
    int Pilihan[50]={0};
    int Total=0;
    Matkul1();
    int i=0;
    do{
        printf("%s\t\t%s\t\t%s\n",Kodematkul[i],Matkul[i],Dosen[i]);
        i++;
    }while (i<=8);
    if (i==9){
        printf("%s\t\t%s\t%s\n",Kodematkul[i],Matkul[i],Dosen[i]);
    }

    for (int i = 0; i <5; i++){
        int Benar=0;
        printf("\nPilih Matkul ke-%d : ",i+1);
        scanf("%s",&input);
        for (int j = 0; j < 10; j++){
            if(strncmp(input, Lengkap[j],6)==0 && Pilihan[j]==0){
                Benar=1;
                Pilihan[j]=1;
                strcpy(Pilih[Total],Lengkap[j]);
                Total++;
                break;
            }
        }
        if (Benar)
        {
            printf("\nBerhasil Mengambil Matakuliah %s\n",input);
        }else{
            printf("\nGagal/Sudah Terambil, Ulangi ! ! !\n");
            i--;
        }
    }
}

void CetakKST(){
    PreviewKST();
    char input1[10];
    for (int i = 0; i < 10; i++){
        if (i>4)
        {
            break;
        }else
        {
            printf("%s\n",Pilih[i]);
        }
    }
    Ulang1();
}




int main(){
    int PilihMenu;
    int p;
    TampilanAwal();
    for (int i=0;i<=p;i++){
        Menu();
        printf("Masukan Pilihan : ");
        scanf("%d",&PilihMenu);
        if (PilihMenu == 1){
            DaftarMatkul();
        }
        if (PilihMenu == 2){
            PilihMatkul();
        }
        if (PilihMenu == 3){
            CetakKST();
        }
        if (PilihMenu == 4){
            Author();
            exit(0);
            break;
        }
        if (PilihMenu<=0||PilihMenu>=5){
            printf("Masukan Sesuai Yang Diinginkan ! ! !\n");
            Ulang=getch();
        }
        p++;
    }
    return 0;
}

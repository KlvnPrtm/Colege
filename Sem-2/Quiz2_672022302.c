#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <windows.h>
#define KIW 30

char NamaBelakang[KIW];

void Nama (){
  char NamaDepan[KIW];
  char NamaLengkap[KIW];
  printf("1. Buat 2 buah String (nama_depan dan nama_belakang) kemudian gabungkan kedua String tersebut\n");
  printf("Nama Depan : ");
  scanf("%s", &NamaDepan);
  printf("Nama Belakang : ");
  scanf("%s", &NamaBelakang);

  strcpy(NamaLengkap,NamaDepan);
  strcat(NamaLengkap,NamaBelakang);

  printf("Nama Lengkap : %s\n\n",NamaLengkap);
}
char NamaUksw[KIW];
char *Tampilkan;

void UKSW(){
  int Panjang;
  Panjang=strlen(NamaUksw);
  printf("2. Buat sebuah String yang menampung nama lengkap UKSW, kemudian carilah panjang String tersebut\n");

  printf("Kepanjangan UKSW : ");
  scanf(" %[^\n]s",&NamaUksw);
  printf("Panjang String '%s' : Adalah %d",NamaUksw,strlen(NamaUksw));
  Tampilkan=(strchr(NamaUksw,'K'));

  printf("\n\n3. Tampilkan isi String UKSW Mulai Dari 'K' Dst\n: : %s\n\n",Tampilkan);
}

void Idola(){
  char Idola[KIW];
  printf("4. Ubahlah String Nama Belakang di Soal No.1 Menjadi Nama Tokoh Idola Anda");
  printf("\nNama Tokoh Idola Anda : ");
  scanf(" %[^\n]s",&Idola);
  printf("Nama Belakang Sebelum Diubah : %s",NamaBelakang);

  strcpy(NamaBelakang,Idola);
  printf("\nNama Belakang Setelah Diubah : %s\n\n",NamaBelakang);


}

void Cita2(){
  char Jurusan[KIW];
  char Fakultas[KIW];
  char PT[KIW];
  char Kota[KIW];

  char Jurusan1[KIW];
  char Fakultas1[KIW];
  char PT1[KIW];
  char Kota1[KIW];
  printf("5. Isikan Jurusan, Fakultas, PT, serta Kota yang Anda Impikan\n");


  printf("Jurusan\t: ");
  scanf(" %[^\n]s",&Jurusan);
  printf("Fakultas: ");
  scanf(" %[^\n]s",&Fakultas);
  printf("PT\t: ");
  scanf(" %[^\n]s",&PT);
  printf("Kota\t: ");
  scanf(" %[^\n]s",&Kota);

  strcat(PT,Kota);
  strcat(Fakultas,PT);
  strcat(Jurusan,Fakultas);


  printf("\n\nBerikut Data Pilihan Anda\t: %s", Jurusan);

}

    void hh(){
    char Username[KIW];
    char pass[KIW];
    int a=0;

    for(int i=0; i<=a; i++){
        printf("Username: ");
        scanf(" %[^\n]s", &Username);
        printf("Password: ");
        fflush(stdin);

        char c;
        int b=0;

        while((c = (char) _getch()) != '\r'){
            if(c == '\b'){
                    if(b>0){
                        pass[b]=c;
                        printf("\b \b");
                        b--;
                    }
            }
            else{
                pass[b]=c;
                printf("*", c);
               b++;
            }
        }
        printf("\n");

        if((strcmp(Username ,"25")==0) && (strcmp(pass,"100")==0)){
            printf("Login Berhasjl!\n\n");
            system("pause");
            system("cls");
        }
        else{
            printf("Ngawur\n\n");
            a++;
            system("pause");
            system("cls");
        }
    }
    system("cls");
}


int u=0;
void Ulang(){
    int a=0;
    char Ulang1;
        for(int i=0; i<=a; i++){
            printf("Apakah anda ingin mengulangi pemrogaman ini?(y/n) ");
            scanf(" %c", &Ulang1);

            if((Ulang1=='y') || Ulang1=='Y'){
                printf("\n");
                u++;
                system("pause");
                system("cls");
            }
            else if((Ulang1=='n') || Ulang1=='N'){
                system("cls");
                printf("XIE XIE!\n\n");
                system("pause");
                exit(0);
            }
            else{
                printf("Input salah, mohon diulangi!\n\n");
                a++;
                system("pause");
                system("cls");
            }
    }
}

int main(){
        hh();
    for (int i=0; i<=u; i++){
        Nama();
        UKSW();
        Idola();
        Cita2();
        printf("\n\n");
        Ulang();
    }

  return 0;
}

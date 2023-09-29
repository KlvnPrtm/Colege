#include <stdio.h>
#include <conio.h>
#include <windows.h>

int pilihan;
int jumlahData;
int input;
int i, j, k, l, x, y;
float waktuDetik;
float waktuJam;
float kecepatan;
float jarak;
float sum;
char listNama[50][50];
int listNilai[30];

void printMenu(){
	system("cls");
	printf("======================\n");
	printf("         MENU         \n");
	printf("======================\n");
	printf("1. Menghitung Jarak\n");
	printf("2. Data Nilai\n");
	printf("3. Belah Ketupat\n");
	printf("4. Author\n");
	printf("5. Exit\n");
}

void printMenuData(){
	system("cls");
	printf("==============\n");
	printf("  DATA NILAI  \n");
	printf("==============\n");
	printf("1. Input Data\n");
	printf("2. Lihat Data\n");
	printf("3. Rata-rata\n");
	printf("4. Kembali\n");
}

void printInputData(){
	system("cls");
	printf("==============\n");
	printf("  INPUT DATA  \n");
	printf("==============\n");
}

void printLihatData(){
	system("cls");
	printf("==============\n");
	printf("  LIHAT DATA  \n");
	printf("==============\n");
}

void printRatarata(){
	system("cls");
	printf("===============\n");
	printf("  RATA - RATA  \n");
	printf("===============\n");
}

void printAuthor(){
	system("cls");
	printf("=======================\n");
	printf("         AUTHOR         \n");
	printf("=======================\n");
	printf("1. Yosua Christian Prasetio\t672022102\n");
	printf("2. Marcellinus Brendan Hananta\t672022301\n");
	printf("3. Kelvin Halim Pratama\t\t672022302\n");
}

void printMenghitung(){
	printf("===========================\n");
	printf("     MENGHITUNG JARAK      \n");
	printf("===========================\n");
}

void printBelah(){
	system("cls");
	printf("========================\n");
	printf("    BELAH KETUPAT \n");
	printf("========================\n");
}

// int main(){
	while( isExit != 1){
	char key = 0;
	int isExit = 0;
		printMenu();
		printf("Masukan Pilihan : ");
		scanf("%d", &pilihan);
		int exit=0;
		switch(pilihan){
			case 1 :
				printMenghitung(); 
				while (!exit){
					printf("Masukkan Waktu Tempuh (detik) : ");
					scanf("%f", &waktuDetik);
					printf("Masukkan Kecepatan (km/jam) : ");
					scanf("%f", &kecepatan);
					waktuJam = waktuDetik/60/60;
					jarak = kecepatan*waktuJam;
					printf("\nJarak yang ditempuh : %f\n", jarak);
					printf("Apakah anda ingin mengulang? (y/t) : ");
					scanf(" %c", &input);
					if(input == 't'){
						exit = 1;
					}
				}
				break;
			case 2 :
				while (exit != 1){
					printf("Masukan Jumlah Data : ");
					scanf("%d", &jumlahData);
					int done = 0;
					while(!done){
						printMenuData();
						printf("Masukan Pilihan Anda : ");
						scanf("%d", &input);
						switch(input){
							case 1 :
								printInputData();
								for(i=1; i<=jumlahData; i++){
									printf("Masukan Data Ke-%d\n", i);
									printf("Masukan Nama : ");
									scanf("%s", &listNama[i]);
									printf("Masukan Nilai : ");
									scanf("%d", &listNilai[i]);
									printf("---------------\n");
								}
								break;
							case 2 :
								printLihatData();
								for(i=1; i<=jumlahData; i++){
									printf("Data Ke-%d\n", i);
									printf("Nama  : %s\n", listNama[i]);
									printf("Nilai : %d\n", listNilai[i]);
									printf("----------------\n");
								}
								printf("Press Any Key to Go Back");
								getch();
								break;
							case 3 : 
								printRatarata();
								for(i=1; i<=jumlahData; i++){
									sum+=listNilai[i];
								}
								float hasil = sum / jumlahData;
								printf("Rata - rata : %f\n", hasil);
								printf("Press Any Key to Go Back");
								getch();
								break;
							case 4 :
								done = 1;
								exit = 1;
								break;
							default :
								printf("Hanya dapat memilih 1 - 4\n");
								getch();	
						}
						}		
					}
				break;		
			case 3 :
				while(!exit){
					printBelah();					
					printf("Masukan tinggi (1-5) : ");
					scanf(" %d", &input);
					if(input <= 5 && input >= 1){
						int j=input-1, num=1;
						for (int i=1; i<=input; i++){
        				int l = i%2;
        					for (int a=1; a<=j; a++){
            				printf("  ");
        					}
        				if (l == 1){
        					for (int k = 1;k<=num*2;k+=2){
            				printf (" %d",k);
        					}
    					}else{
        					for (int k = 2;k<=num*2;k+=2){
            				printf (" %d",k);
        					}
    					}
        				if(j > i){
            				j = j-1;
            				num = num+2;
        				}
        				else if(j < i){
            				j = j+1;
            				num = num-2;
        				}
       				printf("\n");
    				}
					}else {
						printf("Hanya dapat input 1 - 5\n");
					}
					printf("Apakah anda ingin mengulang? (y/t) : ");
					scanf(" %c", &key);
					if(key == 't'){
						exit = 1;
					}
					}	
				break;
			case 4 :
				exit = 0;
				while(!exit){
					printAuthor();
					printf("\nPress Esc to go back");
					key = getch();
					if( key == 27 ){
						exit = 1;
					}
				}
				break;
			case 5 :
				printf("TERIMA KASIH");
				isExit = 1;
				getch();
				break;		
			default :
				printf("Hanya Bisa Memilih 1 - 5\n");
				printf("Press any key to Continue");
				getch();
				// break;
				
		}
	}
// }

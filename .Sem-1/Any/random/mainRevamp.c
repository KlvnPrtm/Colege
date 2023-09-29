#include <stdio.h>
#include <windows.h>

int Nim[100];
int Nilai[30];
int n;
	
void printMenu(){
	printf("--------------------------------\n");
    printf("              MENU\n");
    printf("--------------------------------\n");
    printf("\t1. Menghitung Jarak\n");
    printf("\t2. Data Nilai\n");
    printf("\t3. Mencetak Belah Ketupat\n");
    printf("\t4. Author\n");
    printf("\t5. Exit\n");
}

void printMenuData(){
	system("cls");
	printf("---------------------------------\n");
    printf("           Data Nilai\n");
    printf("---------------------------------\n");
    printf("\t1. input data\n");
    printf("\t2. lihat data\n");
    printf("\t3. rata-rata\n");
    printf("\t4. Keluar\n");
}

void menghitungJarak(){
	float v, s, t;
	system("cls");
	printf("==============================\n");
    printf("  Menghitung Jarak Tempuh\n");
    printf("==============================\n");
    printf("Masukkan kecepatan (km/jam) : ");
    scanf("%f", &v);
    printf("Masukkan waktu tempuh (jam) : ");
    scanf("%f", &t);
    s = v * t;
    printf("Jarak(km)           :  %0.2f\n", s);
}

void inputData(){
	system("cls");
	printf("=======================\n");
	printf("        Input Data\n");
	printf("=======================\n");
	int i;
	printf("input jumlah data : ");
    scanf("%d", &n);
	for (i = 1; i <= n; i++) {											       
        printf("Data ke-%d\n", i);
        printf("NIM : ", i);
        scanf("%d", &Nim[i]);
        printf("Nilai : ", i);
        scanf("%d", &Nilai[i]);
        printf("====================\n");
    }
	printf("Data Telah Tersimpan...\n");
	printf("Press Any Key to Continue");
	getch();
}

void lihatData(){
	system("cls");
	int i;
	printf("=======================\n");
    printf("      Lihat Data : \n");
    printf("=======================\n");
    for (i = 1; i <= n; i++) {
        printf("Data ke-%d : \n", i);
        printf("Nim : %d\n", Nim[i]);
        printf("Nilai : %d\n", Nilai[i]);
        printf("===================\n");
    }
    printf("Press Any Key to Continue");
    getch();
}

void printRatarata(){
	system("cls");
	printf("=======================\n");
	printf("       RATA - RATA\n");
	printf("=======================\n");
	int i;
	float sum;
	for( i=1; i<=n; i++){
		sum+=Nilai[i];
	}
	float hasil = sum / n;
	printf("Rata - rata : %.2f\n", hasil);
	printf("Press Any Key to Go Back");
	getch();
}

void belahKetupat(){
	int i, j;
	int jsp;
	int bentuk;
	system("cls");
	printf("==============================\n");
	printf("   Mencetak Belah Ketupat\n");
	printf("==============================\n");
    printf("Masukkan tinggi belah ketupat (1-5): ");
    scanf("%d", &bentuk);
    if (bentuk >= 1 && bentuk <=5 ) {
        int jumlahSpasi = bentuk;
        for ( i = 1; i <= bentuk; i++) {
            int angka = 1;
            if (i <= bentuk / 2) {
                for ( jsp = jumlahSpasi; jsp > 1; jsp--) {
                    printf(" ");
                }
                for ( j = 1; j < i * 2; j++) {
                    if (i % 2 == 1) {
                        printf("%d ", angka);
                        angka += 2;
                    } else {
                        printf("%d ", j * 2);
                    }
                }
                if (jumlahSpasi > 2) {
                    jumlahSpasi -= 2;
                }
            } else {
                for (jsp = 1; jsp < jumlahSpasi; jsp++) {
                    printf(" ");
                }

                for (j = 1; j < ((bentuk + 1) - i) * 2; j++) {
                    if (i % 2 == 1) {
                        printf("%d ", angka);
                        angka += 2;
                    } else {
                        printf("%d ", j * 2);
                    }
                }
                jumlahSpasi += 2;
            }
            printf("\n");
        }
    } else {
        printf("Hanya Dapat Input 1 - 5\n");
        printf("Press Any Key to Continue");
        getch();
    }
}

void printAuthor(){
	system("cls");
	printf("====================================\n");
	printf("              Author\n");
    printf("====================================\n");
    printf("Nadya Salsabilla Mustafa (672022188)\n");
    printf("Dinda Ayu Ramadhani (672022285)\n");
    printf("Lintang Satrio Gutomo (672022286)\n");
    printf("Press Any Key to Go Back");
    getch();
}

main(){
	int input;
	int isDone = 0;
	int isExit = 0;
	do {
		isExit = 0;
		system("cls");
		printMenu();
		printf("Masukan Angka : ");
		scanf("%d", &input);
		if ( input == 1){
			while(!isExit){
				menghitungJarak();
				printf("Apakah Ingin Mengulang? [Y/T] : ");
				scanf(" %c", &input);
				if( input == 't'){
					isExit = 1;
				}
			}
		}else if ( input == 2 ){
			while(!isExit){
				printMenuData();
				printf("Masukan pilihan anda : ");
				scanf("%d", &input);
				switch(input){								
					case 1:
                        inputData();
                        break;
                    case 2:
                    	lihatData();
                    	break;
                    case 3:
                    	printRatarata();
                    	break;
                    case 4:
                    	isExit = 1;
                    	break;
                    default:
                    	printf("Menu Tidak Ada\n");
                    	printf("Press Any Key to Continue");
                    	getch();
				}
			}	
		}else if( input == 3 ){
			while(!isExit){
				belahKetupat();
				printf("Apakah Ingin Mengulang? [Y/T] : ");
				scanf(" %c", &input);
				if( input == 't'){
					isExit = 1;
				}
			}
		}else if( input == 4){
			while(!isExit){
				printAuthor();
	            isExit = 1;
	            
			}
		}else if( input == 5){
			printf("Closing Program");
			isDone = 1;
		}else {
			printf("Menu Tidak Ada\n");
			printf("Press Any Key to Continue");
			getch();
		}
	}while(!isDone);
}

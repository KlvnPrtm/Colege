#include <stdio.h>
#include <windows.h>

void SegitigaAngka(){
    int i=1;
    int j=1;
    int k;
    int l=0;
    int n;

    printf("Masukan Angka : ");
    scanf("%d",&n);

    for (i=1;i<=n;i++){
        for (j=n-1;j>=i;j--){
            printf("\t");
        }
        for(k=1;k<=(i+l)*2;k++){
        if ((i%2==1&&k%2==0)){
            printf("\t%d",k);
            }        
            else if (i%2==0&&k%2==1){
            printf("\t%d",k);
            }
        }
        l++;
        printf ("\n");
    }
    system("pause");
}

void Fpb(){
	int n1, n2; 
	int hasil;
    char Ulang;
    int p;

    for (int i = 0; i <= p; i++){
        system("cls");
        printf("FPB\n");
        
        printf("Masukan Bilangan Bulat Pertama = ");
        scanf("%d", &n1);
        printf("Masukan Bilangan Bulat Kedua = ");
        scanf("%d", &n2);
        for (int i = 1; i<=n1 && i<=n2; i++){
            if(n1 % i == 0 && n2 % i == 0){
                hasil = i;
            }
        }
        printf("\nBilangan Bulat Pertama Adalah  %d\n", n1);
        printf("Bilangan Bulat Kedua Adalah %d\n", n2);
        printf("FPB Dari %d Dan %d Adalah %d", n1, n2, hasil);
        Kiw:
        printf("\n\nIngin Mengulangi Program Ini?(y/n) ");
        scanf("%s", &Ulang);
        if (Ulang == 'y' || Ulang == 'Y'){
            Fpb();
        }else if (Ulang == 'n' || Ulang == 'N'){
            Menu();
        }else{
            printf("\nTidak ada Pilihan! Ulangi\n");
            system("pause");
            goto Kiw;
        }
        p++;
    }
}

void Menu(){
    int Pilihan;
    int p;
    for (int i = 0; i <= p; i++){
        system("cls");
        printf("1. Fpb\n");
        printf("2. Segitiga Angka\n");
        printf("3. Exit\n");
        printf("Masukan Pilihan: ");

        scanf("%d", &Pilihan);

        if (Pilihan == 1){
            Fpb();
        }else if (Pilihan == 2){
            SegitigaAngka();
        }else if (Pilihan == 3){
            exit(0);
        }else{
            system("cls");
            printf("Tidak ada pilihan! Ulangi\n");
            system("pause");
        }
        p++;
    }
}


int main(){
    Menu();
}
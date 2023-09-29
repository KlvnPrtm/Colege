#include<stdio.h>
#include<windows.h>
#include<conio.h>

int main(){
    int kodebarang;
    int kembalian;
    int jumlah;
    int a,uang;
    int total;
    // ,harga[11]={50000,65000,90000,110000,75000,700000,900000,67000,800000,60000}
    int harga;
    // int harga[11]={50000,65000,90000,110000,75000,700000,900000,67000,800000,60000};
    char ulang;
    do
    {
        system("cls");
    
    printf("--------------------------------------------------\n");
    printf("|       Daftar dan Harga Barang Toko FTI         |\n");
    printf("|------------------------------------------------|\n");
    printf("| ID    | Nama Barang            | Harga Barang  |\n");
    printf("|-------|------------------------|---------------|\n");
    printf("| 1.    | Flash Disk Toshiba 4 GB| Rp.  50000    |\n");
    printf("| 2.    | Flash Disk Toshiba 8 GB| Rp.  65000    |\n");
    printf("| 3.    | Flash disk toshiba 16GB| Rp.  90000    |\n");
    printf("| 4.    | Flash disk toshiba 32GB| Rp.  110000   |\n");
    printf("| 5.    | Flash disk sandisk 4 gb| Rp.  75000    |\n");
    printf("| 6.    | Hard Disk WD 500 GB    | Rp.  700000   |\n");
    printf("| 7.    | Hard Disk WD 1 TB      | Rp.  900000   |\n");
    printf("| 8.    | Hard Disk Dell 500 GB  | Rp.  670000   |\n");
    printf("| 9.    | Hard Disk Dell 1 TB    | Rp.  800000   |\n");
    printf("| 10.   | Tongsis                | Rp.  60000    |\n");
    printf("--------------------------------------------------\n\n\n");
    printf("Masukan Kode Belanjaan Anda : ");
    scanf("%d",&kodebarang);

    switch (kodebarang)
    { 
    case 1:
        printf("Item Anda : Flash Dish Toshiba 4 GB\n");
        harga=50000;
        break;
    case 2:
        printf("Item Anda : Flash Dish Toshiba 8 GB\n");
        harga=65000;
        break;
    case 3:
        printf("Item Anda : Flash Dish Toshiba 16 GB\n");
        harga=90000;
        break;
    case 4:
        printf("Item Anda : Flash Dish Toshiba 32 GB\n");
        harga=110000;
        break;
    case 5:
        printf("Item Anda : Flash Dish Sandisk 4 GB\n");
        harga=75000;
        break;
    case 6:
        printf("Item Anda : Hard Disk WD 500 GB\n");
        harga=700000;
        break;
    case 7:
        printf("Item Anda : Hard Disk WD 1 TB\n");
        harga=900000;
        break;
    case 8:
        printf("Item Anda : Hard Disk DELL 500 GB\n");
        harga=670000;
        break;
    case 9:
        printf("Item Anda : Hard Disk DELL 1 TB\n");
        harga=800000;
        break;
    case 10:
        printf("Item Anda : Tongsis\n");
        harga=60000;
        break;
    default:
        printf("Pilhan Tidak Tersedia\n");
        break;
    }
    // int ulang;
    printf("Jumlah Barang : ");
    scanf("%d",&jumlah);
    jumlah=jumlah*harga;
    printf("\nHarga : %d",jumlah);
    total=total+jumlah;
    printf("\nTotal Belanja : %d",total);
    
    printf("\nBeli Lagi?(Y/N) : ");
    scanf("%c",&ulang);
    
    ulang=getche();
    }while (ulang == 'Y'||ulang == 'y');
    printf("\nStruck Belanja");
    printf("\n--------------");
    printf("\nDaftar Barang : ",kodebarang);
    printf("\nJadi Total Yang Harus Dibayar Adalah : ",total);
    printf("\nUang Anda : ");
    scanf("%d",&uang);
    if (uang<total);
    {
    }
        kembalian=uang-total;
        printf("Kembalian anda : %d",kembalian);
    

}
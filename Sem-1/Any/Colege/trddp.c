#include<stdio.h>
#include<windows.h>

int main(){
    int kodebarang,jumlahpembelian,uang,kembalian;
    char ulang;
    int harga;
    awal:
    // do{
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
        // harga2=65000;
    case 4:
        printf("Item Anda : Flash Dish Toshiba 32 GB\n");
        harga=110000;
        break;
        // harga2=65000;
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
    int total;
    printf("Jumlah Pembelian Item : ");
    scanf("%d",&jumlahpembelian);
    
    printf("Beli Lagi? (y/n) : ");
    scanf("%c",&ulang);
    ulang=getche();
    if (ulang=='y' || ulang=='Y')
    {
        goto awal;
    }
    if(ulang=='n' || ulang=='N') {
    }
        total= jumlahpembelian*harga;
        printf("\nHarus Bayar : %d ", total);
    
    // }
    

    // printf("Jumlah Pembelian : %d",jumlahpembelian[100]);
}
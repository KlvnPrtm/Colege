#include<stdio.h>
#include<stdio.h>

int main(){
	
	int jumlahBarang, uangBelanja, kembalian;
	int total = 0;
	int harga[4]={50000,65000,700000,900000,60000};
	char id, conditional;
	
	
	printf("-------------------------------------------------\n");
	printf("|\tDaftar dan Harga Barang Toko FTI\t|\n");
	printf("-------------------------------------------------\n");
	printf("| ID  | Nama Barang \t\t|  Harga Barang |\n");
	printf("-------------------------------------------------\n");
	printf("| 1.  | Flash Disk Toshiba 4GB  | Rp. 50000     |\n");
	printf("| 2.  | Flash Disk Toshiba 8GB  | Rp. 65000     |\n");
	printf("| 3.  | Hard Disk Dell 500GB    | Rp. 700000    |\n");
	printf("| 4.  | Hard Disk Dell 1TB      | Rp. 900000    |\n");
	printf("| 5.  | Tongsis                 | Rp. 60000     |\n");
	printf("-------------------------------------------------\n");
	
	retry:
		
	printf("Masukkan Kode Belanjaan Anda : ");
	scanf("%c", &id);
	

	switch(id){
		
		case '1' :
			printf("Item Anda : Flash Disk Toshiba 4 GB\n");
			printf("Jumlah Pembelian Item : ");
			scanf("%d", &jumlahBarang);
			total += harga[0]*jumlahBarang;
			printf("Apakah Anda ingin membeli barang lainnya? (y/n)");
			scanf(" %c", &conditional);
			if(conditional == 'y'){
				goto retry;
			}else
				goto end;
			break;
		case '2' :
			printf("Item Anda : Flash Disk Toshiba 8 GB\n");
			printf("Jumlah Pembelian Item : ");
			scanf("%d", &jumlahBarang);
			total += harga[1]*jumlahBarang;
			printf("Apakah Anda ingin membeli barang lainnya? (y/n)");
			scanf(" %c", &conditional);
			if(conditional == 'y'){
				goto retry;
			}else
				goto end;
			break;
		case '3' :
			printf("Item Anda : Hard Disk Dell 500 GB\n");
			printf("Jumlah Pembelian Item : ");
			scanf("%d", &jumlahBarang);
			total += harga[2]*jumlahBarang;
			printf("Apakah Anda ingin membeli barang lainnya? (y/n)");
			scanf(" %c", &conditional);
			if(conditional == 'y'){
				goto retry;
			}else
				goto end;
			break;
		case '4' :
			printf("Item Anda : Hard Disk Dell 1 TB\n");
			printf("Jumlah Pembelian Item : ");
			scanf("%d", &jumlahBarang);
			total += harga[3]*jumlahBarang;
			printf("Apakah Anda ingin membeli barang lainnya? (y/n)");
			scanf(" %c", &conditional);
			if(conditional == 'y'){
				goto retry;
			}else
				goto end;
			break;
		case '5' :
			printf("Item Anda : Tongsis\n");
			printf("Jumlah Pembelian Item : ");
			scanf("%d", &jumlahBarang);
			total += harga[4]*jumlahBarang;
			printf("Apakah Anda ingin membeli barang lainnya? (y/n)");
			scanf(" %c", &conditional);
			if(conditional == 'y'){
				goto retry;
			}else
				goto end;
			break;
					
	}
	end:
		printf("Struck Belanja\n");
		printf("--------------\n");
		printf("Daftar barang: \n");
		printf("Total uang yang harus dibayar : Rp. %d\n", total);
		printf("Uang Anda : ");
		scanf("%d", &uangBelanja);
		if(uangBelanja<total){
			printf("Uang Anda Kurang!\n");
		}else
			kembalian : uangBelanja - total;
			printf("Kembalian : Rp. %d",kembalian);
}

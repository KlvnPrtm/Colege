#include <stdio.h>

int main(){

    char eja[50][150]={"Nol ","Satu ","Dua ","Tiga ","Empat ","Lima ","Enam ","Tujuh ","Delapan ","Sembilan "};
    int input;
	printf("Masukan Angka : ");
    scanf(" %d", &input);
    if(input / 1000 > 0){
    	printf("Seribu ");
    	input%=1000;
	}
	
	if( input / 100 > 0){
		if(input / 100 == 1){
			printf("Seratus ");
		}else{
			printf(eja[input/100]);
			printf("Ratus ");
		}
		input%=100;
	}
	if( input / 10 > 0){
		if(input / 10 == 1){
			if(input % 10 == 0){
				printf("Sepuluh ");
			}else if( input % 10 == 1){
				printf("Sebelas ");
			}else{
				printf(eja[input%10]);
				printf("Belas ");
			}
		}
        else{
		    printf(eja[input/10]);
		    printf("Puluh ");
	        if(input %10!=0){
		        printf(eja[input%10]);
	        }
		}
    }
    if(input<10){
        printf (eja[input%10]);
    }
}
#include <stdio.h>
#include <windows.h>

int main (){


    char nim[11]="672022302 ";
    
    char nama[22]="Kelvin Halim Pratama ";
    

    int i;
    int j;
    char tempn;
    char temph;
    while (1){

        system("cls");

        tempn=nim[0];
        for (i=0;i<11;i++){
            nim[i]=nim[i+1];
        }
        nim[10]=tempn;
        for(i=0;i<=10;i++){
            printf("%c",nim[i]);
        }
        printf("\n");


        temph=nama[20] ;
        for (i=20;i>0;i--){
        nama[i]=nama[i-1];
        }
        nama[0]=temph;
        for(i=0;i<=20;i++){
        printf("%c",nama[i]);
        }


        for (i=1;i<=60000;i++)
		for (j=1;j<=10000;j++);
    }
}

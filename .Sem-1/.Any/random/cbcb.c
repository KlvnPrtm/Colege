#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int x, y,j,i;
main(){
    char key=0;
    while(key != 27){
        if(kbhit()){
            key=getch();
        }
        system("cls");

        gotoxy(30,2);
        printf("------------------");
        gotoxy(37,3);
        printf("MENU");
        gotoxy(30,4);
        printf("------------------");
        gotoxy(33,5);
        printf("1.FPB\n");
        gotoxy(33,6);
        printf("2.KPK\n");
        gotoxy(33,7);
        printf("3.Keluar");
        gotoxy(30,8);
        printf("------------------");

        if(key == '1'){
            gotoxy(30,2);
            printf("------------------");
            gotoxy(37,3);
            printf("MENU");
            gotoxy(30,4);
            printf("------------------");
            gotoxy(29,5);
			printf("--> ");
            printf("1.FPB");
            gotoxy(33,6);
            printf("2.KPK");
            gotoxy(33,7);
            printf("3.Keluar");
            gotoxy(30,8);
            printf("------------------");
			if(key == 13){#include <stdio.h>
    int x,y,i,kpk=0,p=0;
    //printf("Mencari KPK (Kelipatan Persekutuan Terkecil)\n");
    printf("Masukkan bilangan bulat pertama : "); scanf("%d",&x);
    printf("Masukkan bilangan bulat kedua   : "); scanf("%d",&y);
    printf("\nBilangan Pertama = ");
    for(i=x;i<150;i+=x){
        printf("%d ",i);
    }
    printf("\nBilangan Kedua = ");
    for(i=y;i<150;i+=y){
        printf("%d ",i);
    }
    printf("\n");

        for(i=1;i<=y;i++){
        kpk=kpk+x;
            //x+=x;
            //y+=y;
            //printf ("%d, ",x);
            //printf ("%d, ",y);
        if(kpk%y==0){
            // printf ("Bilangan Pertama Adalah : ");
            // printf ("%d dan %d\n",y,kpk);
            // printf ("%d",kpk);

            printf("\nKelipatan Persekutuannya = %d\n",kpk);
            //break; //berhenti di hasil pertama
        }
        }
        
    for(i=1;i<=y;i++){
        p=p+x;
            //x+=x;
            //y+=y;
            //printf ("%d, ",x);
            //printf ("%d, ",y);
        if(p%y==0){
            // printf ("Bilangan Pertama Adalah : ");
            // printf ("%d dan %d\n",y,kpk);
            // printf ("%d",kpk);

            printf("\nKelipatan Persekutuan Terkecilnya adalah %d",p);
            printf("\nJadi KPK dari %d dan %d adalah %d",x,y,p);
            break; //berhenti di hasil pertama
        }
    }
    getch();
}
			}
			}if(key == '2'){
			gotoxy(30,2);
			printf("------------------");
			gotoxy(37,3);
			printf("MENU");
			gotoxy(30,4);
			printf("------------------");
			gotoxy(33,5);
			printf("1.FPB");
			gotoxy(29,6);
			printf("--> ");
			printf("2.KPK");
			gotoxy(33,7);
			printf("3.Keluar");
			gotoxy(30,8);
			printf("------------------");
			}if(key == '3'){
			gotoxy(30,2);
			printf("------------------");
			gotoxy(37,3);
			printf("MENU");
			gotoxy(30,4);
			printf("------------------");
			gotoxy(33,5);
			printf("1.FPB");
			gotoxy(33,6);
			printf("2.KPK");
			gotoxy(29,7);
			printf("--> ");
			gotoxy(33,7);
			printf("3.Keluar");
			gotoxy(30,8);
			printf("------------------");
			}
			for (i=1;i<=10000;i++)
					for (j=1;j<=10000;j++);
    }

}
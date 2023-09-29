#include <stdio.h>
#include <conio.h>
int main(){
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
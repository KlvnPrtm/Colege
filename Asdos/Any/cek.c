#include <stdio.h>

int main (){
int tinggi;
printf("input tinggi segitiga : ");
scanf("%d",&tinggi);

for (int q=1;q<=tinggi;q++){
    int s=q;

    for(int p=1;p<=tinggi-q;p++){
        printf("\t");
    }

    for (int r=1;r<=q*2-1;r++){
        printf("\t%d",s);
        int y=q-1;
        s+=y;
    }
  printf("\n");
}
}

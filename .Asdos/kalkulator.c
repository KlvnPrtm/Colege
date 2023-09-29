#include <stdio.h>

int main(){
    int x,y,n,z,p;

    printf("Masukan Bilangan Pertama: ");
    scanf("%d",&x);

    printf("Masukan Bilangan Kedua: ");
    scanf("%d",&y);

    for (int i = 0; i <= p; i++){
        printf("\nMasukan Operator (1.*,2./,3.+,4.-): ");
        scanf("%d",&n);

        switch (n){
        case 1:
            z=x*y;
            printf("%d * %d = %d" ,x,y,z);
            break;
        case 2:
            z=x/y;
            printf("%d / %d = %d" ,x,y,z);
            break;
        case 3:
            z=x+y;
            printf("%d + %d = %d" ,x,y,z);
            break;
        case 4:
            z=x-y;
            printf("%d - %d = %d" ,x,y,z);
            break;
        default:
            printf("Tidak Ada Operator");
            p++;
        }
    }
    return 0;
}
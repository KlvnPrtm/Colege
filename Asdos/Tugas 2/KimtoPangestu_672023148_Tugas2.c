#include <stdio.h>



float itungbmi(float tb, float bb) {
    float tingi = bb / 100;
    float bmi = tb / (tingi * tingi);
    return bmi;
}

void segitiga(int rorrr) {
    int i, j, spasi;
    spasi = rorrr - 1;

    for (i = 1; i <= rorrr; i++) {
        for (j = 1; j <= spasi; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
        spasi--;
    }
}

int main() {
    char lanjut;
    int menu;
    float tb, bb;

    do {
        printf("----------------------------------------------------------\n");
        printf("|\t      Welcome to Program.            |\n|  \t\t\t\t\t\t\t |\n|");
        printf("\t\t     Menu:                               |\n");
        printf("|\t \t1. Body Mass Caculating  \t\t\t\t |\n");
        printf("|\t \t2. Triangle  \t\t |\n");
        printf("|\t \t3. Exit  \t\t\t\t |\n");
        printf("|\t \tPlease Choose the Number:");
        // printf("\t\t\t\t|");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\t \tPlease Input your Weight to Make Sure (kg): ");
                scanf("\t \t%f", &tb);
                printf("\t \tPlease Input your Height to See your Body Mass (cm): ");
                scanf("\t \t%f", &bb);
                float bmi = itungbmi(tb, bb);
                printf("\t \tYour Body Mass (BMI): %.2f\n", bmi);
                 
    
                
                break;
            case 2:
                printf("|\t \tWhich Triangle Height that you want to Create: ");
                scanf("\t \t%f", &bb);
                segitiga(bb);
                break;
            case 3:
                printf("\t \tThank you to use these Program.\n");
                return 0;
            default:
                printf("\t \tAccess Denied, the Data that you choosing are not valid. please try again.\n");

        }
        printf("\n \t \tAre you sure you want to Continute?...");
        getch();
        system("cls");
        printf("\t \t Continute? (y/n): ");
        scanf(" %c", &lanjut);

    } while (lanjut == 'y' || lanjut == 'Y');

    printf("\t\tThank you for using this Program.\n");
    return 0;
}
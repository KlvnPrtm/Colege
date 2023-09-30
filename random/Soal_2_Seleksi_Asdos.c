#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
    printf("RUNNING TEXT\n\n");
    int i,j;
    int maxkolom=27,startbaris=1,tidur=50;
    char nama[21];
    char key=0,ch;
    int reverse = 0; // Flag to indicate if reverse mode is active

    // Initialize nama array
    strcpy(nama, "A_S_I_S_T_E_N_D_D_P  ");

    while (1) {
        system("cls");

        if (reverse) {
            char temp = nama[19];
            for (j = 19; j > 0; j--) {
                nama[j] = nama[j - 1];
            }
            nama[0] = temp;
        } else {
            char temp = nama[0];
            for (j = 0; j < 20; j++) {
                nama[j] = nama[j + 1];
            }
            nama[19] = temp;
        }

        for (i = 0; i < 20; i++) {
            printf("%c", nama[i]);
        }
        Sleep(50);

        if (kbhit()) {
            ch = getch();
            if ((int)ch == 13) {
                reverse = !reverse; // Toggle the reverse flag
            }
        }
    }
    return 0;
}
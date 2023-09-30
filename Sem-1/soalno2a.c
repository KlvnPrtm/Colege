#include <stdio.h>
#include <conio.h>
#include <windows.h>

int condition();
void gotoxy();


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main()
{
int dx = 1;
int dy = 1;
int x = 0;
int y = 0;
int num = 1;
int baris,kolom ;
    
    system("cls");

    for (baris = 5; baris >= 1; baris--){
        x += dx;
        for (kolom = 1; kolom <= baris; kolom++)
        {
            if (num == 10)
            {
                num = 1;
            }
            gotoxy(x, y);
            printf("%i", num);
            num++;
            if (kolom != baris)
            {
                x += dx;
            }
        }
        dx *= -1;
        y += dy;
        for (kolom = 1; kolom <= baris; kolom++)
        {
            if (num == 10)
            {
                num = 1;
            }
            gotoxy(x, y);
            printf("%i", num);
            num++;
            if (kolom != baris)
            {
                y += dy;
            }
        }
        dy *= -1;
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}
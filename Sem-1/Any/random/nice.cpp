#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int width = 50, height = 25;
int x = width /2, y = height /2;
enum snake{STOP = 1, UP, DOWN, LEFT, RIGHT};
snake snakeMove;
void randomFood(int &foodX, int&foodY){
    // generate random number (2-19)
    srand(time(NULL));
    while(1){
        foodX = rand() % width;
        foodY = rand() % height;
        if(foodX >= 2 && foodY>= 2) break;
    }
}
void rules_logic(int &foodX, int &foodY, int*tailX, int *tailY, int &tails, int &score, bool &gameOver){
    tailX[0] = x;
    tailY[0] = y;

    for(int i=tails; i>0; i--){
        tailX[i] = tailX[i-1];
        tailY[i] = tailY[i-1];
    }
    switch(snakeMove){
        case UP: y--; break;
        case DOWN: y++; break;
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case STOP: gameOver = true ; break;
    }
    if (x<=1) x = width; else if(x>=width) x = 1;
    if (y<=1) y = height; else if(y>=height) y = 1;

    if (x==foodX && y==foodY){
        score += 10;
        tails++;
        randomFood(foodX, foodY);
    }
}

void draw(int &foodX, int &foodY, int &tails, int *tailX, int *tailY, int &score){
    cout << "score: " << score << "\t";
    cout << "tails: " << tails << endl;
    for(int i=1; i<=height; i++){
        for(int j=1; j<=width; j++){

            if(i==1 || i==height || j==1 || j==width) cout << "#";

            else if(x==j && y==i) cout << "0";
            else if(foodX == j && foodY == i) cout << "@";
            else{
                bool printSpace = true;
                for(int k=tails; k>0; k--){
                    if(tailX[k]==j && tailY[k]==i){
                        printSpace = false;
                        cout << "o";
                    }
                }
                if(printSpace) cout << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int foodX, foodY;
    int score;
    int tails;
    int tailX[75], tailY[75];
    bool gameOver = false;
    randomFood(foodX, foodY);

    while(gameOver != true){
        system("cls");
        if(kbhit()){
            switch(getch()){
                case 'w': snakeMove = UP; break;
                case 's': snakeMove = DOWN; break;
                case 'a': snakeMove = LEFT; break;
                case 'd': snakeMove = RIGHT; break;
                default: break;
            }
        }
        rules_logic(foodX, foodY, tails, tailX, tailY, score, gameOver);
        draw(foodX, foodY, tails, tailX,  tailY, score);
    }

    return 0;
}
/*
	Author: Vikas Sinha
	SS Publications

*/

#include <stdio.h>
#include <windows.h>
#define V 21
#define H 75

// initianilizing
void playGame();
void gameRules();
void setColor(int ForgC);
void loop(char map[V][H], int jini, int jfinal, int iaini, int iafinal, int px, int py);
void edge(char map[V][H]);
void player(char map[V][H], int jini, int jfinal);
void cpu(char map[V][H], int iaini, int iafinal);
void ball(char map[V][H], int py, int px);


// main loop
void gameloop(char map[V][H], int jini, int jfinal, int iaini, int iafinal, int px, int py, int modx, int mody, int modia);
void draw(char map[V][H]);
void show(char map[V][H]);
void input(char map[V][H], int *jini, int *jfinal, int *iaini, int *iafinal, int *px, int *py, int *modx, int *mody, int *modia, int *gol);
void update(char map[V][H], int jini, int jfinal, int iaini, int iafinal, int py, int px);
void gotoxy(int x, int y);

int playerwin = 0; // ikr bad deal.
int iawin = 0;

int main()
{
    int choice;
	while (1)
	{
	setColor(43);
    intf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    setColor(44);
    intf("|                     Ping Pong Game                       |");
    setColor(43);
    intf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		intf("\n1. Game Rules");
		intf("\n2. Play Game");
		intf("\n3. Quit\n");
		scanf("%d",&choice);
		switch(choice)
		{
	
			case 1  : gameRules();
			break;
			
			case 2  : playGame();       
			break; 
			
			case 3  : exit(0);       
			break;
            
			default : intf("Invalid choice");
			          
		}
      }
      return 0;
    
}

void gameRules()
{
	setColor(43);
    intf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    setColor(44);
    intf("|                      Game Rules                          |");
 	setColor(43);
    intf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");   
    
    intf("\n\tPress -> W : Up Movement");
    intf("\n\tPress -> S : Down Movement\n");
}
void playGame()
{
 
	char map[V][H];
 
       
	// initialized map
	int jini, jfinal, iaini, iafinal, py, px;

	jini = 8;
	jfinal = 12;

	iaini = 8;
	iafinal = 12;

	py = 10;
	px = 37;

	// movement
	int modx = -1;
	int mody = -1;
	int modia = -1;

	loop(map, jini, jfinal, iaini, iafinal, px, py);
	gameloop(map, jini, jfinal, iaini, iafinal, px, py, modx, mody, modia);

	intf("\n \n");

	if (playerwin == 1)
	{
		setColor(44);
        intf("\n           ----------------------------------------------------\n");
		intf("           |            Congrant's. You Win                   |");
		intf("\n           ----------------------------------------------------\n");
	}

	if (iawin == 1)
	{   setColor(44);
        intf("\n           ----------------------------------------------------\n");
		intf("           |                  You Lose                        |");
		intf("\n           ----------------------------------------------------\n");
		setColor(45);
	    intf("\n\n                              Game Over                       \n\n");
	}
    setColor(43);
	system("pause");
	system("cls");

}

void loop(char map[V][H], int jini, int jfinal, int iaini, int iafinal, int py, int px)
{

	edge(map);
	player(map, jini, jfinal);
	cpu(map, iaini, iafinal);
	ball(map, px, py);
}

void edge(char map[V][H])
{

	int i, j;

	for (i = 0; i < V; i++)
	{   
         
		for (j = 0; j < H; j++)
		{

			if (i == 0 || i == V - 1)
			{

				map[i][j] = '-';
			}
			else if (j == 0 || j == H - 1)
			{

				map[i][j] = '|';
			}
			else
			{

				map[i][j] = ' ';
			}
		}
	}
}

void show(char map[V][H])
{

	int i, j;

	for (i = 0; i < V; i++)
	{

		for (j = 0; j < H; j++)
		{
            
			intf("%c", map[i][j]);
		}

		intf("\n");
	}
}

void player(char map[V][H], int jini, int jfinal)
{

	int i, j;

	for (i = jini; i < jfinal; i++)
	{

		for (j = 2; j <= 3; j++)
		{

			map[i][j] = 'X';
		}
	}
}

void cpu(char map[V][H], int iaini, int iafinal)
{

	int i, j;

	for (i = iaini; i < iafinal; i++)
	{

		for (j = H - 4; j <= H - 3; j++)
		{

			map[i][j] = 'X';
		}
	}
}

void ball(char map[V][H], int py, int px)
{

	map[py][px] = 'O';
}

void gameloop(char map[V][H], int jini, int jfinal, int iaini, int iafinal, int px, int py, int modx, int mody, int modia)
{

	int gol;
	gol = 0;

	do
	{

		draw(map);
		input(map, &jini, &jfinal, &iaini, &iafinal, &px, &py, &modx, &mody, &modia, &gol);
		update(map, jini, jfinal, iaini, iafinal, px, py);
		Sleep(10);

	} while (gol == 0);
}

void draw(char map[V][H])
{

	gotoxy(0, 0);
	show(map);
}

void input(char map[V][H], int *jini, int *jfinal, int *iaini, int *iafinal, int *px, int *py, int *modx, int *mody, int *modia, int *gol)
{

	int i;
	char key;
	char key2;

	if (*py == 1 || *py == V - 2)
	{ // If touch, change direction of ball

		*mody *= -1;
	}

	if (*px == 1)
	{ // Verify GOL

		iawin = 1;
		*gol = 1;
	}

	if (*px == H - 2)
	{

		playerwin = 1;
		*gol = 1;
	}

	if (*px == 4)
	{

		for (i = (*jini); i <= (*jfinal); i++)
		{

			if (i == (*py))
			{

				*modx *= -1;
			}
		}
	}

	if (*px == H-5)
	{

		for (i = (*iaini); i <= (*iafinal); i++)
		{

			if (i == (*py))
			{

				*modx *= -1;
			}
		}
	}
	
	if (*iaini == 1 || *iafinal == V-1) {
		
		*modia *= -1;
		
	}

	// ball

	if (*gol == 0)
	{

		*px += (*modx);
		*py += (*mody);

		// racket ia:

		*iaini += (*modia);
		*iafinal += (*modia);

		// racket jugador:

		if (kbhit() == 1)
		{

			key = getch();

			if (key == 'w')
			{

				if (*jini != 1)
				{

					*jini -= 1;
					*jfinal -= 1;
				}
			}

			if (key == 's')
			{

				if (*jini != V - 5)
				{

					*jini += 1;
					*jfinal += 1;
				}
			}
		}
	}
}

void update(char map[V][H], int jini, int jfinal, int iaini, int iafinal, int py, int px)
{

	edge(map);
	player(map, jini, jfinal);
	cpu(map, iaini, iafinal);
	ball(map, px, py);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void setColor(int ForgC)
{
    WORD wColor;

    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

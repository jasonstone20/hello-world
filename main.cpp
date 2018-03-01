#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ncurses.h>
#include <time.h>


#define cls() printf("\e[1;1H\e[2J");

//ANSI ESC Color Macros use colorBegin followed by colorEnd
#define normalBegin ("\033[0;39m")
#define blackBegin ("\033[1;30m")
#define redBegin  ("\033[1;31m")
#define greenBegin ("\033[1;32m")
#define yellowBegin ("\033[1;33m")
#define blueBegin ("\033[1;34m")
#define magentaBegin ("\033[1;35m")
#define cyanBegin ("\033[1;36m")
#define whiteBegin ("\033[1;34m")
#define colorEnd ("\033[0m")

//varibles
bool GamePlay;

int X,Y,FruitX, FruitY;
const int Width = 38;
const int Height = 20;
char Player = '0';
int Score = 0;
int TailX[200], TailY[200];
int TailLength;

enum EDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
EDirection Dir;

class ColorText
{
    //Color Way 2: Varible Way just enter color name
    char normal[10] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
    char black[10] = { 0x1b, '[', '1', ';', '3', '0', 'm', 0 };
    char red[10] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char green[10] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char yellow[10] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char blue[10] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char magenta[10] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
    char cyan[10] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
    char white[10] = { 0x1b, '[', '1', ';', '3', '7', 'm', 0 };
};


void Setup()
{
    //Seed Ranom Generator
    srand(time(0));
    // Game Condtion
    GamePlay = true;

    //Player Postion

    X = (Width / 4);
    Y = (Height / 2);
    FruitX = rand() % Width/2;
    FruitY = rand() % Height;
    Score = 0;
}

void Draw()
{
    cls();
    printf("+");
    for (int i = 0; i < (Width-1); i++)
    {
         // Top Wall
        printf("-");
    }
    printf("+");
    for (int i = 0; i < Height; i++)
    {
        printf("\r\n");
        for (int j = 0; j < Width; j++)
        {
            //Left Wall
            if (j == 0 )
            {
                printf("|");
            }
            //Snake Head
            if (i == Y && j == X)
            {
                printf("%c", Player);
            }
            //Right Wall
            if (j == (Width-1))
            {
                printf("|");
            }
            else
            {
                printf("");
            }
            if (i == FruitY && j == (FruitX))
            {
                printf("*");
            }
            else
            {
                bool Print = false;
                for (int k = 0; k < TailLength; k++)
                {
                    if (TailX[k] == j && TailY[k] == i)
                    {
                        //Snake Body Char
                        printf("o");
                        Print = true;
                    }

                }
                if (!Print)
                {
                    printf(" ");
                }

            }
        }
    }
     //Bottom Wall
    printf("\r");
    printf("+");
    //printf("%d\n", X);
    //printf("%d\n", Y);
    //for (int i = 0; i < TailLength; i++ )
   // {
   //    printf("%d TX-", TailX[i]);
    //    printf("%d TY-", TailY[i]);
 //   }

    for (int i = 0; i < Width-1; i++)
    {
        printf("-");
    }
    printf("+");
    //Score
    printf("\n\rScore: %d", Score);
    printf("\n");


}
int Logic()
{
    //Snake Tail
    int PrevX = TailX[0];
    int PrevY = TailY[0];
    int Prev2X, Prev2Y;
    TailX[0] = X;
    TailY[0] = Y;
    for (int i = 1 ; i < TailLength; i++)
    {
      Prev2X = TailX[i];
      Prev2Y = TailY[i];

      TailX[i] = PrevX;
      TailY[i] = PrevY;

      PrevX = Prev2X;
      PrevY = Prev2Y;


    }

if ( X == FruitX && Y == FruitY)
    {
        Score += 10;
        FruitX = rand() % Width/2;
        FruitY = rand() % Height;
        TailLength++;
    }
    //Player Direction
    switch(Dir)
    {

        case LEFT:
            X--;
            break;
        case RIGHT:
            X++;
            break;
        case UP:
            Y--;
            break;
        case DOWN:
            Y++;
            break;
        default:
            break;
    }

}

int UserInput()
{
    cbreak();			/* Line buffering disabled, Pass on every thing to me 		*/
	keypad(stdscr, TRUE); // Grab all keys, function and cursor also
	scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
	Setup();
	//printf("%d\n", X);
	//printf("%d\n", Y);
    //User Input
	while(GamePlay = true)
	{
        char current = getch();
        switch(current)
        {
            case 'a':
            {
                //X--;
                Dir = LEFT;
               // printw("\nLeft");
                break;
            }
            case 'd':
            {
                //X++;
                Dir = RIGHT;
               // printw("\nRight");
                break;
            }
            case 'w':
            {
                //Y--;
                Dir = UP;
               // printw("\nUp");
                break;
            }
            case 's':
            {
                //Y++;
                Dir = DOWN;
               //printw("\nDown");
                break;
            }
            case 'x':
            {
                return 0;
                break;
            }
        }
        napms(500); //speed
        Draw();
        Logic();
        // Collision Detection
        for (int i = 0; i < TailLength; i++)
        {
            if (TailX[i] == X && TailY[i] == Y)
            {
                printf("Game Over");
                return 0;

            }
            else if (X == -2 || X == (Width-13) || Y == -2 || Y == Height+1 )
            {
                printf("Game Over");
                return 0;
            }
        }

     }


}


int main()
{
    noecho();
    curs_set(0);
	initscr();			/* Start curses mode 		*/
//	cbreak();			/* Line buffering disabled, Pass on every thing to me 		*/
//	scrollok(stdscr, TRUE);
//    nodelay(stdscr, TRUE);
//	Setup();
//	printf("%d\n", X);
//	printf("%d\n", Y);

    UserInput();
    endwin();
}

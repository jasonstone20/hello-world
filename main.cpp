#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <string>

#include "screen.h"


int main (int NumArg, char* Args[])
{
    screen S;
//    std::cout <<NumArg;
//    switch(NumArg)
//    {
//        case 1:
//        {
//            S.Start(0, 0 , 500 , 0);
//            break;
//        }
//        case 2:
//        {
//            printw("1-24 Height, 1-80 Width, 100-500 Speed, 0-1 GameMap ON/OFF\n");
//            refresh();
//            usleep(5000000);
//            exit(0);
//            break;
//        }
//        case 5:
//        {
//            int a = atoi(Args[1]);
//            int b = atoi(Args[2]);
//            int c = atoi(Args[3]);
//            int d = atoi(Args[4]);
//            S.Start(a, b, c, d);
//            break;
//        }
//        default:
//        {
//            printw("Please enter a valid selection\n");
//            printw("1-24 Height, 1-80 Width, 100-500 Speed, 0-1 GameMap ON/OFF\n");
//            refresh();
//            usleep(5000000);
//            exit(0);
//            break;
//        }
//
//    }
    S.SimpleStart();
    //S.Start(24, 80, 500, 1);
    //S.TurnBased(0, 0, 500, 0);
    //S.EditColor(1, 400, 400, 400);
    //S.ColorFill(4,1,1);
   // S.ColorText(1, 0, 15, 15, 1, "WORKS");
    //S.GetScreenSize();
    //S.GetScreenSize();
    //S.DrawHorzLine(23,15,30);
    //S.DrawVertLine(4,4,15);
    //S.DrawDiagDownLine(6,6,20);
    //S.DrawDiagUpLine(10,10,10);
    //S.print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ...");
}

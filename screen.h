#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <string>

#ifndef SCREEN_H
#define SCREEN_H


class screen
{
    int X;
    int Y;
    int maxHeight;
    int maxWidth;
    int height;
    int width;
    int displayHeight;
    int displayWidth;
    int startHeight;
    int stattWidth;
    int foreColor;
    int backColor;
    char partchar;
	char testVertical;
	char testHorizontal;
	char oldalchar;
	int points;
	int del;
	int get;
	char direction;
	int PlayerX;
	int PlayerY;
	//etel='*';
	char etel;
    std::string GameOver;
	std::string colorText;
	//int food.x;
    //int food.y;

    public:
         screen();
         void GetScreenSize();
         void SimpleStart();
         void Start(int startHeight, int startWidth, int speed, bool GameMapOn);
         void TurnBased(int startHeight, int startWidth, int speed, bool GameMapOn);
         void EditColor(int colorName, int redColor, int greenColor, int blueColor);
         void ColorFill(int foreColor, int backColor, bool colorOn);
         void DisplayScreen(int displayHeight, int displayWidth, bool GameMapOn);
         void DisplayPlayer();
         void MovePlayer();
         bool Collision();
         int EndGame();
         void DrawHorzLine(int startLineX, int startLineY, int lineLength);
         void DrawVertLine(int startLineX, int startLineY, int lineLength);
         void DrawDiagDownLine(int startLineX, int startLineY, int lineLength);
         void DrawDiagUpLine(int startLineX, int startLineY, int lineLength);
         void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
         void GameMap(int height, int width);
         void ColorText(int foreColor, int backColor, int colorTextX, int colorTextY, bool colorOn, char* colorText);
        virtual ~screen();
    protected:
    private:

};

#endif // SCREEN_H

#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>

// Define color
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define VIOLET 5
#define BYELLOW 6
#define GRAY 7
#define WHITE 15

const int BACKGROUND_COLOR = GRAY;

// Change the console color
void changeConsoleColor(int BackC);

// Lock resize console windows
void fixConsoleWindow();

// Resize the console with width and height
void resizeConsole(int width, int height);

// Change the text color
void textColor(int n);

// Change the text color with padding 
void textFillColor(int colorCode, int BackC);

// Move the cursor pointer the location (x, y)
void gotoXY(short x, short y);

// Remove scrolllbar
void removeScrollbar();

void hideCursor();

void colorText(std::string Text, int Color);

void colorText(char Text, int Color);

void snakeLogoRight();

void snakeLogoLeft();
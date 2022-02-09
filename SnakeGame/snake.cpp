﻿#pragma once

#include "snake.h"
#include "graphic.h"
#include "gameSound.h"
#include "level.h"

#include <fstream>
#include <conio.h>
#include <time.h>

#define WidthGame      130
#define HeightGame     35
#define SPEEDFIRST     50
#define SPEEDLATER	   30

std::string studentIds = "21127003211276482112709021127493";
int position = 8;
string colorXY[205][85];
short snakeColor;

void init(vector<Infomation>& Snake, Infomation& Food, Infomation& Derection, bool& endGame, int score) {
	Infomation Body;
	endGame = false;

	gotoXY(152, 5);  
	colorText("Score: ", RED); 
	cout << score;
	int pos = 15;

	for (int i = 0; i < 8; i++) {
		Body.data = studentIds[i];
		Body.x = pos; Body.y = 6;
		Snake.push_back(Body);
		pos--;
	}

	// Make first food
	srand((unsigned int)time(0));
	Food.x = 5 + rand() % (WidthGame - 2);
	Food.y = 5 + rand() % (HeightGame - 2);

	gotoXY(Food.x, Food.y);
	colorText(studentIds[position], snakeColor);

	// Init direction
	Derection.x = 1; 
	Derection.y = 0;
}

void moveSnake(vector<Infomation>& Snake, Infomation dir, Infomation& Food, bool& endGame, int& score) {
	Infomation Add;
	size_t size = Snake.size();

	for (size_t i = 0; i < size_t(size); i++) {
		if (i == 0) {
			// Move the head
			Snake[0].ox = Snake[0].x;    
			Snake[0].oy = Snake[0].y;
			
			Snake[0].x += dir.x;         
			Snake[0].y += dir.y;
		}
		else {
			// Move the body
			Snake[i].ox = Snake[i].x;         
			Snake[i].oy = Snake[i].y;
			
			Snake[i].x = Snake[i - 1].ox;     
			Snake[i].y = Snake[i - 1].oy;
		}

		// Pass the width and height
		//if (Snake[i].x >= WidthGame) {
		//	Snake[i].x = 0;
		//}

		//if (Snake[i].x < 0) {
		//	Snake[i].x = WidthGame - 1;
		//}
		//if (Snake[i].y >= HeightGame) { 
		//	Snake[i].y = 0; 
		//}
		//if (Snake[i].y < 0) {
		//	Snake[i].y = HeightGame - 1;
		//}

		if (colorXY[Snake[0].x][Snake[0].y] != "SAFE") {
			position = 8;
			endGame = true;
		}

		// Check seft-hitting
		if (i != 0 && (Snake[0].x == Snake[i].x && Snake[0].y == Snake[i].y)) {
			position = 8;
			gotoXY(Food.x, Food.y); 
			cout << " ";
			endGame = true;
		}
	}
	
	// Eat food
	if (Snake[0].x == Food.x && Snake[0].y == Food.y) {

		if (position == studentIds.size() - 1) {
			position = 0;
		}

		Add.data = studentIds[position++];
		Add.x = Snake[size - 1].ox;
		Add.y = Snake[size - 1].oy;
		Snake.push_back(Add);

		score++;  
		gotoXY(152, 5); 
		colorText("Score: ", RED); 
		cout << score;

		//playSound(L"resources/eatfood.wav");

		// Creat new food
		srand((unsigned int)time(0));
		Food.x = 5 + rand() % (WidthGame - 1);
		Food.y = 5 + rand() % (HeightGame - 1);

		gotoXY(Food.x, Food.y);
		colorText(studentIds[position], snakeColor);
	}
}

void drawSnake(vector<Infomation>& Snake) {
	size_t size = Snake.size();
	for (int i = 0; i < size; i++) {
		gotoXY(Snake[i].x, Snake[i].y);
		cout << Snake[i].data;
	}
	gotoXY(Snake[size - 1].ox, Snake[size - 1].oy);
	cout << " "; 
}

void mainLoop (
	Status& StatusMove, Status& StatusGame, 
	vector<Infomation>& Snake, 
	Infomation& Direction, Infomation& Food, 
	int& Speed, bool& endGame, int& score
) {
	moveSnake(Snake, Direction, Food, endGame, score);

	if (_kbhit()) {
		int key = _getch();

		if (key < 97 && key > 65) { // A - Z
			key += 32;
		}

		if (key == 'a') {
			StatusMove = Status::LEFT;
		}
		else if (key == 'd') {
			StatusMove = Status::RIGHT;
		}
		else if (key == 'w') {
			StatusMove = Status::UP;
		}
		else if (key == 's') {
			StatusMove = Status::DOWN;
		}
		else if (key == 32) { // Space - pause game
			StatusGame = Status::PAUSE;
		}
		else if (key == 27) {
			StatusGame = Status::ESC; // ESC - Exit game
		}
	}

	if (StatusMove == Status::LEFT) {
		if (Direction.x != 1) {
			Direction.x = -1;
			Direction.y = 0;
		}
	}
	else if (StatusMove == Status::RIGHT) {
		if (Direction.x != -1) {
			Direction.x = 1;
			Direction.y = 0;
		}
	}
	else if (StatusMove == Status::UP) {
		if (Direction.y != 1) {
			Direction.y = -1;
			Direction.x = 0;
		}
	}
	else if (StatusMove == Status::DOWN) {
		if (Direction.y != -1) {
			Direction.y = 1;
			Direction.x = 0;
		}
	}

	if (StatusGame == Status::PAUSE) {
		while (true) {
			if (_kbhit()) { // Wait for pressing space again
				int key = _getch();

				if (key == 32) {
					StatusGame = Status::EMPTY;
					break;
				}
				else {
					continue;
				}
			}
		}
	}

	if (StatusGame == Status::ESC) {
		position = 8;
		endGame = true;
	}
}

void playGame() {
	system("cls");

	vector<Infomation> Snake;
	Infomation Derection, Food;
	Status StatusMove, StatusGame;

	int Speed = SPEEDFIRST, score = 0;
	bool endGame = false;

	initLevel();
	level[0]();

	init(Snake, Food, Derection, endGame, score);
	while (!endGame) {
		Sleep(Speed);
		mainLoop(StatusMove, StatusGame, Snake, Derection, Food, Speed, endGame, score);
		drawSnake(Snake);
	}
}
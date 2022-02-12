﻿#pragma once
#include "menu.h"
#include "screen.h"
#include "graphic.h"
#include <fstream>
using namespace std;

void initMenu(vector<Menu>& listMenu) {
	Menu items;

	items.x = 85;
	items.y = 24;
	items.data = "PLAY GAME";
	listMenu.push_back(items);
	
	items.x = 85;
	items.y = 26;
	items.data = "LOAD GAME";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 28;
	items.data = "HIGH SCORE";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 30;
	items.data = "GUIDE";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 32;
	items.data = "SETTING";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 34;
	items.data = "OUR TEAM";
	listMenu.push_back(items);

	items.x = 85;
	items.y = 36;
	items.data = "QUIT GAME";
	listMenu.push_back(items);
}

void printMenu(vector<Menu> listMenu) {
	for (int i = 0; i < listMenu.size(); i++) {
		gotoXY(listMenu[i].x, listMenu[i].y); 
		cout << listMenu[i].data;
	}
}

void moveSelect(vector<Menu> listMenu, int& dir, bool& check) {
	while (true) {
		if (_kbhit()) {
			int key = _getch();
			if (key == 72) {
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y); cout << listMenu[dir].data;
				if (dir == 0) {
					dir = listMenu.size() - 1;
				}
				else {
					dir--;
				}

				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				textColor(RED);
				cout << (char)175 << " " << listMenu[dir].data << " "; 
				textColor(BLUE);
				//break;
			}
			else if (key == 80) { 
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y); 
				cout << listMenu[dir].data;

				if (dir == listMenu.size() - 1) {
					dir = 0;
				} 
				else {
					dir++;
				}

				textColor(RED); 
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y); 
				cout << (char)175 << " " << listMenu[dir].data << " "; 
				textColor(BLUE);
				//break;
			}
			else if (key == 13) {
				check = true;
				break;
			}
		}
	}
}

void moveSelectSetting(vector<Menu> listMenu, int& dir, bool& check) {
	while (true) {
		if (_kbhit()) {
			int key = _getch();
			if (key == 72) {
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y); cout << listMenu[dir].data;
				if (dir == 0) {
					dir = listMenu.size() - 1;
				}
				else {
					dir--;
				}

				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				textFillColor(RED, BLACK);
				cout << (char)175 << " " << listMenu[dir].data << " ";
				textFillColor(WHITE, BLACK);
				//break;
			}
			else if (key == 80) {
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				cout << "             ";
				gotoXY(listMenu[dir].x, listMenu[dir].y);
				cout << listMenu[dir].data;

				if (dir == listMenu.size() - 1) {
					dir = 0;
				}
				else {
					dir++;
				}

				textFillColor(RED, BLACK);
				gotoXY(listMenu[dir].x - 3, listMenu[dir].y);
				cout << (char)175 << " " << listMenu[dir].data << " ";
				textFillColor(WHITE, BLACK);
				//break;
			}
			else if (key == 13) {
				check = true;
				break;
			}
			else if (key == 27) {
				check = true;
				dir = -1;
				break;
			}
		}
	}
}

void setting() {
	textFillColor(BLUE, BLACK);
	for (int j = 15; j <= 40; ++j) {
		gotoXY(40, j);
		cout << "                                                                                                     ";
		Sleep(8);
	}

	textFillColor(WHITE, BLACK);
	for (int i = 40; i <= 140; ++i) {
		gotoXY(i, 15);
		cout << (char)(205);
		gotoXY(i, 40);
		cout << (char)(205);
	}

	for (int i = 15; i <= 40; ++i) {
		gotoXY(40, i);
		cout << (char)(186);
		gotoXY(140, i);
		cout << (char)(186);
	}

	gotoXY(40, 15);
	cout << (char)(201);

	gotoXY(40, 40);
	cout << (char)(200);

	gotoXY(140, 15);
	cout << (char)(187);

	gotoXY(140, 40);
	cout << (char)(188);

	int row = 16, col = 60;

	textFillColor(BYELLOW, BLACK);
	gotoXY(col, row++);
	wcout << L"	███████╗███████╗████████╗████████╗██╗███╗   ██╗ ██████╗ ";
	gotoXY(col, row++);
	wcout << L"	██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗  ██║██╔════╝ ";
	gotoXY(col, row++);
	wcout << L"	███████╗█████╗     ██║      ██║   ██║██╔██╗ ██║██║  ███╗";
	gotoXY(col, row++);
	wcout << L"	╚════██║██╔══╝     ██║      ██║   ██║██║╚██╗██║██║   ██║";
	gotoXY(col, row++);
	wcout << L"	███████║███████╗   ██║      ██║   ██║██║ ╚████║╚██████╔╝";
	gotoXY(col, row++);
	wcout << L"	╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝	";
	gotoXY(col, row++);

	int row5 = 33, col5 = 43;
	gotoXY(col5, row5++);
	textFillColor(GRAY, 64);
	cout << "                                                                                       ____";
	gotoXY(col5, row5++);
	textFillColor(VIOLET, 64);
	cout << "                                                                                      / . .\\";
	gotoXY(col5, row5++);
	textFillColor(BLUE, 64);
	cout << "                                                                                      \\   -----<";
	gotoXY(col5, row5++);
	textFillColor(GREEN, 64);
	cout << "                                                                                       \\  /";
	gotoXY(col5, row5++);
	textFillColor(BYELLOW, 64);
	cout << "   ____________________________________________________________________________________/ /";
	gotoXY(col5, row5++);
	textFillColor(RED, 64);
	cout << "-=:_____________________________________________________________________________________/";

	textFillColor(WHITE, 64);

	// Exit
	int row6 = 39, col6 = 43;
	gotoXY(col6, row6++);
	cout << "Press ESC to exit. Press enter to change value.";
}

void ourTeam() {
	textFillColor(RED, 64);
	for (int i = 40; i <= 140; ++i) {
		for (int j = 15; j <= 40; ++j) {
			gotoXY(i, j);
			cout << " ";
		}
	}

	textFillColor(WHITE, 64);
	for (int i = 40; i <= 140; ++i) {
		gotoXY(i, 15);
		cout << (char)(205);
		gotoXY(i, 40);
		cout << (char)(205);
	}

	//Our team border
	for (int i = 15; i <= 40; ++i) {
		gotoXY(40, i);
		cout << (char)(186);
		gotoXY(140, i);
		cout << (char)(186);
	}

	gotoXY(40, 15);
	cout << (char)(201);
	gotoXY(40, 40);
	cout << (char)(200);
	gotoXY(140, 15);
	cout << (char)(187);
	gotoXY(140, 40);
	cout << (char)(188);

	// Ourteam logo
	//int row = 16, col = 70;
	//textFillColor(GRAY, 64);
	//gotoXY(col, row++);
	//cout << "   ____               _______                  ";
	//gotoXY(col, row++);
	//cout << "  / __ \\             |__   __|                  ";
	//gotoXY(col, row++);
	//cout << " | |  | |_   _ _ __     | | ___  __ _ _ __ ___  ";
	//gotoXY(col, row++);
	//cout << " | |  | | | | | '__|    | |/ _ \\/ _` | '_ ` _ \\ ";
	//gotoXY(col, row++);
	//cout << " | |__| | |_| | |       | |  __/ (_| | | | | | |";
	//gotoXY(col, row++);
	//cout << "  \\____/ \\__,_|_|       |_|\\___|\\__,_|_| |_| |_|";

	//textFillColor(WHITE, 64);

	// Ourteam logo
	int row = 16, col = 60;
	textFillColor(RED, 64);
	gotoXY(col, row++);
	wcout << L" ██████╗ ██╗   ██╗██████╗     ████████╗███████╗ █████╗ ███╗   ███╗";
	gotoXY(col, row++);
	wcout << L"██╔═══██╗██║   ██║██╔══██╗    ╚══██╔══╝██╔════╝██╔══██╗████╗ ████║";
	gotoXY(col, row++);
	wcout << L"██║   ██║██║   ██║██████╔╝       ██║   █████╗  ███████║██╔████╔██║";
	gotoXY(col, row++);
	wcout << L"██║   ██║██║   ██║██╔══██╗       ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║";
	gotoXY(col, row++);
	wcout << L"╚██████╔╝╚██████╔╝██║  ██║       ██║   ███████╗██║  ██║██║ ╚═╝ ██║";
	gotoXY(col, row++);
	wcout << L" ╚═════╝  ╚═════╝ ╚═╝  ╚═╝       ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝";
	
	// Team 8 border
	textFillColor(BLUE, 64);
	for (int i = 43; i <= 79; ++i) {
		gotoXY(i, 24);
		cout << (char)(205);
		gotoXY(i, 32);
		cout << (char)(205);
	}
	for (int i = 24; i <= 32; ++i) {
		gotoXY(43, i);
		cout << (char)(186);
		gotoXY(79, i);
		cout << (char)(186);
	}

	gotoXY(43, 24);
	cout << (char)(201);
	gotoXY(43, 32);
	cout << (char)(200);
	gotoXY(79, 24);
	cout << (char)(187);
	gotoXY(79, 32);
	cout << (char)(188);

	textFillColor(WHITE, 64);

	// Teamm 8 logo
	int row1 = 22, col1 = 46;
	textFillColor(BLUE, 64);

	gotoXY(col1, row1++);
	cout << "  _____ ___   _   __  __   ___ ";
	gotoXY(col1, row1++);
	cout << " |_   _| __| /_\\ |  \\/  | ( _ )";
	gotoXY(col1, row1++);
	cout << "   | | | _| / _ \\| |\\/| | / _ \\";
	gotoXY(col1, row1++);
	cout << "   |_| |___/_/ \\_\\_|  |_| \\___/";

	textFillColor(WHITE, 64);
	
	// Team member
	int row2 = 27, col2 = 45;

	gotoXY(col2, row2++);
	textFillColor(RED, 64);
	cout << "Phan Thanh An       - 21127003";

	gotoXY(col2, row2++);
	textFillColor(BYELLOW, 64);
	cout << "Nguyen Nhat Nam     - 21127648";

	gotoXY(col2, row2++);
	textFillColor(CYAN, 64);
	cout << "Vo Nguyen Hoang Kim - 21127090";

	gotoXY(col2, row2++);
	textFillColor(GREEN, 64);
	cout << "Luu Hoang Bach      - 21127493";

	textFillColor(WHITE, 64);

	// Instructor border
	textFillColor(BLUE, 64);
	for (int i = 81; i <= 138; ++i) {
		gotoXY(i, 24);
		cout << (char)(205);
		gotoXY(i, 29);
		cout << (char)(205);
	}

	for (int i = 24; i <= 29; ++i) {
		gotoXY(81, i);
		cout << (char)(186);
		gotoXY(138, i);
		cout << (char)(186);
	}

	gotoXY(81, 24);
	cout << (char)(201);
	gotoXY(81, 29);
	cout << (char)(200);
	gotoXY(138, 24);
	cout << (char)(187);
	gotoXY(138, 29);
	cout << (char)(188);

	textFillColor(WHITE, 64);

	// Instructor logo
	int row3 = 22, col3 = 84;
	textFillColor(BLUE, 64);
	gotoXY(col3, row3++);
	cout << "  ___ _  _ ___ _____ ___ _   _  ___ _____ ___  ___ ";
	gotoXY(col3, row3++);
	cout << " |_ _| \\| / __|_   _| _ \\ | | |/ __|_   _/ _ \\| _ \\";
	gotoXY(col3, row3++);
	cout << "  | || .` \\__ \\ | | |   / |_| | (__  | || (_) |   /";
	gotoXY(col3, row3++);
	cout << " |___|_|\\_|___/ |_| |_|_\\\\___/ \\___| |_| \\___/|_|_\\";
	
	textFillColor(WHITE, 64);

	// Instructor information
	int row4 = 27, col4 = 83;

	gotoXY(col4, row4++);
	textFillColor(VIOLET, 64);
	cout << "Dr.Truong Toan Thinh - Teacher";
	
	textFillColor(WHITE, 64);	

	// Snake image
	/*int flag = 0;
	while (flag == 0) {
		Sleep(100);
		textFillColor(RED, 64);
		snakeImage();
		Sleep(100);
		textFillColor(VIOLET, 64);
		snakeImage(); 
		Sleep(100);
		textFillColor(BLUE, 64);
		snakeImage(); 
		Sleep(100);
		textFillColor(GREEN, 64);
		snakeImage(); 
		Sleep(100);
		textFillColor(BYELLOW, 64);
		snakeImage();
		Sleep(100);
		textFillColor(WHITE, 64);
		snakeImage();
	}*/

	// Snake image
	int row5 = 33, col5 = 43;
	gotoXY(col5, row5++);
	textFillColor(GRAY, 64);
	cout << "                                                                                       ____";
	gotoXY(col5, row5++);
	textFillColor(VIOLET, 64);
	cout << "                                                                                      / . .\\";
	gotoXY(col5, row5++);
	textFillColor(BLUE, 64);
	cout << "                                                                                      \\   -----<";
	gotoXY(col5, row5++);
	textFillColor(GREEN, 64);
	cout << "                                                                                       \\  /";
	gotoXY(col5, row5++);
	textFillColor(BYELLOW, 64);
	cout << "   ____________________________________________________________________________________/ /";
	gotoXY(col5, row5++);
	textFillColor(RED, 64);
	cout << "-=:_____________________________________________________________________________________/";

	textFillColor(WHITE, 64);

	// Exit
	int row6 = 39, col6 = 43;
	gotoXY(col6, row6++);
	cout << "Press ESC to exit.";
}

void guide() {
	textFillColor(RED, 65);
	for (int i = 40; i <= 140; ++i) {
		for (int j = 15; j <= 40; ++j) {
			gotoXY(i, j);
			cout << " ";
		}
	}

// Create boder for the table
	textFillColor(WHITE, 65);
	for (int i = 40; i <= 140; ++i) {
		gotoXY(i, 15);
		cout << (char)(205); // 205 =
		gotoXY(i, 40);
		cout << (char)(205);
	}

	for (int i = 15; i <= 40; ++i) {
		gotoXY(40, i);
		cout << (char)(186); // ||
		gotoXY(140, i);
		cout << (char)(186);
	}

	gotoXY(40, 15);
	cout << (char)(201); 

	gotoXY(40, 40);
	cout << (char)(200);

	gotoXY(140, 15);
	cout << (char)(187); 

	gotoXY(140, 40);
	cout << (char)(188); 

	/*int row = 16, col = 70;
	gotoXY(col, row++);
	cout << "   _____ _    _ _____ _____  ______ ";
	gotoXY(col, row++);
	cout << "  / ____| |  | |_   _|  __  \|  ____|";
	gotoXY(col, row++);
	cout << " | |  __| |  | | | | | |  | | |__   ";
	gotoXY(col, row++);
	cout << " | | |_ | |  | | | | | |  | |  __|  ";
	gotoXY(col, row++);
	cout << " | |__| | |__| |_| |_| |__| | |____ ";
	gotoXY(col, row++);
	cout << "  \\_____|\\____/|_____|_____/|______|";*/

	int row = 16, col = 75;
	textFillColor(BLACK, BLUE);
	gotoXY(col, row++);
	wcout << L" ██████╗ ██╗   ██╗██╗██████╗ ███████╗";
	gotoXY(col, row++);
	wcout << L"██╔════╝ ██║   ██║██║██╔══██╗██╔════╝";
	gotoXY(col, row++);
	wcout << L"██║  ███╗██║   ██║██║██║  ██║█████╗ ";
	gotoXY(col, row++);
	wcout << L"██║   ██║██║   ██║██║██║  ██║██╔══╝ ";
	gotoXY(col, row++);
	wcout << L"╚██████╔╝╚██████╔╝██║██████╔╝███████╗";

	textFillColor(WHITE, 65);
	gotoXY(50, 23);
	cout << "Read me first !!";
	gotoXY(50, 25);
	cout << "You will be a snake finding food to prolong your length.";
	gotoXY(50, 26);
	cout << "              ___";
	gotoXY(50, 27);
	cout << "             | W |";
	gotoXY(50, 28);
	cout << "          ___|___|___  ";
	gotoXY(50, 29);
	cout << "Pressing | A | S | D | to control the direction of the snake. ";
	gotoXY(50, 30);
	cout << "         |___|___|___|";
	
	gotoXY(50, 32);
	//textFillColor(RED, 65);
	cout << "Be carefull!";
	textFillColor(WHITE, 65);
	gotoXY(50, 34);
	cout << "You have to cope with barricades and walls in each level.";
	gotoXY(50, 36);
	cout<<"If you hit one of them, the snake will die.";
	gotoXY(50, 38);
	cout << "Good luck!";
	gotoXY(120, 39);
	cout << "Press ESC to exit.";
		
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void loadFileScore(vector<int> &saveScore) {
	ifstream filein;
	filein.open("saveScore.txt", ios::in);
	if (filein.fail() == true) {
		cout << "File cannot be found";
	}
	else {
		saveScore.clear();
		int x;
		while (filein >> x) {
			
			saveScore.push_back(x);
		}
	}
}

void highScore(vector<int>& saveScore, Screen screen) {
	//Border of highscore
	textFillColor(BLACK, BLACK);
	for (int i = 40; i <= 140; ++i) {
		for (int j = 15; j <= 40; ++j) {
			gotoXY(i, j);
			cout << " ";
		}
	}

	textFillColor(WHITE, BLACK);
	for (int i = 40; i <= 140; ++i) {
		gotoXY(i, 15);
		cout << (char)(205);
		gotoXY(i, 40);
		cout << (char)(205);
	}

	for (int i = 15; i <= 40; ++i) {
		gotoXY(40, i);
		cout << (char)(186);
		gotoXY(140, i);
		cout << (char)(186);
	}

	gotoXY(40, 15);
	cout << (char)(201);
	gotoXY(40, 40);
	cout << (char)(200);
	gotoXY(140, 15);
	cout << (char)(187);
	gotoXY(140, 40);
	cout << (char)(188);

	int colHS = 49;
	int rowHS = 17;
	textFillColor(14, BLACK);
	gotoXY(colHS, rowHS++);
	wcout << L"	██╗  ██╗██╗ ██████╗ ██╗  ██╗    ███████╗ ██████╗ ██████╗ ██████╗ ███████╗";
	gotoXY(colHS, rowHS++);
	wcout << L"	██║  ██║██║██╔════╝ ██║  ██║    ██╔════╝██╔════╝██╔═══██╗██╔══██╗██╔════╝";
	gotoXY(colHS, rowHS++);
	wcout << L"	███████║██║██║  ███╗███████║    ███████╗██║     ██║   ██║██████╔╝█████╗  ";
	gotoXY(colHS, rowHS++);
	wcout << L"	██╔══██║██║██║   ██║██╔══██║    ╚════██║██║     ██║   ██║██╔══██╗██╔══╝  ";
	gotoXY(colHS, rowHS++);
	wcout << L"	██║  ██║██║╚██████╔╝██║  ██║    ███████║╚██████╗╚██████╔╝██║  ██║███████╗";
	gotoXY(colHS, rowHS++);
	wcout << L"	╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝";
	
	textFillColor(14, BLACK);
	int a = 118;
	int b = 24;
	gotoXY(a, b++);
	wcout << L"  █████████████████  ";
	gotoXY(a, b++);
	wcout << L" ███████████████████ ";
	gotoXY(a, b++);
	wcout << L"██ ███████████████ ██";
	gotoXY(a, b++);
	wcout << L" ███████████████████ ";
	gotoXY(a, b++);
	wcout << L"  █████████████████  ";
	gotoXY(a, b++);
	wcout << L"   ███████████████   ";
	gotoXY(a, b++);
	wcout << L"     █  ██████  █    ";
	gotoXY(a, b++);
	wcout << L"         ███        ";
	gotoXY(a, b++);
	wcout << L"         ███        ";
	gotoXY(a, b++);
	wcout << L"         ███        ";
	gotoXY(a, b++);
	wcout << L"       ███████      ";
	gotoXY(a, b++);
	wcout << L"      █████████      ";
	gotoXY(a, b++);
	wcout << L"     ███████████      ";
	gotoXY(a, b++);
	wcout << L"      █████████       ";
	gotoXY(a, b++);
	wcout << L"     ███████████      ";

	//High score border
	screen.draw.retangle({ 44, 23 }, { 36, 15 }, RED, 1, colorXY);
	screen.draw.retangle({ 60, 24 }, { 0, 14 }, RED, 1, colorXY);
	screen.draw.retangle({ 44, 27 }, { 36, 0 }, RED, 1, colorXY);
	gotoXY(51, 25);
	textFillColor(11, BLACK);
	cout << "RANK";
	gotoXY(87, 25);
	cout << "Score";

	//Sort function
	for (int i = 0; i < saveScore.size(); i++) {
		for (int j = i + 1 ; j < saveScore.size(); j++) {
			if (saveScore[i] < saveScore[j]) {
				swap(saveScore[i], saveScore[j]);
			}
		}
	}

	//textColor(WHITE);
	
	textFillColor(14, BLACK);
	for (int i = 0; i < saveScore.size(); i++) {
		if (i >= 10) break;
		gotoXY(52, i+ 28);
		cout << i + 1;
		gotoXY(88, i + 28);
		cout << saveScore[i] << endl;
	}
	
}

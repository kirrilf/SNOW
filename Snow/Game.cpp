#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "windows.h"
#include "EditMapHeader.h"
#include "SetupHeader.h"


using namespace std;

void goInRight(int &x) {
	gotoxy(x, 4);
	cout << " ";
	x++;
	if (x > 78) {
		x = 1;
	}
	gotoxy(x, 4);
	cout << (char)203;
	
}

void goInLeft(int &x) {
	gotoxy(x, 4);
	cout << " ";
	x--;
	if (x < 1) {
		x = 78;
	}
	gotoxy(x, 4);
	cout << (char)203;

}

void goSnowflake(int x, int map[][25]) {
	gotoxy(x, 5);
	cout << "*";
	map[x][5] = 42;
}


int keyPressed(int movingInRight, int movingInLeft, int snowflakeFall, int &x, int map[][25]) {
	if (_kbhit()) {
		int numberKey = _getch(), numberArrow = 0;
		if (numberKey == 224) {
			numberArrow = _getch();
			if(numberArrow == movingInRight) {
				goInRight(x);
				return 1;
			}
			else if (numberArrow == movingInLeft) {
				goInLeft(x);
				return 1;
			}
		}
		else if (numberKey == movingInRight) {
			goInRight(x);
			return 1;
		}
		else if (numberKey == movingInLeft) {
			goInLeft(x);
			return 1;
		}
		else if (numberKey == snowflakeFall) {
			goSnowflake(x, map);
			return 1;
		}
		else if (numberKey == 27) {
			return 2;
		}
		else if (numberKey == 115) {
			return 3;
		}


	}

}

void showMapa(int map[][25]) {
	system("cls");
	gotoxy(0, 0);
	cout << "TO SAVE, PRESS         \"S\"  ";
	gotoxy(0, 2);
	cout << "IN MENU              \"ESC\"  ";

	for (int i = 0; i < 80; i++) {
		for (int j = 3; j < 25; j++) {
			gotoxy(i, j);
			cout << (char)map[i][j];
		}
	}
}

void movingSnowflake(int map[][25]) {
	for (int i = 0; i < 80; i++) {
		for (int j = 24; j >= 3; j--) {
			if (map[i][j] == 42) {
				if (map[i][j + 1] == 0) {
					gotoxy(i, j);
					map[i][j] = 0;
					map[i][j + 1] = 42;
					cout << " ";
					gotoxy(i, j+1);
					cout << (char)42;
					
				}
				else if (map[i - 1][j + 1] == 0 && map[i-1][j] == 0) {
					gotoxy(i, j);
					map[i][j] = 0;
					map[i-1][j + 1] = 42;
					cout << " ";
					gotoxy(i-1, j + 1);
					cout << (char)42;
				}
				else if (map[i + 1][j + 1] == 0 && map[i+1][j] == 0) {
					gotoxy(i, j);
					map[i][j] = 0;
					map[i + 1][j + 1] = 42;
					cout << " ";
					gotoxy(i + 1, j + 1);
					cout << (char)42;
				}
			}
		}
	}

}


void game() {
	int map[80][25];
	int fallSpeed, movingInRight, movingInLeft, snowflakeFall;
	int x = 1;

	
	readMap(map);

	fileRead(fallSpeed, movingInRight, movingInLeft, snowflakeFall);

	showMapa(map);
	gotoxy(x, 4);
	cout << (char)203;
	while (true) {
		int keyPress;
		keyPress = keyPressed(movingInRight, movingInLeft, snowflakeFall, x, map);
		if (keyPress == 2) {
			break;
		}
		else if (keyPress == 3) {
			saveMap(map);
		}
		movingSnowflake(map);
		Sleep(fallSpeed);

		


	}

}

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;


void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

void saveMap(int map[][25]) {

	ofstream File;
	File.open("D:\\test.dat", ios::binary);
	if (!File.is_open()) {
		cout << "Could not open file \n";
		return;
	}

	char ch;

	for (int i = 0; i < 80; i++) {
		for (int j = 3; j < 25; j++) {
			ch = map[i][j];
			File.put(ch);
		}
	}


	File.close();


}

void readMap(int map[][25]) {
	ifstream File;
	File.open("D:\\test.dat", ios::binary); // Открыли файл
	if (!File.is_open()) { // Проверили, удалось ли открыть файл
		cout << "Could not open file \n";
		return;
	}
	char ch;


	for (int i = 0; i < 80; i++) {
		for (int j = 3; j < 25; j++) {
			File.get(ch);
			map[i][j] = ch;
		}
	}


	File.close();


}

void outlineMap(int map[][25]) {
	for (int i = 0; i < 80; i++) {
		for (int j = 3; j < 25; j++) {
			if (i == 0 || i == 79) {
				map[i][j] = 179;
			}
			else if (j == 3 || j == 24) {
				map[i][j] = 196;
			}
			else {
				map[i][j] = 0;
			}
		}
	}

	map[0][3] = 218;
	map[0][24] = 192;
	map[79][3] = 191;
	map[79][24] = 217;

}

void removeAllMap(int map[][25]) {
	for (int i = 0; i < 80; i++) {
		for (int j = 3; j < 25; j++) {
			map[i][j] = 0;
			
		}
	}
	outlineMap(map);
}

void showMap(int map[][25]) {
	system("cls");
	gotoxy(0, 0);
	cout << "TO SAVE, PRESS         \"S\"  ";
	gotoxy(0, 1);
	cout << "REMOVE 1 ITEM, PRESS   \"D\"  ";
	gotoxy(0, 2);
	cout << "REMOVE ALL ITEM, PRESS \"A\"  ";
	for (int i = 0; i < 80; i++) {
		for (int j = 3; j < 25; j++) {
			gotoxy(i, j);
			cout << (char)map[i][j];
		}
	}


}


void fillingMap(int map[][25]) {
	int x = 1, y = 23;
	
	while (true) {
		gotoxy(x, y);
		int i = _getch(), j = 0;
		if (i == 224) {
			j = _getch();
		}
		if (j == 72) {
			y--;
		}
		else if (j == 80) {
			y++;
		}
		else if (j == 75) {
			x--;
		}
		else if (j == 77) {
			x++;
		}
		if (i == 13) {
			if (map[x][y] == 0) {
				map[x][y] = 219;
				cout << (char)219;
			}
			else {
				continue;
			}
		}
		if (i == 115) {
			saveMap(map);
			break;
		}
		if (i == 97) {
			removeAllMap(map);
			showMap(map);
		}
		if (i == 100) {
			map[x][y] = 0;
			cout << (char)0;
		}
		
		if (x < 1) {
			x = 78;
		}
		if (x > 78) {
			x = 1;
		}
	
		if (y < 6) {
			y = 23;
		}
		if (y > 23) {
			y = 6;
		}
		
	}

}

void editMap() {
	
	int map[80][25];
	readMap(map);
	//outlineMap(map);
	showMap(map);
	fillingMap(map);
	system("cls");
	

}

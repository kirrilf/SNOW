#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
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


void keyPressed(int movingInRight, int movingInLeft, int snowflakeFall, int &x, int map[][25]) {
	if (_kbhit()) {
		int numberKey = _getch(), numberArrow = 0;
		if (numberKey == 224) {
			numberArrow = _getch();
			if(numberArrow == movingInRight) {
				goInRight(x);
			}
			else if (numberArrow == movingInLeft) {
				goInLeft(x);
			}
		}
		else if (numberKey == movingInRight) {
			goInRight(x);
		}
		else if (numberKey == movingInLeft) {
			goInLeft(x);
		}
		else if (numberKey == snowflakeFall) {
			goSnowflake(x, map);
		}


	}

}

void showMapa(int map[][25]) {
	for (int i = 0; i < 80; i++) {
		for (int j = 3; j < 25; j++) {
			gotoxy(i, j);
			cout << (char)map[i][j];
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
		keyPressed(movingInRight, movingInLeft, snowflakeFall, x, map);
		
		
		
		
		//в зависимости от нажатой кнопки вызывает соответсвующию функцию 
		//кажый ход выводится массив 
		//функция сна здесь, просто задется время sleep();
		//функция анализа массива после кажой итерации проходит по всему массиву и распределяет упавшие и
		//перемещает падающие снежинки 


	}

}//// перенести в новый файл 

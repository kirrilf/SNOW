#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>



void keyPressed() {
	if (_kbhit()) {
		int numberKey = _getch(), numberArrow = 0;
		if (numberKey == 224) {
			numberArrow = _getch();
		}

	}

}// перенести в новый файл 


void game() {
	while (true) {

		keyPressed();//в зависимости от нажатой кнопки вызывает соответсвующию функцию 
		//кажый ход выводится массив 
		//функция сна здесь, просто задется время sleep();
		//функция анализа массива после кажой итерации проходит по всему массиву и распределяет упавшие и
		//перемещает падающие снежинки 


	}

}//// перенести в новый файл 

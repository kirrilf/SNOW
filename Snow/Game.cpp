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

}// ��������� � ����� ���� 


void game() {
	while (true) {

		keyPressed();//� ����������� �� ������� ������ �������� �������������� ������� 
		//����� ��� ��������� ������ 
		//������� ��� �����, ������ ������� ����� sleep();
		//������� ������� ������� ����� ����� �������� �������� �� ����� ������� � ������������ ������� �
		//���������� �������� �������� 


	}

}//// ��������� � ����� ���� 

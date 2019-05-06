
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <map>
#include <fstream>




using namespace std;


map <int, string> s1 = {
		{48, "0"},
		{49, "1"},
		{50, "2"},
		{51, "3"},
		{52, "4"},
		{53, "5"},
		{54, "6"},
		{55, "7"},
		{56, "8"},
		{57, "9"},
		{97, "A"},
		{98, "B"},
		{99, "C"},
		{100, "D"},
		{101, "E"},
		{102, "F"},
		{103, "G"},
		{104, "H"},
		{105, "I"},
		{106, "J"},
		{107, "K"},
		{108, "L"},
		{109, "M"},
		{110, "N"},
		{111, "O"},
		{112, "P"},
		{113, "Q"},
		{114, "R"},
		{115, "S"},
		{116, "T"},
		{117, "U"},
		{118, "V"},
		{119, "W"},
		{120, "X"},
		{121, "Y"},
		{122, "Z"},
		{75, "<-"},
		{72, "UP"},
		{80, "DOWN"},
		{77, "->"},
		{13, "ENTER"},
		{32, "SPACE"},
		{47, "/"},
		{42, "*"},
		{45, "-"},
		{43, "+"},
		{96, "`"},
		{91, "["},
		{93, "]"},
		{59, ";"},
		{39, "\'"},
		{98, "\\"}

};

void fileRead(int &fallSpeed, int &movingInRight, int &movingInLeft, int &snowflakeFall) {
	ifstream File;
	File.open("D:\\test1.dat", ios::binary); // ������� ����
	if (!File.is_open()) { // ���������, ������� �� ������� ����
		cout << "Could not open file \n";
		return;
	}

	

	int B[5];

	char *ch = (char *)B; // ch � ������ �� ������ �, ��� �� ������ �������� (����)

	int I = 0;

	while (File)

		File.get(ch[I++]);

	// ���������� ���� ����� �������� ������, ��������, ���:

	// while (i_File.get(*ch++);

	File.close(); // ��������� ����

	// ������� ������ � �� �����

	for (I = 0; I < 4; ++I) {

		fallSpeed = B[0];
		movingInRight = B[1];
		movingInLeft = B[2];
		snowflakeFall = B[3];
	}

	


}

void fileWrite(int fallSpeed, int movingInRight, int movingInLeft, int snowflakeFall) {
	ofstream File;
	File.open("D:\\test1.dat", ios::binary);
	if (!File.is_open()) {
		cout << "Could not open file \n";
		return;
	}
	

	
	int A[4] = { fallSpeed, movingInRight, movingInLeft, snowflakeFall};
	

	char *ch = (char *)A; // ch � ������ �� ������ �, ��� �� ������ �������� (����)

	for (int I = 0; I < sizeof(A); ++I)

		File.put(ch[I]);

	File.close();


	


}

int getValue()
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		int a;
		cin >> a;

		// �������� �� ���������� ����������
		if (cin.fail()) // ���� ���������� ���������� ��������� ����������
		{
			cin.clear(); // ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "ERROR.  Please try again.\n";
		}
		else
		{
			cin.ignore(2147483647, '\n'); // ������� ������ ��������

			return a;
		}
	}
}


int FallSpeed() {
	int fallSpeed = 1000;
	system("cls");
	cout << "ENTER THE FALL SPEDD: ";
	fallSpeed = getValue();
	if (fallSpeed > 10000 || fallSpeed < 0) {
		cout << "WRONG FALL SPEED";
		system("pause");
		return 1000;
	}
	
	return fallSpeed;
}

int NumberKey(int num, int num1, int num2) {
	cout << "PRESS KEY: ";
	int i = _getch(), j, num3;
	num3 = i;
	if (i == 224) {
		j = _getch();
		num3 = j;
	}
	if (num3 == num1 || num3 == num2 || num3 == 27 || num3 == 115 ) {
		cout << "INPUT ERROR";
		system("pause");
		return num;
	}
	
	return num3;
}

int menu(int fallSpeed, int movingInRight, int movingInLeft, int snowflakeFall) {
	int k = 1, num = 1;

	string  A = "FALL SPEED     : ",
			B = "MOVING IN RIGHT: ",
			C = "MOVING IN LEFT : ",
			D = "SNOWFLAKE FALL : ",
			E = "MENU             ";


	system("cls");

	cout << ">> " << A << fallSpeed <<  "\n";
	cout << B << "\"" << s1[movingInRight] << "\"" << "\n";
	cout << C << "\"" << s1[movingInLeft]  << "\"" << "\n";
	cout << D << "\"" << s1[snowflakeFall] << "\"" << "\n";
	cout << E;


	while (true) {

		int l = _getch(), c = 0;
		if (l == 224) {
			c = _getch();
		}
		system("cls");

		if (c == 80) {
			k++;
		}

		else if (c == 72) {
			k--;
		}


		if (k == 6) {
			k = 1;
		}

		else if (k == 0) {
			k = 5;
		}

		if (l == 13) {
			return k;
		}


		if (k == 1) {
			cout << ">> " << A << fallSpeed << "\n";
			cout << B << "\"" << s1[movingInRight] << "\"" << "\n";
			cout << C << "\"" << s1[movingInLeft] << "\"" << "\n";
			cout << D << "\"" << s1[snowflakeFall] << "\"" << "\n";
			cout << E;
		}
		else if (k == 2) {
			cout << A << fallSpeed << "\n";
			cout << ">> " << B << "\"" << s1[movingInRight] << "\"" << "\n";
			cout << C << "\"" << s1[movingInLeft] << "\"" << "\n";
			cout << D << "\"" << s1[snowflakeFall] << "\"" << "\n";
			cout << E;
		}
		else if (k == 3) {
			cout << A << fallSpeed << "\n";
			cout << B << "\"" << s1[movingInRight] << "\"" << "\n";
			cout << ">> " << C << "\"" << s1[movingInLeft] << "\"" << "\n";
			cout << D << "\"" << s1[snowflakeFall] << "\"" << "\n";
			cout << E;
		}
		else if (k == 4) {
			cout << A << fallSpeed << "\n";
			cout << B << "\"" << s1[movingInRight] << "\"" << "\n";
			cout << C << "\"" << s1[movingInLeft] << "\"" << "\n";
			cout << ">> " << D << "\"" << s1[snowflakeFall] << "\"" << "\n";
			cout << E;
		}
		else if (k == 5) {
			cout << A << fallSpeed << "\n";
			cout << B << "\"" << s1[movingInRight] << "\"" << "\n";
			cout << C << "\"" << s1[movingInLeft] << "\"" << "\n";
			cout << D << "\"" << s1[snowflakeFall] << "\"" << "\n";
			cout << ">> " << E;
		}

	}

}

void setup() {
	int fallSpeed = 1000, movingInRight = 77, movingInLeft = 75, snowflakeFall = 13;
	fileRead(fallSpeed, movingInRight, movingInLeft, snowflakeFall);
	while (true) {
		int parametrMenu = menu(fallSpeed, movingInRight, movingInLeft, snowflakeFall);
		if (parametrMenu == 1) {
			fallSpeed = FallSpeed();
		}
		else if (parametrMenu == 2) {
			movingInRight = NumberKey(movingInRight, movingInLeft, snowflakeFall);
		}
		else if (parametrMenu == 3) {
			movingInLeft = NumberKey(movingInLeft, movingInRight, snowflakeFall);
		}
		else if (parametrMenu == 4) {
			snowflakeFall = NumberKey(snowflakeFall, movingInRight, movingInLeft);
		}
		else if (parametrMenu == 5) {
			fileWrite(fallSpeed, movingInRight, movingInLeft, snowflakeFall);
			break;
		}
	}
	
}
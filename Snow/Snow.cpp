
#include "pch.h"
#include "EditMapHeader.h"
#include "SetupHeader.h"
#include "GameHeader.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>


using namespace std;





int menu() {
	int k = 1, num = 1;

	string	A = "START           ",
			B = "EDITING THE MAP ",
			C = "SETUP           ",
			D = "EXIT            ";
		

	system("cls");
	
	cout << A << "<--\n";
	cout << B << "\n";
	cout << C << "\n";
	cout << D << "\n";
	

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


		if (k == 5) {
			k = 1;
		}

		else if (k == 0) {
			k = 4;
		}

		if (l == 13) {
			return k;
		}


		if (l == 49) {
			return 1;
		}
		else if (l == 50) {
			return 2;
		}
		else if (l == 51) {
			return 3;
		}
		else if (l == 52) {
			return 4;
		}
		


		if (k == 1) {
			cout << A << "<--\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			
		}
		else if (k == 2) {
			cout << A << "\n";
			cout << B << "<--\n";
			cout << C << "\n";
			cout << D << "\n";
			
		}
		else if (k == 3) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "<--\n";
			cout << D << "\n";
		
		}
		else if (k == 4) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "<--\n";
			
		}
		
	}

}

void startMenu(){
	int parametrMenu = menu();
	if (parametrMenu == 1) {
		game();
	}
	else if (parametrMenu == 2) {
		editMap();
	}
	else if (parametrMenu == 3) {
		setup();
	}
	else if (parametrMenu == 4) {
		cout << "TIP VSE";
	}

}


int main()
{
	while (true) {
		startMenu();
	}

	return 0;
}

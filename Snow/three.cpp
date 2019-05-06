#include "pch.h"
#include "EditMapHeader.h"
#include "SetupHeader.h"
#include "GameHeader.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;




struct SingleLinkedList
{
	int numberX, numberY;
	bool edgeLeft = false, edgeRight = false;
	SingleLinkedList *next;
	SingleLinkedList *nextGG;
	SingleLinkedList *previous;
	SingleLinkedList *down = NULL;

};

SingleLinkedList *firstElement;
SingleLinkedList *firstElementGG;
SingleLinkedList *lastElement;

void AddElemenToList(int numX, int numY)
{
	SingleLinkedList *Element = new SingleLinkedList;
	SingleLinkedList *temp = new SingleLinkedList;
	Element->numberX = numX;
	Element->numberY = numY;

	if (firstElement == NULL && firstElement == lastElement) {
		firstElement = Element;
		firstElementGG = Element;
		firstElement->previous = NULL;
		lastElement = Element;
		lastElement->next = NULL;
		lastElement->nextGG = NULL;

	}
	else {
		lastElement->next = Element;
		lastElement->nextGG = Element;
		temp = lastElement;
		lastElement = Element;
		lastElement->previous = temp;
		lastElement->next = NULL;
		lastElement->nextGG = NULL;
	}


}

void ShowMap(int map[][25]) {
	system("cls");
	gotoxy(0, 0);
	cout << "BUILD A THREE, PRESS         \"ENTER\"  ";
	gotoxy(0, 2);
	cout << "IN MENU              \"ESC\"  ";

	for (int i = 0; i < 80; i++) {
		for (int j = 3; j < 25; j++) {
			gotoxy(i, j);
			cout << (char)map[i][j];
		}
	}


}

void createList(int map[][25], int x, int y) {
	int k1 = 0, k2 = 0;
	bool fl = false;
	while (map[x][y] == 42) {
		while (map[x + 1][y] == 42) {
			x++;
		}

		AddElemenToList(x, y);

		while (map[x - 1][y] == 42) {
			x--;
			k2++;
			AddElemenToList(x, y);
		}

		if (k1 > k2 || fl == true) {
			int xCop = x, yCop = y;
			x--;
			while (map[x][y] != 42) {
				x--;
			}
			while (map[x - 1][y] == 42) {
				x--;
				k2++;
				AddElemenToList(x, y);
			}
			x = xCop;
			y = yCop;
			fl = true;
		}

		k1 = 0;
		k2 = 0;
		while (map[x + 1][y] == 42) {
			x++;
			k1++;
		}
		y++;
	}


}

void buildThreeList(int map[][25], int x, int y) {
	createList(map, x, y);
	SingleLinkedList *temp = new SingleLinkedList;
	temp = firstElement;
	while (temp) {
		int x = temp->numberX, y = temp->numberY;
		if (map[x + 1][y] != 42) {
			temp->edgeRight = true;
		}
		if (map[x - 1][y] != 42) {
			temp->edgeLeft = true;
		}

		temp = temp->next;
	}


}

void buildThree() {
	SingleLinkedList *temp = new SingleLinkedList;
	temp = firstElement;
	while (temp) {
		int x = temp->numberX, y = temp->numberY;
		SingleLinkedList *temp1 = new SingleLinkedList;
		temp1 = firstElement;
		while (temp1) {
			if (temp1->numberX == x && temp1->numberY == y + 1) {
				temp->down = temp1;

			}
			temp1 = temp1->next;
		}



		temp = temp->next;
	}
	temp = firstElementGG;

	while (temp) {
		if (temp->edgeLeft == true) {
			temp->next = NULL;
		}

		if (temp->edgeRight == true) {
			temp->previous = NULL;
		}

		temp = temp->nextGG;
	}



}

void ShowThree() {
	SingleLinkedList *temp = new SingleLinkedList;
	temp = firstElementGG;
	system("cls");
	while (temp) {

		//cout << temp->numberX << "  " << temp->numberY << temp->down <<" "<<  temp->next << " " << temp->previous << " " << temp->edgeLeft << temp->edgeRight << endl;
		int x = temp->numberX, y = temp->numberY;
		gotoxy(x, y);
		if (temp->next != NULL && temp->down != NULL && temp->previous == NULL) {
			cout << (char)191;
		}
		else if (temp->next == NULL && temp->down != NULL && temp->previous == NULL) {
			cout << (char)179;
		}
		else if (temp->next != NULL && temp->down == NULL && temp->previous != NULL) {
			cout << (char)196;
		}
		else if (temp->next == NULL && temp->down != NULL && temp->previous != NULL) {
			cout << (char)218;
		}
		else if (temp->next != NULL && temp->down != NULL && temp->previous != NULL) {
			cout << (char)194;
		}
		else {
			cout << (char)196;
		}


		gotoxy(0, 0);
		temp = temp->nextGG;
	}
	cout << "PRESS \"ENTER\"  exit the menu. ";

	while (_getch() != 13) {
		system("cls");
		cout << "PRESS \"ENTER\" to exit the menu. ";
	}
	
}


void DeleteThree() {
	SingleLinkedList *temp1 = new SingleLinkedList;
	SingleLinkedList *temp2 = new SingleLinkedList;
	temp1 = firstElement;

	while (temp1) {
		temp2 = temp1;
		temp1 = temp1->nextGG;
		delete temp2;
	}
	firstElement = NULL;
	lastElement = NULL;
	return;

}


void goToMap(int map[][25], int &x, int &y) {
	x = 1;
	y = 23;

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
			if (map[x][y] == 42) {
				buildThreeList(map, x, y);
				buildThree();
				ShowThree();
				DeleteThree();
				return;
			}
			else {
				continue;
			}
		}
		if (i == 27) {
			break;
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



void three() {
	int map[80][25], x, y;
	readMap(map);
	ShowMap(map);
	goToMap(map, x, y);
	

}
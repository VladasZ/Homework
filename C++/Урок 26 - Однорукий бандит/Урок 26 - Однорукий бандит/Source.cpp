#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define RAND_SUIT rand()%3 + 3
#define RAND_RANK rand()%15

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Card{

public:
	int n;
	char m;
	//â™¥â™¦â™£â™ 
	Card(){
		m = RAND_SUIT;
		n = RAND_RANK;
	}
	int displayCard(int pos, int row){
		if (!n) {// Ð¿ÑƒÑÑ‚Ð°Ñ ÐºÐ°Ñ€Ñ‚Ð°

			gotoxy(pos, row);
			cout << " " << endl;
			gotoxy(pos, row + 1);
			cout << " " << endl;
			gotoxy(pos, row + 2);
			cout << " " << endl;
			gotoxy(pos, row + 3);
			cout << " " << endl;
			return 0;
		}

		gotoxy(pos, row);
		cout << " __" << endl;
		gotoxy(pos, row + 1);
		cout << '|' << (char)m << " |" << endl;
		gotoxy(pos, row + 2);
		cout << '|';
		if (n < 10) cout << n << ' ';
		if (n == 10) cout << "10";
		else{
			switch (n)
			{
			case 11:
				cout << "J ";
				break;
			case 12:
				cout << "Q ";
				break;
			case 13:
				cout << "K ";
				break;
			case 14:
				cout << "A ";
				break;
			}

		}
		cout << '|' << endl;
		gotoxy(pos, row + 3);
		cout << "|__|" << endl;
		// gotoxy(pos, row+4);
		return 0;
	}

};


int main(){
	while (1){
		Card a, b, c;
		static int row = 8;

		a.displayCard(0, 0);
		b.displayCard(5, 0);
		c.displayCard(10, 0);

		if (a.m == b.m && b.m == c.m){
			gotoxy(0, row++);
			cout << "Winner!" << endl;
		}
		if (a.n == b.n && b.n == c.n){
			gotoxy(0, row++);
			cout << "Winner!" << endl;
		}
		getch();
	}

}



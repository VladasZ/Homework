#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define RAND rand()%36
#define PL1 1
#define PL2 0

int moveTurn = PL1;
int attackTurn = PL1;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void tableCls(){

	for (int i = 0; i < 15; i++){
		gotoxy(10, 4 + i); 
		for (int j = 0; j < 50; j++){
			cout << " ";
		}
		
	}

}

class Card{

public:
	int n;
	char m;
	//♥♦♣♠
	int displayCard(int pos, int row){
		if (!n) {// пустая карта

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

class Deck{
public:
	Card deck[36];
	Card trump;
	int cardLeft = 35;


	Deck(){ ////////////////////////////////// конструктор колоды
		srand(time(NULL));
		int cardN = 0;
		for (int i = 3; i < 7; i++){
			for (int j = 6; j < 15; j++, cardN++){
				deck[cardN].n = j;
				deck[cardN].m = i;
			}
		}


		Card temp, *foo, *bar; ///////////////////// тасовка колоды
		for (int i = 0; i < 5000000; i++){
			foo = &deck[RAND];
			bar = &deck[RAND];

			temp = *foo;

			*foo = *bar;
			*bar = temp;


		}

		trump = deck[0];
	};

	void show(){
		tableCls();
		int card = 0;

		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 9; j++){
				deck[card].displayCard(j * 4 + 10, i * 4 + 4);
				card++;
			}
		}
	}
};

Deck deck;

class Table{

public:
	Card table[35];
	int cardLeft = 0;

	void takeOneCard(){
		table[cardLeft] = deck.deck[deck.cardLeft];
		deck.deck[deck.cardLeft].n = 0;
		deck.cardLeft--;
		cardLeft++;
	}
	void takeCard(){
		while (cardLeft < 6) takeOneCard();
	}

	void display(){
		tableCls();
		int shift = 0;
		for (int i = 0; i < cardLeft; i++){

			table[i].displayCard(15 + i * 2, 8 + shift);

			if (!shift){ shift = 2; continue; }
			shift = 0;

		}


	}

	void clear(){
		cardLeft = 0;
		for (int i = 0; i < 35; i++){
			table[i].n = 0;
		}
		display();
	}



};

Table table;




class Player{
public:
	Card hand[35];
	int pos;
	int turn = 0;
	int attack = 0;
	int cardLeft = 0;

	Player(int a){
		turn = 0;
		attack = 0;
		pos = a;
		takeCard();
		sortHand();
	}

	void takeOneCard(){
		hand[cardLeft] = deck.deck[deck.cardLeft];
		deck.deck[deck.cardLeft].n = 0;
		deck.cardLeft--;
		cardLeft++;
	}
	int takeCard(){
		if (!(deck.cardLeft + 1)) return 0;
		if (cardLeft > 6) return 0;
		while (cardLeft < 6) takeOneCard();
		sortHand();
		return 0;
	}
	void showHand(){

		for (int i = 0; i < 4; i++){
			gotoxy(10, pos + i);
			for (int j = 0; j < 50; j++){
				cout << ' ';
			}
		}

		for (int i = 0; i < cardLeft; i++){
			hand[i].displayCard(i * 4 + 12, pos);
		}

	}
	void sortHand(){
		for (int i = 0; i < cardLeft - 1; i++){
			for (int j = 0; j < cardLeft - 1; j++){

				if (hand[j].n > hand[j + 1].n){

					Card temp = hand[j];
					hand[j] = hand[j + 1];
					hand[j + 1] = temp;

				}

			}
		}
	}


	int dropCard(int n){
		if (n > cardLeft - 1) return 0;











		//////////// drop logic /////////////
		table.table[table.cardLeft] = hand[n];
		hand[n].n = 0;
		for (int i = n; i < cardLeft; i++){
			hand[i] = hand[i + 1];
			if (i == cardLeft - 2) hand[i + 1].n = 0;
		}
		table.cardLeft++;
		cardLeft--;

		table.display();
		showHand();

		return 0;
	}

	bool _throw(int n){
		for (int i = 0; i < table.cardLeft; i++){
			if (hand[n].n == table.table[i].n) return true;
		}
		return false;
	}

	bool canDrop(int n){


		// битье карты козырем
		if (deck.trump.m == hand[n].m &&
			table.table[table.cardLeft - 1].m != deck.trump.m  &&
			table.cardLeft % 2
			) return true;


		// "битье" карты
		if (table.table[table.cardLeft - 1].m == hand[n].m &&
			table.table[table.cardLeft - 1].n < hand[n].n &&
			table.cardLeft % 2
			) return true;





		// ход на пустой стол
		if (!table.cardLeft) return true;


		// следующий атакующий ход
		if (!(table.cardLeft % 2) &&
			_throw(n)



			) return true;

		return false;

	}

	void takeTable(){

		while (table.cardLeft){
			hand[cardLeft] = table.table[table.cardLeft - 1];
			table.cardLeft--;
			table.table[table.cardLeft].n = 0;
			cardLeft++;
			sortHand();
		}

	}


};

Player player = 0, player2 = 20;

void debugDisplay(){
	gotoxy(50, 7); cout << "Очистить экран: B";
	gotoxy(50, 8); cout << "Показать колоду: V";
	gotoxy(50, 9); cout << "Забрать: C";
	gotoxy(50, 10); cout << "Отбой: X";
	/*
	gotoxy(50, 13); cout << "player 1 cardLeft: "<< player.cardLeft;
	gotoxy(50, 14); cout << " turn: " << player.turn;
	gotoxy(50, 15); cout << " attack: " << player.attack;
	gotoxy(50, 18); cout << "player 2 cardLeft: " << player2.cardLeft;
	gotoxy(50, 19); cout << " turn: " << player2.turn;
	gotoxy(50, 20); cout << " attack: " << player2.attack;
	gotoxy(50, 22); cout << "deck cardLeft: " << deck.cardLeft+1;
	gotoxy(50, 23); cout << "table cardLeft: " << table.cardLeft;*/


}

void take(){
	if (table.cardLeft % 2){
		if (player.turn){
			player.takeTable();
			player.turn--;
			player2.turn++;
			table.display();
			player.showHand();
			player2.takeCard();


		}
		else if (player2.turn){
			player2.takeTable();
			player2.turn--;
			player.turn++;
			table.display();
			player2.showHand();
			player.takeCard();

		}
	}
}

void remove(){
	if (!(table.cardLeft % 2) && table.cardLeft){
		if (player.turn){
			player.turn--;
			player2.turn++;
			table.display();



		}
		else if (player2.turn){
			player2.turn--;
			player.turn++;
			table.display();
		}


		player.takeCard();
		player2.takeCard();
		table.cardLeft = 0;
		table.display();
	}
}

void movesControl(){

	deck.trump.displayCard(4, 10);
	
	player.showHand();
	player2.showHand();
	gotoxy(9, 2); cout << '0';

	player.attack = 1;
	player.turn = 1;
	debugDisplay();
	while (1){




		////////// getch//////////////////
		char a = getch();
		switch (a){	
		case '1': case '2':case '3':case '4':case '5':case '6': case '7':case '8':case '9':case '0':
			if (player.turn && player.canDrop(a - 49)){
				player.dropCard(a - 49);
				player.turn--;
				player2.turn++;
			}
			else if (player2.turn && player2.canDrop(a - 49)){
				player2.dropCard(a - 49);
				player2.turn--;
				player.turn++;
			}
			break;
		case'c':// забрать
			take();
			break;
		case'v':
			deck.show();
			break;
		case'b':
			tableCls();
			break;
		case'z':
			goto l;
			break;
		case'x': /////////// отбой
			remove();
			break;
		default:

			break;
		}
		if (player.turn) { gotoxy(9, 2); cout << '0'; gotoxy(9, 22); cout << ' '; }
		else { gotoxy(9, 22); cout << '0'; gotoxy(9, 2); cout << ' '; }




		player.showHand();
		player2.showHand();

		debugDisplay();

	}
l:;


}



void main(){
	setlocale(LC_ALL, "rus");


	movesControl();




}
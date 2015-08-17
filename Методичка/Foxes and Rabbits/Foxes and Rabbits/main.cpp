#include <iostream>
#include <Windows.h>
using namespace std;

#define HIGH 20
#define LENGTH 50

struct Location{
	int x;
	int y;
	Location(int x, int y) : x(x), y(y){}
	Location() : x(0), y(0){};
	void setLoc(int x, int y){
		this->x = x;
		this->y = y;
	}
	void show(){
		cout << x << ' ' << y << endl;
	}
};

class Creature;
class Fox;
class Rabbit;
class Empty;

Creature* field[HIGH][LENGTH];

class Creature{
public:
	Creature* neighbors[3][3];
	Location location;
	virtual char look() = 0;
	virtual int move() = 0;
	virtual int getAge() = 0;

	Creature(int x, int y){
		location.setLoc(x, y);
	}
	Creature(){}
	virtual void lookAround(){
	/*	cout << "i see something!" << endl;
		cout << " i see myself! i'm looks like - " << look() << endl;

		cout << "i'm here: "; location.show();*/

		int y = location.y - 1;
		int x = location.x - 1;

		for (int i = 0; i < 3; i++){
			
			for (int j = 0; j < 3; j++){	
						
				neighbors[j][i] = field[x++][y];		
				
			}
			y++; x = x = location.x - 1;
		}
		

		/*cout << " i see my neighbors! they are: " << endl;

		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << neighbors[i][j]->look();
			}
			cout << endl;
		}*/
	}

};



class Rabbit :public Creature{
public:
	int age = 0;
	int getAge(){
		return age;
	}
	Rabbit(int x, int y) : Creature(x, y){}

	char look(){ return 'R'; }
	int move(){ return 0; }
};

class Empty :public Creature{
public:
	int age = 0;
	int getAge(){
		return age;
	}
	Empty(int x, int y) : Creature(x, y){}

	char look(){ return ' '; }
	int move(){ return 0; }
};


class Wall :public Creature{
public:
	int age = 0;
	int getAge(){
		return age;
	}
	Wall(int x, int y) : Creature(x, y){}

	char look(){ return 219; }
	int move(){ cout << "Walls can't move!" << endl; return 0; }
	void lookAround(){
		cout << "\nSorry! I'm a wall. I can't see anything T_T" << endl;
	}
};


class Fox :public Creature{
public:
	int age = 0;
	int getAge(){
		return age;
	}

	Fox(int x, int y) : Creature(x, y){}
	char look(){ return 'F'; }
	int move(){
		// едим соседнего зайца
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (neighbors[i][j]->look() == 'R')
				{
					field[location.x - 1 + i][location.y - 1 + j] = new Empty(location.x - 1 + i, location.y - 1 + j);
					return 0;
				}
			}
		}
		// Двигаемся если зайцев нет
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (neighbors[i][j]->look() == ' ' && 1)
				{
					field[location.x - 1 + i][location.y - 1 + j] = this;
					//field[location.x - 1 + i][location.y - 1 + j]->location.x = location.x - 1 + i;
					//field[location.x - 1 + i][location.y - 1 + j]->location.y = location.y - 1 + j;

					field[i][j] = new Empty(i, j);
					return 0;
				}
			}
		}


	}

};

void createField(){
	for (int i = 0; i < HIGH; i++){
		for (int j = 0; j < LENGTH; j++){


			// создаем стену для того чтобы не выйти за пределы массива когда животные будут осматриваться вокруг себя 
			if (!i || !j || i == HIGH-1 || j == LENGTH-1)
			{
				field[i][j] = new Wall(i,j);
				continue;
			}

			// заселяем поле случайными существами
			int Rand = rand() % 3;
			switch (Rand)
			{
			case 0:
				field[i][j] = new Fox(i, j);
				break;
			case 1:
				field[i][j] = new Rabbit(i, j);
				break;
			case 2:
				field[i][j] = new Empty(i, j);
				break;
			default:
				break;
			}
		}
	}
}

void showField(){
	for (int i = 0; i < HIGH; i++){
		for (int j = 0; j < LENGTH; j++){
			cout << field[i][j]->look();
		}
		cout << endl;
	}

}

void life(){


	// животные осматриваются
	for (int i = 1; i < HIGH-1; i++){
		for (int j = 1; j < LENGTH-1; j++){
			field[i][j]->lookAround();
		}
	}
	// животные делают свои дела
	for (int i = 1; i < HIGH - 1; i++){
		for (int j = 1; j < LENGTH - 1; j++){
			field[i][j]->move();
		}
	}

	system("cls");
	showField();

}







int main(){
	createField();
	showField();
	while (1){
		life();
	}

	return 0;
}
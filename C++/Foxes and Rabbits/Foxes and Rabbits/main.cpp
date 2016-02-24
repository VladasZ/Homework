#include <iostream>
#include <Windows.h>
using namespace std;

#define HIGH 20
#define LENGTH 50
// для вычисления смешения
#define SHIFT_X location.x - 1 + j 
#define SHIFT_Y location.y - 1 + i

#define RABBIT_CHANCE 21
#define FOX_CHANCE 71
struct Location{
	int x = 0;
	int y = 0;
	bool notFound;
	Location(int x, int y) : x(x), y(y){}
	Location(bool i) :notFound(i){}
	Location() : x(0), y(0){};
	void setLoc(int x, int y){
		this->x = x;
		this->y = y;
	}
	void setLoc(Location loc){
		this->x = loc.x;
		this->y = loc.y;
	}
	void show(){
		cout << x << ' ' << y << endl;
	}
};

class Creature;
class Fox;
class Rabbit;
class Empty;

Creature* field[LENGTH][HIGH];

class Creature{
public:
	Creature* neighbors[3][3] = {};
	Location location;
	virtual char look() = 0;
	virtual int move() = 0;
	virtual int getAge() = 0;
	virtual int getChance() = 0;

	Creature(int x, int y){
		location.setLoc(x, y);
		location.notFound = true;
	}

	Creature(Location loc){
		location.setLoc(loc.x, loc.y);
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

	void showNeighbors(){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << neighbors[j][i]->look();
			}
			cout << endl;
		}
	}

	void tellAboutYourself(){
		cout << "Hello! i'm - " << look() << endl;
		cout << "I live here - "; location.show();
		lookAround();
		cout << "My neighbors are:" << endl;
		showNeighbors();
	}

	bool findNeighbor(Location& loc, char look){

		
		
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (neighbors[j][i]->look() == look){

					if (!(rand() % getChance())){
						loc = neighbors[j][i]->location;
						return true;
					}
				}
			}
		}

		return false;
	}

	
};


class Empty :public Creature{
public:
	int age = 0;
	int chance = 1;
	int getChance(){
		return chance;
	}
	int getAge(){
		return age;
	}
	Empty(int x, int y) : Creature(x, y){}

	Empty(Location loc):Creature(loc){}

	char look(){ return ' '; }
	int move(){ return 0; }
};

class Rabbit :public Creature{
public:
	int age = 0;
	int chance = RABBIT_CHANCE;
	int getChance(){
		return chance;
	}
	int getAge(){
		return age;
	}
	Rabbit(int x, int y) : Creature(x, y){}
	Rabbit(Location loc) :Creature(loc){}

	char look(){ return 'R'; }
	int move(){
		lookAround();

		Location target;

		if (findNeighbor(target, 'R'))
		{
			findNeighbor(target, ' ');

			field[target.x][target.y] = new Rabbit(target);
			return 0;
		}


		return 0; }
};




class Wall :public Creature{
public:
	int age = 0;
	int chance = 1;
	int getChance(){
		return chance;
	}
	int getAge(){
		return age;
	}
	Wall(int x, int y) : Creature(x, y){}

	char look(){ return 219; }
	int move(){return 0; }

};


class Fox :public Creature{
public:
	int age = 0;
	int chance = FOX_CHANCE;
	int getChance(){
		return chance;
	}
	int getAge(){
		return age;
	}

	Fox(int x, int y) : Creature(x, y){}
	char look(){ return 'F'; }
	int move(){

		lookAround();

		Location target;

		if (findNeighbor(target, 'R'))
		{
			field[target.x][target.y] = new Empty(target);
			return 0;
		}
		if (findNeighbor(target, ' '))
		{
			field[target.x][target.y] = this;
			field[location.x][location.y] = new Empty(location);
			this->location.setLoc(target);

			return 0;
		}
		
		

		return 0;
	}

};

void createField(){
	for (int i = 0; i < HIGH; i++){
		for (int j = 0; j < LENGTH; j++){


			// создаем стену для того чтобы не выйти за пределы массива когда животные будут осматриваться вокруг себя 
			if (!i || !j || i == HIGH-1 || j == LENGTH-1)
			{
				field[j][i] = new Wall(j,i);
				continue;
			}

			// заселяем поле случайными существами
			int Rand = rand() % 3;
			switch (Rand)
			{
			case 0:
				field[j][i] = new Fox(j, i);
				break;
			case 1:
				field[j][i] = new Rabbit(j, i);
				break;
			case 2:
				field[j][i] = new Empty(j, i);
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
			cout << field[j][i]->look();
		}
		cout << endl;
	}

}

void life(){


	
	// животные делают свои дела
	for (int i = 1; i < HIGH - 1; i++){
		for (int j = 1; j < LENGTH - 1; j++){
			field[j][i]->move();
		}
	}

	system("cls");
	showField();
	//field[3][3]->tellAboutYourself();
	//Sleep(500);

}







int main(){
	createField();

	life();
	while (1){
		life();
	}

	showField();

	field[3][3]->tellAboutYourself();
	field[3][3]->move();





	return 0;
}
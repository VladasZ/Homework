#include <iostream>
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



class Creature{
public:
	Creature* neighbors[3][3];
	Location location;
	virtual char look() = 0;
	virtual void move() = 0;
	virtual int getAge() = 0;

	Creature(int x, int y){
		location.setLoc(x, y);
	}
	Creature(){}
	void lookAround(){
		cout << "i see something!" << endl;
		cout << " i see myself! i'm looks like - " << look() << endl;

		cout << "i'm here: "; location.show();

		cout << " i see my neighbors! they are: " << endl;
	}

};

class Fox :public Creature{
public:
	int age = 0;
	int getAge(){
		return age;
	}

	Fox(int x, int y) : Creature(x, y){}
	char look(){ return 'F';}
	void move(){ cout << "Fox moved" << endl; }
};

class Rabbit :public Creature{
public:
	int age = 0;
	int getAge(){
		return age;
	}
	Rabbit(int x, int y) : Creature(x, y){}

	char look(){ return 'R'; }
	void move(){ cout << "Rabbit moved" << endl; }
};

class Empty :public Creature{
public:
	int age = 0;
	int getAge(){
		return age;
	}
	Empty(int x, int y) : Creature(x, y){}

	char look(){ return ' '; }
	void move(){ cout << "Nothing has moved" << endl; }
};


class Wall :public Creature{
public:
	int age = 0;
	int getAge(){
		return age;
	}
	Wall(int x, int y) : Creature(x, y){}

	char look(){ return 219; }
	void move(){ cout << "Walls can't move!" << endl; }
};


Creature* field[HIGH][LENGTH];

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
	field[5][5]->lookAround();
}







int main(){
	createField();
	showField();
	Location a;

	



	return 0;
}
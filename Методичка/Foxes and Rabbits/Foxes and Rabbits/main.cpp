#include <iostream>
using namespace std;

#define HIGH 20
#define LENGTH 20

class Creature{
public:
	int age;
	virtual char look();
	virtual void move();
};

class Fox :public Creature{
	char look(){ return 'F';}
	void move(){ cout << "Fox moved" << endl; }
};

class Rabbit :public Creature{
	char look(){ return 'R'; }
	void move(){ cout << "Rabbit moved" << endl; }
};

class Empty :public Creature{
	char look(){ return ' '; }
	void move(){ cout << "Nothing has moved" << endl; }
};

Creature* field[HIGH][LENGTH];

void createField(){
	for (int i = 0; i < HIGH; i++){
		for (int j = 0; j < LENGTH; j++){
			int Rand = rand() % 3;
			switch (Rand)
			{
			case 0:
				field[i][j] = new Fox;
				break;
			case 1:
				field[i][j] = new Rabbit;
				break;
			case 2:
				field[i][j] = new Empty;
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







int main(){
	createField();
	showField();

	return 0;
}
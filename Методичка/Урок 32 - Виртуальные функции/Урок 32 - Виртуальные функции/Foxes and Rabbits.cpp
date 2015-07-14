#include <iostream>

using namespace std;

class Creature{
public:
	int age;	
	virtual int look() = 0;
	virtual void move() = 0;
};

class Fox : public Creature{
public:
	int rabbitsEaten;
	int r_look = 1;
	virtual int look(){ return r_look; }
	virtual void move(){};
};

class Rabbit : public Creature{
public:
	int f_look = 2;
	virtual int look(){ return f_look; }
	virtual void move(){};
};

class Grass : public Creature{
public:
	int g_look = 3;
	virtual int look(){ return g_look; }
	virtual void move(){};
};

class Empty : public Creature{
public:
	int e_look = 4;
	virtual int look(){ return e_look; }
	virtual void move(){};
};

class Field{
public:
	Creature* field [50][50];
	Field(){
		for (int i = 0; i < 50; i++){
			for (int j = 0; j < 50; j++){
			int _rand = rand() % 4;
			switch (_rand)
			{
			case 1:
				field[i][j] = new Fox;
			case 2:
				field[i][j] = new Rabbit;
			case 3:
				field[i][j] = new Empty;
			case 4:
				field[i][j] = new Grass;
			default:
				break;
			}
			}
		}
	}
	void show(){
		for (int i = 0; i < 50; i++){
			for (int j = 0; j < 50; j++){
				cout << field[i][j]->look() << endl;
			
			}
		}
	}
};
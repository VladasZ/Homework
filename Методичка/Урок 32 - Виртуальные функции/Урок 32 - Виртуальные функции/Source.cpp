#include <iostream>
#include <vector>
//#include "Employer.cpp"
//#include "List.cpp"
//#include "Square.cpp"
//#include "Foxes and Rabbits.cpp"

#define HIGH 20
#define LENGTH 70



using namespace std;

class Empty;

class Creature{
public:
	vector <Creature*> neighbors;
	int age;
	virtual char look() = 0;
	virtual void move(int x, int y) = 0;
};

Creature* afield[HIGH][LENGTH];

vector <Creature*> lookAround(int x, int y)
{
	vector <Creature*> neighbors(8);
	int i = 0;

	for (int j = x - 1; j < x + 1; j++){
		for (int t = y - 1; t < x + 1; t++){
			//if (j == x && t == x) x++;
			neighbors[i++] = afield[x][y];
		}
	}

	//cout << neighbors[3]->look() << endl;
	

	return neighbors;
}

class Fox : public Creature{
public:
	vector <Creature*> neighbors;
	int rabbitsEaten;

	virtual char look(){ return 'F'; }
	virtual void move(int x, int y){};
};

class Rabbit : public Creature{
public:
	vector <Creature*> neighbors;
	virtual char look(){ return 'R'; }
	virtual void move(int x, int y)
	{
		neighbors = lookAround(x, y);

	};
};

class Grass : public Creature{
public:
	vector <Creature*> neighbors;
	virtual char look(){ return 'G'; }
	virtual void move(int x, int y)
	{
		neighbors = lookAround(x, y);

	};
};

class Empty : public Creature{
public:
	vector <Creature*> neighbors;
	virtual char look(){ return '-'; }
	virtual void move(int x, int y)
	{
		neighbors = lookAround(x, y);

	};
};

class Field{
public:

	Field(){
		for (int i = 0; i < HIGH; i++){
			for (int j = 0; j < LENGTH; j++){
				int _rand = rand() % 4;
				switch (_rand)
				{
				case 0:
					afield[i][j] = new Fox;
					break;
				case 1:
					afield[i][j] = new Rabbit;
					break;
				case 2:
					afield[i][j] = new Empty;
					break;
				case 3:
					afield[i][j] = new Grass;
					break;
				default:
					break;
				}
			}
		}
	}
	void show(){
		system("cls");
		for (int i = 0; i < HIGH; i++){
			for (int j = 0; j < LENGTH; j++){

				cout << afield[i][j]->look();

			}
			cout << endl;
		}
	}

	void move(){
		for (int i = 1; i < HIGH - 1; i++){
			for (int j = 1; j < LENGTH - 1; j++){

				afield[i][j]->move(i, j);

			}

		}
	}
};

int main(){

	//Ñîòðóäíèêè
	
	Employer* president = new President;
	Employer* manager = new Manager;
	Employer* worker = new Worker;
	

	president->print();
	manager->print();
	worker->print();

	cout << endl;

	// Î÷åðåäü è ñòåê

	List* a = new Queue;
	List* b = new Stack;

	a->push(3);
	a->push(2);
				
	cout << a->pull() << endl;
	
	a->show();

	cout << endl;
	
	b->push(3);
	b->push(7);

	cout << b->pull() << endl;

	b->show();

	cout << endl;

	// Ïëîùàäè ôèãóð

	Square* rectangle = new Rectangle(10, 15);
	Square* circle = new Circle(7);
	Square* rightTriangle = new RightTriangle(3, 6);
	Square* trapeze = new Trapeze(10, 18, 13);

	cout << "Square of rectangle = " << rectangle->square() << endl;
	cout << "Square of circle = " << circle->square() << endl;
	cout << "Square of rightTriangle = " << rightTriangle->square() << endl;
	cout << "Square of trapeze = " << trapeze->square() << endl;


	Field a;

	a.show();




	afield[5][5]->move(5, 5);

	vector <Creature*> neighbors(8);

	neighbors = lookAround(5, 5);



	//cout << neighbors[3]->look() << endl;



	for(int i = 0; i < 4; i++){
		cout << neighbors[i]->look() << endl;
	}


	return 0;
}

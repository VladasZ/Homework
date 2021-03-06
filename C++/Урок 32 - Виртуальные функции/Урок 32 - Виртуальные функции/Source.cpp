#include <iostream>
#include <vector>
#include "Employer.cpp"
#include "List.cpp"
#include "Square.cpp"


using namespace std;

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




	

	return 0;
}

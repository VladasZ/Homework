#include <iostream>
#include "Field.h"
#include "Creature.h"

using namespace std;


int main(){
	Creature* fox = new Fox;

	Creature* rabbit = new Rabbit;
	

	rabbit->addRabbitsEatem();


	cout << rabbit->getRabbitsEaten() << endl;


	return 0;
}
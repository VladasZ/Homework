#pragma once
#include "Creature.h"
class Fox :
	public Creature
{
public:
	int rabbitsEaten = 0;
	int getRabbitsEaten();
	void addRabbitsEatem();
	Fox();
	~Fox();
};


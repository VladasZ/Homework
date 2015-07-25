#pragma once
#include "Fox.h"
#include "Rabbit.h"
class Creature
{
public:
	int age = 0;
	Creature();
	virtual int getRabbitsEaten();
	virtual void addRabbitsEatem();
	~Creature();
};


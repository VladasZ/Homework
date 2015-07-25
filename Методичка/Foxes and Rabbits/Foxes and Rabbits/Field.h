#pragma once
#include "Creature.h"

#define HIGH 20
#define LENGTH 20


class Field
{
	Creature* field[HIGH][LENGTH];
public:
	Field();
	~Field();
};


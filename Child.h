#pragma once
#include "Person.h"


class Child : public Person
{
public:
	// CONSTRUCTORS
	Child(string name, int ID, int fatherID, int motherID);
	Child(string info_in);
	~Child();

	// MUTATORS

	// EXPORTERS
	string toString();

	// ANALYZERS
	int getFatherID();
	int getMotherID();

protected:
	// DATA
	int fatherID;
	int motherID;
};
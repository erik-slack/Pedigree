#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;


class Person
{
public:
	// CONSTRUCTORS
	Person(string name, int ID);
	Person(string info_in);
	~Person();

	// MUTATORS
	virtual bool blankFunction();

	// EXPORTERS
	virtual string toString();

	// ANALYZERS
	string getName();
	int getID();
	bool isChild();
	virtual int getFatherID();
	virtual int getMotherID();

protected:
	// DATA
	string name;
	int ID;
	bool child_status;
};
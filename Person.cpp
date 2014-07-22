#include "Person.h"


// CONSTRUCTORS
Person::Person(string name_choice, int ID_in)
{
	name = name_choice;
	ID = ID_in;
	child_status = false;
}

Person::Person(string info_in)
{
	cout << info_in << endl;
	istringstream input_ss;
	input_ss.str(info_in);

	string person, ID_string;
	input_ss >> person >> ID_string >> name;
	ID = atoi(ID_string.c_str());
}

Person::~Person() {}

// MUTATORS
bool Person::blankFunction()
{
	return false;
}

// EXPORTERS
string Person::toString()
{
	stringstream ss;
	ss << "Person ";
	ss << ID << " ";
	ss << name;
		
	return ss.str();
}

// ANALYZERS
string Person::getName()
{
	return name; // Returns the name of this Person.
}

int Person::getID()
{
	return ID; // Returns the ID of this person.
}

bool Person::isChild()
{
	return child_status;
}

int Person::getFatherID()
{
	return 0;
}

int Person::getMotherID()
{
	return 0;
}
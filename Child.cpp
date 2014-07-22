#include "Child.h"


// CONSTRUCTORS
Child::Child(string name_extract, int ID_extract, int fatherID_in, int motherID_in):Person(name_extract, ID_extract)
{
	name = name_extract;
	ID = ID_extract;
	child_status = true;
	fatherID = fatherID_in;
	motherID = motherID_in;
}

Child::Child(string info_in):Person(info_in)
{
	//cout << info_in << endl;
	istringstream input_ss;
	input_ss.str(info_in);

	string child, ID_string, father_ID_string, mother_ID_string;

	input_ss >> child >> ID_string >> father_ID_string >> mother_ID_string >> name;

	ID = atoi(ID_string.c_str());
	fatherID = atoi(father_ID_string.c_str());
	cout << "Child.cpp ID: " << ID << endl;
	motherID = atoi(mother_ID_string.c_str());
}

Child::~Child() {}

// MUTATORS

// EXPORTERS

string Child::toString()
{
	stringstream ss;
	ss << "Child ";
	ss << ID << " ";
	ss << fatherID << " ";
	ss << motherID << " ";
	ss << name;
		
	return ss.str();
}

// ANALYZERS

int Child::getFatherID()
{
	return fatherID; // Returns the ID of this Child's Father.
}

int Child::getMotherID()
{
	return motherID; // Returns the ID of this Child's Mother.
}
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Person.h"
#include "Child.h"
using namespace std;

class Pedigree
{
public:
// CONSTRUCTORS
	Pedigree();
	~Pedigree();

// MUTATORS
	virtual bool addPerson(string name_choice);
	virtual bool removePerson(string name_choice);
	void addChild(Person* person_pointer, int fatherID_in, int motherID_in);

// IMPORTERS
	void loadPedigree_new();
	void loadPedigree();

// EXPORTERS
	void savePedigree();

// ANALYZERS
	/*bool name_checker(string name_choice);*/
	Person* getPerson_byID(int parent_ID);
	virtual Person* getPerson_byName(string name_choice);
	string get_parentName(int ID_out);
	void recursive_sort(Person* person_selector, int dash_count);
	//void recursive_print(int all_people_size);
	/*void showAll_People();*/
	int getSize();

private:
// DATA
	vector<Person*> all_people;
};
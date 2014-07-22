#include "Pedigree.h"

// CONSTRUCTORS
Pedigree::Pedigree() {}

Pedigree::~Pedigree() {}

// MUTATORS

// Used to add a new person--without parent ID's attached--to all_people.
bool Pedigree::addPerson(string name_choice)
{
	// Adds a new Person to the collection of People in the Pedigree.
	bool is_duplicate = false;
	bool has_failed = false;
	
	string name_in = name_choice;
	int ID_in = getSize();

	//is_duplicate = name_checker(name_in); //Do not allow duplicate names.

	/*if (is_duplicate == false)
	{*/
		Person* this_person = new Person(name_choice, ID_in);
		all_people.push_back(this_person);
		cout << "Person " << this_person->getID() << " - " << this_person->getName() << " Accepted." << endl;
		return true;
	//}
	//else
	//{
	//	cout << "Person Rejected." << endl;
	//	return false; // Reject any string that does not adhere to the format outlined in the test specs.
	//}
}

// Part of addChild member function.  Removes a Person object from the all_people vector.
bool Pedigree::removePerson(string name_choice)
{
	bool was_removed = false; // Does nothing if no Person is found with the given name.

	for (int i = 0; i < all_people.size(); i++)
	{
		if (name_choice == all_people[i]->getName()) 
		{
			all_people.erase(all_people.begin() + i); // Removes the Person whose name is equal to the given name.
			was_removed = true; // Return true if a Person is removed; false otherwise.
		}
	}

	return was_removed;
}

// IMPORTERS

//void Pedigree::loadPedigree_new()
//{
//	ifstream in_file;
//	string file_choice = "";
//	cout << "File name to load (file_name.txt): \t";
//	cin >> file_choice;
//	in_file.open(file_choice);
//	string info_in = "";
//
//	do
//	{
//		if (info_in.substr(0, 5) == "Child")
//		{
//			Child* loaded_child = new Child(info_in);
//			all_people.push_back(loaded_child);
//		}
//		else if (info_in.substr(0, 6) == "Person")
//		{
//			Person* loaded_person = new Person(info_in);
//			all_people.push_back(loaded_person);
//		}		
//	}
//	while (getline(in_file, info_in));
//
//	if (in_file.fail()) 
//	{
//		return;
//	}
//	
//	cout << endl;
//}

void Pedigree::loadPedigree()
{
	string status_in = "";
	string name_in = "";
	int id_in = 0;
	int fatherID_in = 0;
	int motherID_in = 0;
	
	ifstream in_file;
	string file_choice = "";
	cout << "File name to load (file_name.txt): \t";
	cin >> file_choice;
	in_file.open(file_choice);
	
	if (in_file.fail())
	{
		cout << "That file is non-existant." << endl;
		return;
	}

	do
	{
		in_file >> status_in >> id_in;
		if(status_in == "Child")
		{
			in_file >> fatherID_in >> motherID_in;
		}

		in_file >> name_in;

		if (status_in == "Child")
		{
			Child* loaded_child = new Child(name_in, id_in, fatherID_in, motherID_in);
			cout << loaded_child->getName() << " " << loaded_child->getID() << " " << loaded_child->getFatherID() << " " << loaded_child->getMotherID() << endl;
			all_people.push_back(loaded_child);
		}
		else
		{
			Person* loaded_person = new Person(name_in, id_in);
			cout << loaded_person->getName() << " " << loaded_person->getID() << endl;
			all_people.push_back(loaded_person);
		}
	}
	while (getline(in_file, file_choice));

	if (in_file.fail()) 
	{
		return;
	}	
	cout << endl;
}

// EXPORTERS

void Pedigree::savePedigree()
{
	string save_file = "";
	cout << "Save file as (file_name.txt): \t";
	cin >> save_file;
	ofstream out_file;
	out_file.open(save_file);
	if (out_file.fail()) 
	{
		return;
	}
	for (int i = 0; i < getSize(); i++)
	{
		Person* next_person = getPerson_byID(i);
		string data = next_person->toString();
		out_file << data;
		if (i != getSize() - 1)
		{
			out_file << endl;
		}
	}
	//start a new line at the end of the row
}

// ANALYZERS

// Useful to prohibit people from having the same name.
//bool Pedigree::name_checker(string name_value)
//{
//	bool is_copy = false;
//
//	for (int i = 0; i < all_people.size() ; i++)
//	{
//		if (name_value == all_people[i]->getName()) 
//		{ 
//			is_copy = true; 
//		}
//	}
//
//	return is_copy;
//}

// Used by get_parentName member function. Finds a person in the vector all_people that has the unique ID passed as a parameter--an integer.
Person* Pedigree::getPerson_byID(int parent_ID)
{
	Person* memory_location = NULL; // Returns NULL if no Person is found with the given name.
	bool test = false;
	for (int i = 0; i < all_people.size(); i++)
	{
		if (parent_ID == all_people[i]->getID() ) 
		{
			memory_location = all_people[i]; // Return a memory address if a Person is found; NULL otherwise.
			test = true;
		}
	}
	
	if (test = false)
	{
		cout << "Error, that ID does not exist, please enter another ID ";
		return 0;
	}
	return memory_location;
}

// Used by the main function. Finds a person in the vector all_people that has the name passed as a parameter--a string.
Person* Pedigree::getPerson_byName(string name_choice)
{
	Person* memory_location = NULL; // Returns NULL if no Person is found with the given name.

	for (int i = 0; i < all_people.size(); i++)
	{
		if (name_choice == all_people[i]->getName() ) 
		{
			memory_location = all_people[i]; // Return a memory address if a Person is found; NULL otherwise.
		}
	}

	return memory_location;
}

string Pedigree::get_parentName(int parent_ID)
{
	string parent_name;

	Person* parent_location = getPerson_byID(parent_ID);
	parent_name = parent_location->getName();

	return parent_name;
}

void Pedigree::recursive_sort(Person* person_selector, int dash_count) // use a second vector of pointers and pop them out as you go
{
	if (person_selector->getID() < 0 || person_selector->getID() == all_people.size()){return;}
	dash_count++;

	int ID_out = person_selector->getID();
	string name_out = person_selector->getName();
	
	cout << name_out << " " << ID_out << endl;

	if (person_selector->isChild() == true)
	{
		int fatherID_out = 0;
		fatherID_out = person_selector->getFatherID();
		//cout << fatherID_out << " " << get_parentName(fatherID_out);

		int motherID_out = 0;
		motherID_out = person_selector->getMotherID();
		//cout << " and " << motherID_out << " " << get_parentName(motherID_out) ;

		for(int i = dash_count; i > 0; i--)
		{
			cout << "-";
		}

		person_selector = getPerson_byID(fatherID_out);
		recursive_sort(person_selector, dash_count);

		for(int i = dash_count; i > 0; i--)
		{
			cout << "-";
		}

		person_selector = getPerson_byID(motherID_out);
		recursive_sort(person_selector, dash_count);
	}
	//else
	//{
	//	cout << "NONE WERE SUBMITTED YET.";
	//}
	//cout << endl;
}

// Recursive Way to Show All People - This function not sorted
//void Pedigree::recursive_print(int person_id)
//{
//	if (person_id < 0 || person_id == all_people.size()){return;}
//
//	string name_out = all_people[person_id]->getName();
//	int ID_out = all_people[person_id]->getID();
//
//	cout << "ID: " << ID_out << " - " << name_out << " - Parents: ";
//	if (all_people[person_id]->isChild() == true)
//	{
//		int fatherID_out = 0;
//		fatherID_out = all_people[person_id]->getFatherID();
//		cout << get_parentName(fatherID_out);
//
//		int motherID_out = 0;
//		motherID_out = all_people[person_id]->getMotherID();
//		cout << " and " << get_parentName(motherID_out);
//	}
//	else
//	{
//		cout << "NONE WERE SUBMITTED YET.";
//	}
//	cout << endl;
//
//	int next_person_id = person_id + 1;
//	recursive_print(next_person_id);
//}

// Iteration Way to Show All People
//void Pedigree::showAll_People()
//{
//	for (int i = 0; i < (all_people).size(); i++)
//	{
//		string name_out = all_people[i]->getName();
//		int ID_out = all_people[i]->getID();
//
//		cout << "ID: " << ID_out << " - " << name_out << " - Parents: ";
//		if (all_people[i]->isChild() == true)
//		{
//			int fatherID_out = 0;
//			fatherID_out = all_people[i]->getFatherID();
//			cout << get_parentName(fatherID_out);
//
//			int motherID_out = 0;
//			motherID_out = all_people[i]->getMotherID();
//			cout << " and " << get_parentName(motherID_out);
//		}
//		else
//		{
//			cout << "NONE WERE SUBMITTED YET.";
//		}
//		cout << endl;
//	}
//}

// Takes the name and ID of a person and creates a new Child and attaches the ID # of the father and mother Person to that Child.
void Pedigree::addChild(Person* person_pointer, int fatherID_in, int motherID_in)
{
	string name_extract = "";
	int ID_extract = 0;

	name_extract = (*person_pointer).getName();
	ID_extract = (*person_pointer).getID();

	Person* this_child = new Child(name_extract, ID_extract, fatherID_in, motherID_in);
	//cout << "father ID: " << fatherID_in << " mother ID: " << motherID_in << endl;
	removePerson(name_extract);
	all_people.push_back(this_child);
	cout << "Person Successfully Converted to Child." << endl;
	
	return;
}
		
int Pedigree::getSize()
{
	return all_people.size(); // Returns the number of People in the Pedigree. Return a non-negative integer.
}
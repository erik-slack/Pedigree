#include <iostream>
#include "Pedigree.h"
using namespace std;

void main_menu(Pedigree pedigree1)	
{
	bool repeat_checker = true;
	while (repeat_checker == true)
	{
		string name_choice = "";
		cout << "Erik's Pedigree Application" << endl;
		cout << "1 - Print Tree \n2 - Add Parents to Person \n3 - Save File \n4 - Load File \n5 - Quit" << endl;
		cout << "What would you like to do? \t";
		int menu_choice = 0;
		cin >> menu_choice;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Try again Foo...a number this time.";
			cin >> menu_choice;
		}

		if (menu_choice == 1)  // Print Tree
		{
			cout << "You chose menu choice " << menu_choice << endl;
			
			/* Iteration Solution - Functioning
			cout << pedigree1.getSize() << endl;
			pedigree1.showAll_People();*/
			
			
			/* Recursion Solution - Functioning, but not in order*/
			int dash_count = 0;
			Person* person_selector = pedigree1.getPerson_byID(0);
			pedigree1.recursive_sort(person_selector, dash_count);
			

		}

		/*else if (menu_choice == 2) // Add Person
		{
			cout << "You chose menu choice " << menu_choice << endl;
			cout << "What is the full name of the person you are adding?" << endl;
			
			while (name_choice == "")
			{
				getline(cin, name_choice);
			}
			pedigree1.addPerson(name_choice);
		}
		*/
		else if (menu_choice == 2) // Converts Person to Child, Adds 2 new People which are assigned as that Child's Parents
		{
			cout << "You chose menu choice " << menu_choice << endl;

			// GET CHILD NAME
			int ID_child;
			cout << "Who would you like to add information for? (ID #)" << endl;
			cin >> ID_child;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Try again Foo...a number this time.";
				cin >> ID_child;
			}
			if (ID_child >= pedigree1.getSize() || ID_child < 0)
			{
				cout << "Error, that ID does not exist, please enter another ID ";
			}
			else
			{
				Person* person_pointer;
				person_pointer = pedigree1.getPerson_byID(ID_child);

				if (person_pointer->isChild())
				{
					cout << "This person already has parents...this is BYU, Polygamy is a sin...Sinner." << endl;
				}
				else
				{
					cout << "What is this child's father's name?" << endl;
					name_choice = "";
					while (name_choice == "")
					{
						getline(cin, name_choice);
					}

					int fatherID_in = pedigree1.getSize();
				
					pedigree1.addPerson(name_choice);
			
					cout << "What is this child's mother's name?" << endl;
					name_choice = "";
					while (name_choice == "")
					{
						getline(cin, name_choice);
					}

					int motherID_in = pedigree1.getSize();

					pedigree1.addPerson(name_choice);

					pedigree1.addChild(person_pointer, fatherID_in, motherID_in);
				}
			}
		}

		else if (menu_choice == 3) // Save File
		{
			cout << "You chose menu choice " << menu_choice << endl;
			pedigree1.savePedigree();
		}
		else if (menu_choice == 4) // Load File
		{
			cout << "You chose menu choice " << menu_choice << endl;
			pedigree1.loadPedigree();
			//pedigree1.loadPedigree_new();
		}
		else if (menu_choice == 5) // Quit
		{
			cout << "You chose menu choice " << menu_choice << endl;
			cout << "The application has been terminated.  Goodbye." << endl;
			repeat_checker = false;
		}

		else // INPUT VALIDATION
		{
			cout << endl;
			cout << "That is not a valid response to the question. \n" << endl;
		}
		cout << "\n" << endl;
	}
}

int main()
{
	Pedigree pedigree1;
	string name_choice;
	cout << "What is the full name of the person you are adding?" << endl;
			
			while (name_choice == "")
			{
				getline(cin, name_choice);
			}
			pedigree1.addPerson(name_choice);
	main_menu(pedigree1);
	
	system ("pause");
	return 0;
}
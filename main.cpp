#include <iostream>
#include "GPU.h"
#include "BoardDesign.h"

using namespace std;

int mainMenu();
void selection(int option);


int main()
{
	//test of show info
	//constructor includes GPU and BoardDesign, other classes have not been connected to GPU
	GPU test = GPU("RX 570", "2017 Q3", 354, 2.0, 200, "HDMI x1, Display Prot x3, DVI x1", "8 pin x1", 50, 30, 10);
	test.showInfo();



	cout << "\n\n###---Welcome to GPU Database---###\n";
	while (mainMenu())
	{
	}

}

int mainMenu()
{
	int option;
	cout << "Choose a option to contiune\n";
	cout << "1. Add a new graphics card to the database\n";
	cout << "2. Delete a grahics card from the list\n";
	cout << "3. Open the view GPU menu\n";
	cout << "4. Close the Program\nOption: ";

	cin >> option;
	cout << endl;

	if (option > 4 || option < 1)
	{
		cout << "Error reading input, please try again\n";
		return mainMenu();
	}
	else if (option == 4)
		return 0;
	else if (option == 3)
	{
		cout << "\n\n\nChoose a option to contiune\n";
		cout << "1. Search for a specific graphics card by name\n";
		cout << "2. View graphics cards by architecture\n";
		cout << "3. View graphics cards by generation\n";
		cout << "4. View all graphics cards\n";
		cout << "5. Go back\nOption: ";
		cin >> option;
		cout << endl;

		if (option > 5 || option < 1)
		{
			cout << "Error reading input, please try again\n";
			return mainMenu();
		}
		else if (option == 5)
			return mainMenu();
		else
			option += 3;
	}

	selection(option);
}

void selection(int option)
{
	switch(option)
	{
		case 1: //adding to list
		{
			cout << "Adding to list\n";
			break;
		}
		case 2: //deleteing from the list
		{
			cout << "Deleting to list\n";
			break;
		}
		case 3: //something has gone wrong, should never execute
		{
			cout << "Critical error encountred. You shouldnt be here..." << endl;
			cout << "\nCongratulations! The simple fact that you're standing here listening to me means you've made a glorious contribution to science.";
			cout << "As founder and CEO of Aperture Science, I thank you for your participation and hope we can count on you for another round of tests";
			break;
		}
		case 4: //search list
		{
			cout << "Searching list\n";
			break;
		}
		case 5: //view by arch
		{
			cout << "Viewing database by arch\n";
			break;
		}
		case 6: //view by gen
		{
			cout << "Viewing by gen\n";
			break;
		}
		case 7: //view all
		{
			cout << "Viewing all\n";
			break;
		}
		default:
			cout << "Critical error encoutred. You shouldnt be here...";
	}
}
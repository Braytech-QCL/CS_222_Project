#include <iostream>
#include <istream>
#include <string>
#include "GPU.h"
#include "BoardDesign.h"
#include "LinkedList.h"

using namespace std;

LinkedList<GPU> GPUDatabaseList;

int mainMenu();
void selection(int option);
void searchList();
void populateList();
void addList();


int main()
{
	//test of show info
	//constructor includes GPU and BoardDesign, other classes have not been connected to GPU
	GPU test = GPU("RX 570", "2017 Q3", 354, 2.0, 200, "HDMI x1, Display Prot x3, DVI x1", "8 pin x1", 50, 30, 10);
	test.showInfo();
	cout << endl;

	GPUDatabaseList.appendNodeFront(test);

	populateList();
	GPUDatabaseList.print();


	cout << "\n\n###---Welcome to GPU Database---###\n";
	cout << GPUDatabaseList.size() << " GPU(s) have been loaded into the system\n\n";
	while (mainMenu())
	{
	}

}

/// <Displays menu for user to decide what they want the program to do>
/// 
/// Precondition: Function called from main
/// Postcondition: Selection function called, user input sent
/// 
/// </summary>
/// <returns></The users choice, what they want the program to do>
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
    return 0;
}

/// <Uses a input from a user and directs them to the appropriate function>
/// 
/// </summary>
/// <param name="option"></Number chosen by user corresponding to what they wan the program to do>
void selection(int option)
{
	switch(option)
	{
		case 1: //adding to list
		{
			cout << "Adding to list\n";
			addList();
			break;
		}
		case 2: //deleteing from the list
		{
			deleteItem();
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
			searchList();

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
			GPUDatabaseList.print();
			break;
		}
		default:
			cout << "Critical error encoutred. You shouldnt be here...";
	}
}

/// <Function allows user to enter the name of a gpu to see if it is present in list>
/// 
/// </summary>
void searchList()
{
	string gpuSearch = "";
	GPU test;

	cin.ignore();
	cout << "What GPU would you like to search for?" << endl;
	getline(cin, gpuSearch);

	GPUDatabaseList.search(test, gpuSearch);

	mainMenu();
}

//GPU::GPU(string _name, string _releaseDate, int _MSRP, double slotW, int tdp, string output,
//string powerCon, double len, double wid, double hei, int baseC, int boostC, string busI,
//int dieS, int trans, int processorS, int memoryS,
//int memoryG, int memoryB, int memoryC)
void populateList()
{
	GPU test2 = GPU("NVIDIA GeForce RTX 2080 Ti 12 GB", "2019 Q4 ", 999, 2, 250, "HDMI / 3x DisplayPort 1.4a / USB Type - C", "2x 8 - pin", 267, 116, 35, 1410, 1650,    "PCIe 3.0 x16", 754, 18600, 12, 12, 6, 384, 2000);
	GPU test3 = GPU("NVIDIA GeForce RTX 3070", "2020 Q3", 499, 2, 220, "HDMI 2.1 / 3x DisplayPort1.4a", "1x 12 - pin", 242, 112, 35, 1500, 1725, "PCIe4.0 x16", 392, 17400, 8, 8, 6, 256, 1750);
	GPU test4 = GPU("NVIDIA GeForce GTX 1050", "2016 Q4", 109, 2, 75, "DVI / HDMI / DisplayPort 1.4a", "None", 145, 111, 35, 1354, 1455, "PCIe 3.0 x16", 132, 3300, 14, 2, 5, 128, 1752);
	GPU test5 = GPU("NVIDIA GeForce RTX 4080", "2022 Q4", 1200, 3, 320, "HDMI 2.1 / DisplayPort1.4a", "1 x 16-pin", 310, 140, 61, 2205, 2505, "PCIe4.0 x16", 379, 45900, 4, 16, 40, 256, 1400);

	//The follwoing GPUs dont exist, only using for testing purposes
	GPU test6 = GPU("AMD Radeon RX 5700 XT", "2019", 399, 2, 225, "HDMI 2.0b / DisplayPort 1.4", "1x 8-pin / 1x 6-pin", 240, 110, 0, 1605, 1905, "PCIe 4.0 x16", 251, 10300, 7, 8, 57, 256, 16000);
	GPU test7 = GPU("Intel Iris Xe Max Graphics", "2020", 199, 1, 28, "HDMI 2.0b / DisplayPort 1.4", "N/A", 135, 95, 0, 1200, 1500, "PCIe 4.0 x8", 123, 940, 10, 4, 6, 128, 1000);
	GPU test8 = GPU("AMD Radeon Pro W5700X", "2020", 699, 2, 230, "HDMI 2.1 / DisplayPort 1.4", "2x 8-pin", 240, 130, 0, 1605, 1905, "PCIe 4.0 x16", 251, 10300, 7, 8, 57, 256, 16000);
	GPU test9 = GPU("NVIDIA GeForce GTX 1660", "2019", 219, 2, 120, "DVI / HDMI / DisplayPort 1.4a", "1x 6-pin", 175, 111, 0, 1530, 1785, "PCIe 3.0 x16", 192, 6300, 12, 6, 16, 192, 14000);
	GPU test10 = GPU("AMD Radeon RX 6800", "2020", 649, 2, 250, "HDMI 2.1 / DisplayPort 1.4", "2x 8-pin", 240, 110, 0, 1800, 2105, "PCIe 4.0 x16", 251, 10300, 7, 16, 68, 256, 16000);
	GPU test11 = GPU("Intel Iris Xe Graphics", "2020", 99, 1, 28, "HDMI 2.0b / DisplayPort 1.4", "N/A", 135, 95, 0, 1200, 1500, "PCIe 4.0 x8", 123, 940, 10, 4, 0, 64, 1000);
	GPU test12 = GPU("AMD Radeon Pro W5700", "2020", 599, 2, 230, "HDMI 2.1 / DisplayPort 1.4", "2x 8-pin", 240, 130, 0, 1605, 1905, "PCIe 4.0 x16", 251, 10300, 7, 8, 57, 256, 16000);
	GPU test13 = GPU("NVIDIA GeForce RTX 2060 Super", "2019", 399, 2, 175, "DVI / HDMI / DisplayPort 1.4a", "1x 8-pin", 175, 111, 0, 1470, 1650, "PCIe 3.0 x16", 192, 6300, 12, 8, 20, 256, 14000);

	GPUDatabaseList.appendNodeFront(test2);
	GPUDatabaseList.appendNodeFront(test3);
	GPUDatabaseList.appendNodeFront(test4);
	GPUDatabaseList.appendNodeFront(test5);

	//generated demo gpus
	GPUDatabaseList.appendNodeFront(test5);
	GPUDatabaseList.appendNodeFront(test6);
	GPUDatabaseList.appendNodeFront(test7);
	GPUDatabaseList.appendNodeFront(test8);
	GPUDatabaseList.appendNodeFront(test9);
	GPUDatabaseList.appendNodeFront(test10);
	GPUDatabaseList.appendNodeFront(test11);
	GPUDatabaseList.appendNodeFront(test12);
	GPUDatabaseList.appendNodeFront(test13);
}

/// <Allows user to add GPU to database>
/// 
/// Precondition: Function was called from selection function
/// Postcondition: GPU added to list
/// 
/// </summary>
void addList()
{
	//vars used to define GPU obj by user
	string name, reDate;
	int msrp;

	int option;
	cout << "\n\n\nChoose a option to contiune\n";
	cout << "1. Add a GPU to the list with minimal specification \n";
	cout << "2. Add a GPU to the list with full specification\nChoice:";
	cin >> option;
	cout << endl;

	if (option == 1)
	{
		GPU temp = GPU();
		cin.ignore();
		cout << "\nEnter the name of the GPU you would like to enter\n";
		getline(cin, name);
		temp.setName(name);

		cout << "\nEnter the release date of the GPU (year/quater format, 20XX QX)\n";
		cin >> reDate;
		getline(cin, reDate);
		temp.setReleaseDate(reDate);

		cout << "\nEnter the suggested price, or MSRP, of the GPU\n";
		cin >> msrp;
		temp.setMSRP(msrp);

		GPUDatabaseList.appendNodeFront(temp);
		cout << "GPU added to list.\n\n";
	}
	else if (option == 2)
	{
		cout << "Why do you hate your self?";
	}
	else
	{
		cout << "Error reading input, please try again\n";
		return addList();
	}

	mainMenu();
}

void deleteItem(){
    string gpuToDelete = "";
    GPU test;

    cin.ignore();
    cout << "What GPU would you like to search for?" << endl;
    getline(cin, gpuToDelete);

    GPUDatabaseList.deleteItem(test, gpuToDelete);
    cout<< GPUDatabaseList.size()<<" GPU's Loaded into Database"<<endl;
    mainMenu();
    
    
}

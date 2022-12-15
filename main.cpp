/**
This code is a driver program for a GPU database. 
The program uses the LinkedList class to store GPU objects and allows users to perform various actions on the list, 
such as adding and deleting items, searching for specific items, and viewing the list in different ways.

The program begins by creating a GPU object and adding it to the linked list. Then it calls the populateList function, 
which populates the linked list with additional GPU objects. After this, the program displays a menu to the user and waits for them to make a selection. 
Depending on the user's input, the program will perform different actions, 
such as adding a new GPU object to the list, deleting an existing object, or searching the list in various ways.

@author ConnorMcGill ElbertEsquea

*/

#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include "GPU.h"
#include "BoardDesign.h"
#include "LinkedList.h"


using namespace std;

LinkedList<GPU> GPUDatabaseList; //A database of GPUs, where each GPU is represented by an object of type GPU

int mainMenu(); // This function displays the main menu and prompts the user to select an option. It returns the user's selected option as an integer.
void selection(int option); //This function takes in an integer representing the user's selected option from the main menu. It then calls the appropriate function for the selected option.
void searchList(); //This function allows the user to search for a GPU in the database by its name.
void populateList(); //This function populates the database with a pre-defined list of GPUs.
void addList(); // This function allows the user to add a new GPU to the database.
void deleteItem(); //This function allows the user to delete a GPU from the database.

void viewByArch(); //This function displays the GPUs in the database sorted by their architecture.
void viewByGen(); //This function displays the GPUs in the database sorted by their generation.
void viewByBrand(); //This function displays the GPUs in the database sorted by their brand.


int main()
{


	populateList(); //fills database with GPUs for demoing purposes. Reading from a file for this was not possible

	cout << "\n\n###---Welcome to GPU Database---###\n";
	cout << GPUDatabaseList.size() << " GPU(s) have been loaded into the system\n\n";
	while (mainMenu()) //will repeat until user exits, allows for more fluid functionality
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
		cout << "4. View graphics cards by manufacturer\n";
		cout << "5. View all graphics cards\n";
		cout << "6. Go back\nOption: ";
		cin >> option;
		cout << endl;

		if (option > 6 || option < 1)
		{
			cout << "Error reading input, please try again\n";
			return mainMenu();
		}
		else if (option == 6)
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
			cout << "Searching list...\n";
			searchList();

			break;
		}
		case 5: //view by arch
		{
			cout << "Viewing database by arch\n";
			viewByArch();
			break;
		}
		case 6: //view by gen
		{
			cout << "Viewing by gen\n";
			viewByGen();
			break;
		}
		case 7: //view by brand
		{
			cout << "Viewing by Manufacturer\n";
			viewByBrand();
			break;
		}
		case 8: //view all
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
	GPU card1 = GPU("NVIDIA GeForce GTX 1080", 2016, 499, 2, 180, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 267, 111, 41, 1607, 1733, "PCIe 3.0 x16", 314, 7200, 16, 8, 8, 256, 10000, "Nvidia", "Pascal", "GeForce10series");
	GPU card2 = GPU("NVIDIA GeForce GTX 1070", 2016, 379, 2, 150, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 277, 111, 40, 1506, 1683, "PCIe 3.0 x16", 314, 7200, 16, 8, 8, 256, 8000);
	GPU card3 = GPU("NVIDIA GeForce GTX 1060", 2016, 249, 2, 120, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 229, 111, 40, 1506, 1708, "PCIe 3.0 x16", 200, 4400, 16, 6, 6, 192, 8000);
	GPU card4 = GPU("AMD Radeon RX 5700 XT", 2019, 399, 2, 225, "HDMI 2.0b / DisplayPort 1.4 with DSC", "2x 8-pin", 240, 132, 46, 1605, 1905, "PCIe 4.0 x16", 251, 10300, 7, 8, 36, 256, 14000);
	GPU card5 = GPU("AMD Radeon RX 5700", 2019, 349, 2, 180, "HDMI 2.0b / DisplayPort 1.4 with DSC", "8-pin", 240, 132, 46, 1465, 1725, "PCIe 4.0 x16", 251, 10300, 7, 8, 36, 256, 14000);
	GPU card6 = GPU("AMD Radeon RX Vega 64", 2017, 499, 2, 295, "HDMI 2.0 / DisplayPort 1.4 HBR3 / DisplayPort 1.4 HDR", "2x 8-pin", 295, 210, 48, 1247, 1546, "PCIe 3.0 x16", 495, 12500, 14, 8, 64, 2048, 1890);
	GPU card7 = GPU("AMD Radeon RX Vega 56", 2017, 399, 2, 210, "HDMI 2.0 / DisplayPort 1.4 HBR3 / DisplayPort 1.4 HDR", "2x 8-pin", 295, 210, 48, 1156, 1471, "PCIe 3.0 x16", 495, 12500, 14, 8, 56, 2048, 1600);
	GPU card8 = GPU("NVIDIA GeForce GTX 1050 Ti", 2016, 139, 2, 75, "HDMI 2.0b / DisplayPort 1.4", "6-pin", 148, 111, 37, 1290, 1392, "PCIe 3.0 x16", 132, 3300, 14, 6, 7, 192, 7000);
	GPU card9 = GPU("AMD Radeon RX 480", 2016, 199, 2, 150, "HDMI 2.0b / DisplayPort 1.4", "6-pin", 240, 135, 41, 1120, 1266, "PCIe 3.0 x16", 232, 5700, 14, 5, 36, 256, 2000);
	GPU card10 = GPU("NVIDIA GeForce GTX 970", 2014, 329, 2, 145, "HDMI 1.4a / Dual-Link DVI-D / Dual-Link DVI-I / DisplayPort 1.2", "6-pin + 8-pin", 298, 111, 28, 1050, 1178, "PCIe 3.0 x16", 554, 7000, 28, 6, 13, 256, 7000);
	GPU card11 = GPU("NVIDIA GeForce GTX 770", 2013, 329, 2, 230, "HDMI 1.4a / Dual-Link DVI-D / Dual-Link DVI-I / DisplayPort 1.2", "8-pin", 284, 111, 28, 1046, 1085, "PCIe 3.0 x16", 3540, 6400, 28, 6, 15, 256, 7000);
	GPU card12 = GPU("NVIDIA GeForce GTX 670", 2012, 399, 2, 170, "HDMI 1.4a / Dual-Link DVI-D / Dual-Link DVI-I / DisplayPort 1.2", "8-pin", 238, 111, 28, 915, 980, "PCIe 3.0 x16", 3072, 6000, 28, 6, 13, 256, 6000);
	GPU card13 = GPU("AMD Radeon HD 7970", 2012, 449, 2, 250, "HDMI 1.4a / Dual-Link DVI-D / Dual-Link DVI-I / DisplayPort 1.2", "8-pin", 285, 111, 28, 925, 1375, "PCIe 3.0 x16", 4310, 6000, 28, 6, 20, 384, 5500);
	GPU card14 = GPU("AMD Radeon HD 7870", 2012, 349, 2, 180, "HDMI 1.4a / Dual-Link DVI-D / Dual-Link DVI-I / DisplayPort 1.2", "6-pin + 8-pin", 240, 111, 28, 1000, 1200, "PCIe 3.0 x16", 2080, 4800, 28, 6, 20, 256, 4800);
	GPU card15 = GPU("AMD Radeon HD 7850", 2012, 299, 2, 130, "HDMI 1.4a / Dual-Link DVI-D / Dual-Link DVI-I / DisplayPort 1.2", "6-pin", 240, 111, 28, 860, 900, "PCIe 3.0 x16", 1792, 4800, 28, 6, 20, 256, 4800);
	GPU card16 = GPU("NVIDIA GeForce GTX 980 Ti", 2014, 649, 2, 250, "HDMI 2.0 / Dual-Link DVI-I / Dual-Link DVI-D / DisplayPort 1.2", "8-pin + 6-pin", 270, 111, 28, 1000, 1075, "PCIe 3.0 x16", 2816, 7000, 28, 6, 22, 384, 7000);
	GPU card17 = GPU("NVIDIA GeForce GTX 970", 2014, 329, 2, 145, "HDMI 1.4a / Dual-Link DVI-D / Dual-Link DVI-I / DisplayPort 1.2", "6-pin + 8-pin", 298, 111, 28, 1050, 1178, "PCIe 3.0 x16", 554, 7000, 28, 6, 13, 256, 7000);
	GPU card18 = GPU("Intel Arc A580", 2022, 599, 2, 170, "HDMI 2.1 / DisplayPort 1.4", "2x 8-pin", 240, 130, 0, 1605, 1905, "PCIe 4.0 x16", 251, 10300, 7, 8, 57, 256, 16000);
	GPU card19 = GPU("Intel Arc A770", 2022, 799, 2, 230, "HDMI 2.1 / DisplayPort 1.4", "2x 8-pin", 240, 130, 0, 1605, 1905, "PCIe 4.0 x16", 251, 10300, 7, 8, 57, 256, 16000);

	GPUDatabaseList.appendNodeFront(card1);
	GPUDatabaseList.appendNodeFront(card2);
	GPUDatabaseList.appendNodeFront(card3);
	GPUDatabaseList.appendNodeFront(card4);
	GPUDatabaseList.appendNodeFront(card5);
	GPUDatabaseList.appendNodeFront(card6);
	GPUDatabaseList.appendNodeFront(card7);
	GPUDatabaseList.appendNodeFront(card8);
	GPUDatabaseList.appendNodeFront(card9);
	GPUDatabaseList.appendNodeFront(card10);
	GPUDatabaseList.appendNodeFront(card11);
	GPUDatabaseList.appendNodeFront(card12);
	GPUDatabaseList.appendNodeFront(card13);
	GPUDatabaseList.appendNodeFront(card14);
	GPUDatabaseList.appendNodeFront(card15);
	GPUDatabaseList.appendNodeFront(card16);
	GPUDatabaseList.appendNodeFront(card17);
	GPUDatabaseList.appendNodeFront(card18);
	GPUDatabaseList.appendNodeFront(card19);
	
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
	string name;
	int msrp, reDate;

	//vars if the user wants to add a full gpu (this will take for ever and is only included for functionality)
	string output, powerCon, busI;
	int len, wid, hei, trans, slotW, tdp;
	int baseC, boostC, dieS, processorS, memoryS, memoryC, memoryG, memoryB;
	string brand, gen, arch;

	int option;
	cout << "\n\n\nChoose a option to contiune\n";
	cout << "1. Add a GPU to the list with minimal specification \n";
	cout << "2. Add a GPU to the list with full specification (Not recomended)\nChoice:";
	cin >> option;
	cout << endl;

	if (option == 1)
	{
		GPU temp = GPU();
		cin.ignore();
		cout << "\nEnter the name of the GPU you would like to enter\n";
		getline(cin, name);
		temp.setName(name);

		cout << "\nEnter the release date of the GPU (year format, 20XX)\n";
		cin >> reDate;
		temp.setReleaseDate(reDate);

		cout << "\nEnter the suggested price, or MSRP, of the GPU\n";
		cin >> msrp;
		temp.setMSRP(msrp);


		GPUDatabaseList.appendNodeFront(temp);
		temp.showInfo();
		cout << "GPU added to list.\n\n";
	}
	else if (option == 2)
	{
		// Get user input
		cin.ignore();
		cout << "\nEnter the name of the GPU you would like to enter\n";
		getline(cin, name);
		cout << "\nEnter the release date of the GPU (year/quater format, 20XX QX)\n";
		cin >> reDate;
		cout << "\nEnter the suggested price, or MSRP, of the GPU\n";
		cin >> msrp;
		cout << "\nEnter the width of the slot that the GPU occupies on a motherboard\n";
		cin >> slotW;
		cout << "\nEnter the thermal design power of the GPU\n";
		cin >> tdp;
		cin.ignore();
		cout << "\nEnter the video output options of the GPU\n";
		getline(cin, output);
		cout << "\nEnter the power connector type of the GPU\n";
		getline(cin, powerCon);
		cout << "\nEnter the length of the GPU\n";
		cin >> len;
		cout << "\nEnter the width of the GPU\n";
		cin >> wid;
		cout << "\nEnter the height of the GPU\n";
		cin >> hei;
		cout << "\nEnter the base clock speed of the GPU\n";
		cin >> baseC;
		cout << "\nEnter the boost clock speed of the GPU\n";
		cin >> boostC;
		cin.ignore();
		cout << "\nEnter the bus interface of the GPU\n";
		getline(cin, busI);
		cout << "\nEnter the die size of the GPU\n";
		cin >> dieS;
		cout << "\nEnter the number of transistors in the GPU\n";
		cin >> trans;
		cout << "\nEnter the size of the GPU\n";
		cin >> processorS;
		cout << "\nEnter the size of the memory in the GPU\n";
		cin >> memoryS;
		cout << "\nEnter the generation of the memory in the GPU\n";
		cin >> memoryG;
		cout << "\nEnter the memory bus width of the GPU\n";
		cin >> memoryB;
		cout << "\nEnter the clock speed of the memory in the GPU\n";
		cin >> memoryC;
		cin.ignore();

		cout << "\nPlease pay attention to input for next 3 variables, GPU will not list correctly if entered wrong\n\n";

		cout << "\nEnter the brand of the GPU\n";
		getline(cin, brand);
		cout << "\nEnter the generation of the GPU\n";
		getline(cin, gen);
		cout << "\nEnter the architecture of the GPU\n";
		getline(cin, arch);

		// Create a new GPU object with the user-specified values
		GPU temp = GPU(name, reDate, msrp, slotW, tdp, output, powerCon, len, wid, hei, baseC, boostC, busI, dieS, trans, processorS, memoryS, memoryG, memoryB, memoryC, brand, gen, arch);
		temp.showInfo();
		GPUDatabaseList.appendNodeFront(temp);
		cout << "GPU added to list.\n\n";
	}
	else
	{
		cout << "Error reading input, please try again\n";
		return addList();
	}

	mainMenu();
}

void deleteItem()
{
    string gpuToDelete = "";
    GPU test;

    cin.ignore();
    cout << "What GPU would you like to delete?" << endl;
    getline(cin, gpuToDelete);

    GPUDatabaseList.deleteItem(test, gpuToDelete);
	cout << endl;
    cout<< GPUDatabaseList.size()<<" GPU's Loaded into Database"<<endl;
    mainMenu();
    
}

void viewByArch()
{
	int brand;
	int archNum;
	string arch;

	cout << "Select a brand:" << endl;
	cout << "1. Nvidia" << endl;
	cout << "2. AMD" << endl;
	cout << "3. Intel" << endl;
	cin >> brand;

	// Select architecture based on brand
	switch (brand)
	{
	case 1:
		cout << "Select an architecture:" << endl;
		cout << "1. Pascal" << endl;
		cout << "2. Turing" << endl;
		cout << "3. Ampere" << endl;
		cout << "4. Ada" << endl;
		cin >> archNum;

		// Map architecture number to name
		switch (archNum)
		{
		case 1:
			arch = "Pascal";
			break;
		case 2:
			arch = "Turing";
			break;
		case 3:
			arch = "Ampere";
			break;
		case 4:
			arch = "Ada";
			break;
		default:
			cout << "Invalid architecture selection" << endl;
			return;
		}
		break;
	case 2:
		cout << "Select an architecture:" << endl;
		cout << "1. Graphics_Core_Next_4" << endl;
		cout << "2. AMD_Graphics_Core_Next_5" << endl;
		cout << "3. RDNA1" << endl;
		cout << "4. RDNA2" << endl;
		cout << "5. RDNA3" << endl;
		cin >> archNum;

		// Map architecture number to name
		switch (archNum)
		{
		case 1:
			arch = "Graphics_Core_Next_4";
			break;
		case 2:
			arch = "AMD_Graphics_Core_Next_5";
			break;
		case 3:
			arch = "RDNA1";
			break;
		case 4:
			arch = "RDNA2";
		case 5:
			arch = "RDNA3";
		default:
			cout << "Invalid architecture selection" << endl;
			return;
		}
		break;
	case 3:
		cout << "Select an architecture:" << endl;
		cout << "1. Xe_HPG" << endl;
		cout << "2. Xe2_HPG" << endl;
		cout << "3. Xe3_HPG" << endl;
		cout << "4. Xe_Next_Architecture" << endl;
		cin >> archNum;

		// Map architecture number to name
		switch (archNum)
		{
		case 1:
			arch = "Xe_HPG";
			break;
		case 2:
			arch = "Xe2_HPG";
			break;
		case 3:
			arch = "Xe3_HPG";
			break;
		case 4:
			arch = "Xe_Next_Architecture";
			break;
		default:
			cout << "Invalid architecture selection" << endl;
			return;
		}
		break;
	}

	GPUDatabaseList.printByArch(arch);
	mainMenu();
}

void viewByGen()
{
	int brand;
	int genNum;
	string gen;

	cout << "Select a manufacturer:" << endl;
	cout << "1. Nvidia" << endl;
	cout << "2. AMD" << endl;
	cout << "3. Intel" << endl;
	cin >> brand;

	// Select generation based on brand
	switch (brand)
	{
	case 1:
		cout << "Select a generation:" << endl;
		cout << "1. GeForce10series" << endl;
		cout << "2. GeForce16Series" << endl;
		cout << "3. GeForce20series" << endl;
		cout << "4. GeForce30Series" << endl;
		cout << "5. GeForce40series" << endl;
		cin >> genNum;

		// Map generation number to name
		switch (genNum)
		{
		case 1:
			gen = "GeForce10series";
			break;
		case 2:
			gen = "GeForce16Series";
			break;
		case 3:
			gen = "GeForce20series";
			break;
		case 4:
			gen = "GeForce30Series";
			break;
		case 5:
			gen = "GeForce40series";
			break;
		default:
			cout << "Invalid generation selection" << endl;
			return;
		}
		break;
	case 2:
		cout << "Select a generation:" << endl;
		cout << "1. RadeonRX400Series" << endl;
		cout << "2. RadeonRX500Series" << endl;
		cout << "3. RadeonRX5000Series" << endl;
		cout << "4. RadeonRX6000Series" << endl;
		cout << "5. RadeonRX7000Series" << endl;
		cin >> genNum;

		// Map generation number to name
		switch (genNum)
		{
		case 1:
			gen = "RadeonRX400Series";
			break;
		case 2:
			gen = "RadeonRX500Series";
			break;
		case 3:
			gen = "RadeonRX5000Series";
			break;
		case 4:
			gen = "RadeonRX6000Series";
			break;
		case 5:
			gen = "RadeonRX7000Series";
			break;
		default:
			cout << "Invalid generation selection" << endl;
			return;
		}
		break;
	case 3:
		cout << "Select a generation:" << endl;
		cout << "1. Arc_Alchemist" << endl;
		cout << "2. Arc_Battlemage" << endl;
		cout << "3. Arc_Celestial" << endl;
		cout << "4. Arc_Druid" << endl;
		cin >> genNum;

		// Map generation number to name
		switch (genNum)
		{
		case 1:
			gen = "Arc_Alchemist";
			break;
		case 2:
			gen = "Arc_Battlemage";
			break;
		case 3:
			gen = "Arc_Celestial";
			break;
		case 4:
			gen = "Arc_Druid";
			break;
		default:
			cout << "Invalid generation selection" << endl;
			return;
		}
		break;
	default:
		cout << "Invalid manufacturer selection" << endl;
		return;
	}

	GPUDatabaseList.printByGen(gen);
	mainMenu();
}

void viewByBrand()
{
	int ch;
	string brand;

	cout << "Select a manufacturer:" << endl;
	cout << "1. Nvidia" << endl;
	cout << "2. AMD" << endl;
	cout << "3. Intel" << endl;
	cin >> ch;

	// Select manufacturer
	switch (ch)
	{
	case 1:
		brand = "Nvidia";
		break;
	case 2:
		brand = "AMD";
		break;
	case 3:
		brand = "Intel";
		break;
	default:
		cout << "Invalid manufacturer selection" << endl;
		return;

	}

	GPUDatabaseList.printByMan(brand);
	mainMenu();
}

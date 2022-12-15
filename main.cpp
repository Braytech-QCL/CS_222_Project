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

// This function populates the database with a pre - defined list of GPUs.
void populateList()
{
	GPU gpu_card1 = GPU("NVIDIA GeForce GTX 1050", 2016, 109, 1, 75, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "None", 144, 111, 35, 1354, 1455, "PCIe 3.0 x16", 132, 3500, 2, 8, 6, 128, 7000, "Nvidia", "GeForce10series", "Pascal");
	GPU gpu_card2 = GPU("NVIDIA GeForce GTX 1060 6 GB", 2016, 299, 2, 120, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 229, 111, 35, 1506, 1708, "PCIe 3.0 x16", 200, 7200, 16, 8, 6, 192, 8000, "Nvidia", "GeForce10series", "Pascal");
	GPU gpu_card3 = GPU("NVIDIA GeForce GTX 1070", 2016, 399, 2, 150, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 267, 111, 39, 1506, 1683, "PCIe 3.0 x16", 314, 7200, 16, 8, 8, 256, 8000, "Nvidia", "GeForce10series", "Pascal");
	GPU gpu_card4 = GPU("NVIDIA GeForce GTX 1080 Ti", 2017, 699, 2, 250, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 267, 111, 43, 1480, 1582, "PCIe 3.0 x16", 314, 11000, 16, 8, 11, 352, 11000, "Nvidia", "GeForce10series", "Pascal");
	GPU gpu_card5 = GPU("NVIDIA TITAN X Pascal", 2016, 1199, 2, 250, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 267, 111, 43, 1417, 1531, "PCIe 3.0 x16", 314, 12000, 16, 8, 10, 384, 10000, "Nvidia", "GeForce10series", "Turing");
	GPU gpu_card6 = GPU("NVIDIA GeForce GTX 1650", 2019, 149, 1, 75, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 151, 111, 35, 1485, 1665, "PCIe 3.0 x16", 122, 3500, 4, 8, 6, 128, 8000, "Nvidia", "GeForce16series", "Turing");
	GPU gpu_card7 = GPU("NVIDIA GeForce GTX 1660", 2019, 219, 1, 125, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 171, 111, 36, 1530, 1785, "PCIe 3.0 x16", 192, 6300, 6, 8, 6, 192, 8000, "Nvidia", "GeForce16series", "Turing");
	GPU gpu_card8 = GPU("NVIDIA GeForce GTX 1660 Ti", 2019, 279, 1, 120, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 171, 111, 36, 1500, 1770, "PCIe 3.0 x16", 192, 6300, 6, 8, 6, 192, 8000, "Nvidia", "GeForce16series", "Turing");
	GPU gpu_card9 = GPU("NVIDIA GeForce RTX 2060", 2018, 349, 2, 160, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 215, 111, 39, 1365, 1680, "PCIe 3.0 x16", 200, 7200, 6, 8, 6, 192, 8000, "Nvidia", "GeForce20series", "Turing");
	GPU gpu_card10 = GPU("NVIDIA GeForce RTX 2070", 2018, 499, 2, 175, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 215, 111, 39, 1410, 1710, "PCIe 3.0 x16", 200, 7200, 8, 8, 8, 256, 8000, "Nvidia", "GeForce20series", "Turing");
	GPU gpu_card11 = GPU("NVIDIA GeForce RTX 2080 SUPER", 2019, 699, 2, 250, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 215, 111, 39, 1650, 1815, "PCIe 3.0 x16", 314, 7200, 8, 8, 8, 256, 10000, "Nvidia", "GeForce20series", "Turing");
	GPU gpu_card12 = GPU("NVIDIA GeForce RTX 2070", 2018, 499, 2, 175, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 215, 111, 39, 1410, 1710, "PCIe 3.0 x16", 200, 7200, 8, 8, 8, 256, 8000, "Nvidia", "GeForce20series", "Turing");
	GPU gpu_card13 = GPU("NVIDIA GeForce RTX 3060", 2020, 319, 2, 120, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 209, 111, 38, 1320, 1665, "PCIe 4.0 x16", 285, 8400, 8, 8, 8, 256, 14000, "Nvidia", "GeForce30series", "Ampere");
	GPU gpu_card14 = GPU("NVIDIA GeForce RTX 3070", 2020, 499, 2, 220, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 209, 111, 38, 1500, 1725, "PCIe 4.0 x16", 285, 8400, 8, 8, 8, 256, 14000, "Nvidia", "GeForce30series", "Ampere");
	GPU gpu_card15 = GPU("NVIDIA GeForce RTX 3080", 2020, 699, 2, 320, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "12-pin", 284, 111, 38, 1440, 1710, "PCIe 4.0 x16", 628, 10800, 8, 8, 8, 256, 19000, "Nvidia", "GeForce30series", "Ampere");
	GPU gpu_card16 = GPU("NVIDIA GeForce RTX 3090", 2020, 1499, 2, 350, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "12-pin", 328, 111, 38, 1395, 1695, "PCIe 4.0 x16", 628, 10800, 10, 8, 10, 320, 19000, "Nvidia", "GeForce30series", "Ampere");
	GPU gpu_card17 = GPU("NVIDIA GeForce RTX 3090 Ti", 2021, 1899, 2, 400, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "12-pin", 328, 111, 38, 1410, 1710, "PCIe 4.0 x16", 628, 10800, 10, 8, 10, 320, 19000, "Nvidia", "GeForce30series", "Ampere");
	GPU gpu_card18 = GPU("NVIDIA GeForce RTX 4080", 2022, 799, 3, 350, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "12-pin", 284, 111, 38, 1610, 1890, "PCIe 4.0 x16", 826, 13200, 8, 8, 8, 256, 25000, "Nvidia", "GeForce40series", "Ada");
	GPU gpu_card19 = GPU("NVIDIA GeForce RTX 4090", 2022, 999, 3, 400, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "12-pin", 328, 111, 38, 1720, 1980, "PCIe 4.0 x16", 826, 13200, 10, 8, 10, 320, 25000, "Nvidia", "GeForce40series", "Ada");
	GPU gpu_card20 = GPU("NVIDIA GeForce RTX 4090 Ti", 2022, 1199, 3, 450, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "12-pin", 328, 111, 38, 1735, 1995, "PCIe 4.0 x16", 826, 13200, 10, 8, 10, 320, 25000, "Nvidia", "GeForce40series", "Ada");
	
	GPU gpu_card21 = GPU("Intel Arc A580", 2022, 399, 1, 65, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 216, 111, 36, 1150, 1350, "PCIe 4.0 x16", 315, 7200, 8, 8, 8, 256, 10000, "Intel", "Arc_Alchemist", "Xe_HPG");
	GPU gpu_card22 = GPU("Intel Arc A770", 2022, 499, 1, 95, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 216, 111, 36, 1350, 1550, "PCIe 4.0 x16", 315, 7200, 8, 8, 8, 256, 10000, "Intel", "Arc_Alchemist", "XE_HPG");
	
	GPU gpu_card23 = GPU("AMD Radeon RX 460", 2016, 109, 1, 75, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 151, 111, 35, 1090, 1200, "PCIe 3.0 x16", 123, 3600, 4, 8, 6, 128, 7000, "AMD", "RadeonRX400series", "Graphics_Core_Next_4");
	GPU gpu_card24 = GPU("AMD Radeon RX 470", 2016, 179, 1, 120, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 191, 111, 36, 926, 1206, "PCIe 3.0 x16", 212, 5800, 8, 8, 8, 256, 7000, "AMD", "RadeonRX400series", "Graphics_Core_Next_4");
	GPU gpu_card25 = GPU("AMD Radeon RX 480", 2016, 239, 1, 150, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 191, 111, 36, 1120, 1266, "PCIe 3.0 x16", 232, 5800, 8, 8, 8, 256, 7000, "AMD", "RadeonRX400series", "Graphics_Core_Next_4");
	GPU gpu_card26 = GPU("AMD Radeon RX 550", 2017, 89, 1, 50, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 151, 111, 35, 1183, 1287, "PCIe 3.0 x16", 103, 3600, 4, 8, 4, 128, 7000, "AMD", "RadeonRX500series", "AMD_Graphics_Core_Next_5");
	GPU gpu_card27 = GPU("AMD Radeon RX 560", 2017, 99, 1, 80, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 151, 111, 35, 1175, 1275, "PCIe 3.0 x16", 123, 3600, 4, 8, 6, 128, 7000, "AMD", "RadeonRX500series", "AMD_Graphics_Core_Next_5");
	GPU gpu_card28 = GPU("AMD Radeon RX 570", 2017, 169, 1, 120, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 191, 111, 36, 1168, 1340, "PCIe 3.0 x16", 212, 5800, 8, 8, 8, 256, 7000, "AMD", "RadeonRX500series", "AMD_Graphics_Core_Next_5");
	GPU gpu_card29 = GPU("AMD Radeon RX 580", 2017, 229, 1, 185, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "6-pin", 191, 111, 36, 1257, 1340, "PCIe 3.0 x16", 232, 5800, 8, 8, 8, 256, 7000, "AMD", "RadeonRX500series", "AMD_Graphics_Core_Next_5");
	GPU gpu_card30 = GPU("AMD Radeon RX 590", 2018, 279, 1, 225, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 235, 111, 38, 1576, 1771, "PCIe 3.0 x16", 232, 5800, 8, 8, 8, 256, 7000, "AMD", "RadeonRX500series", "AMD_Graphics_Core_Next_5");
	GPU gpu_card31 = GPU("AMD Radeon RX 5500 OEM", 2019, 199, 1, 130, "HDMI 2.0b, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 151, 111, 36, 1685, 1845, "PCIe 4.0 x16", 158, 7200, 8, 8, 8, 128, 7000, "AMD", "RadeonRX5000series", "RDNA1");
	GPU gpu_card32 = GPU("AMD Radeon RX 5600 OEM", 2019, 279, 1, 150, "HDMI 2.1, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 151, 111, 36, 1190, 1460, "PCIe 4.0 x16", 158, 7200, 6, 8, 6, 128, 7000, "AMD", "RadeonRX5000series", "RDNA1");
	GPU gpu_card33 = GPU("AMD Radeon RX 5700", 2019, 379, 1, 180, "HDMI 2.1, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 151, 111, 36, 1465, 1625, "PCIe 4.0 x16", 251, 8400, 8, 8, 8, 256, 7000, "AMD", "RadeonRX5000series", "RDNA1");
	GPU gpu_card34 = GPU("AMD Radeon RX 5700 XT", 2019, 449, 1, 225, "HDMI 2.1, DisplayPort 1.4, Dual Link DVI-D", "8-pin", 151, 111, 36, 1605, 1905, "PCIe 4.0 x16", 251, 8400, 8, 8, 8, 256, 7000, "AMD", "RadeonRX5000series", "RDNA1");
	GPU gpu_card35 = GPU("AMD Radeon RX 6600", 2022, 349, 1, 150, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 151, 111, 36, 1685, 1845, "PCIe 4.0 x16", 158, 7200, 8, 8, 8, 128, 7000, "AMD", "RadeonRX6000series", "RDNA2");
	GPU gpu_card36 = GPU("AMD Radeon RX 6700", 2022, 449, 1, 180, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 151, 111, 36, 1465, 1625, "PCIe 4.0 x16", 251, 8400, 8, 8, 8, 256, 7000, "AMD", "RadeonRX6000series", "RDNA2");
	GPU gpu_card37 = GPU("AMD Radeon RX 6800", 2020, 599, 1, 250, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 151, 111, 36, 1815, 2105, "PCIe 4.0 x16", 438, 12800, 16, 8, 16, 512, 7000, "AMD", "RadeonRX6000series", "RDNA2");
	GPU gpu_card38 = GPU("AMD Radeon RX 6900 XT", 2020, 999, 2, 300, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 151, 111, 36, 2015, 2315, "PCIe 4.0 x16", 438, 12800, 16, 8, 16, 512, 7000, "AMD", "RadeonRX6000series", "RDNA2");
	GPU gpu_card39 = GPU("AMD Radeon RX 6950 XT", 2021, 1199, 3, 300, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 151, 111, 36, 2115, 2415, "PCIe 4.0 x16", 438, 12800, 16, 8, 16, 512, 7000, "AMD", "RadeonRX6000series", "RDNA2");
	GPU gpu_card40 = GPU("AMD Radeon RX 7900 XT", 2022, 1499, 3, 350, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 151, 111, 36, 2315, 2615, "PCIe 4.0 x16", 438, 12800, 16, 8, 16, 512, 7000, "AMD", "RadeonRX7000series", "RDNA3");
	GPU gpu_card41 = GPU("AMD Radeon RX 7900 XTX", 2022, 1699, 3, 400, "HDMI 2.1, DisplayPort 1.4a, Dual Link DVI-D", "8-pin", 151, 111, 36, 2515, 2815, "PCIe 4.0 x16", 438, 12800, 16, 8, 16, 512, 7000, "AMD", "RadeonRX7000series", "RDNA3");








	GPUDatabaseList.appendNodeFront(gpu_card1);
	GPUDatabaseList.appendNodeFront(gpu_card2);
	GPUDatabaseList.appendNodeFront(gpu_card3);
	GPUDatabaseList.appendNodeFront(gpu_card4);
	GPUDatabaseList.appendNodeFront(gpu_card5);
	GPUDatabaseList.appendNodeFront(gpu_card6);
	GPUDatabaseList.appendNodeFront(gpu_card7);
	GPUDatabaseList.appendNodeFront(gpu_card8);
	GPUDatabaseList.appendNodeFront(gpu_card9);
	GPUDatabaseList.appendNodeFront(gpu_card10);
	GPUDatabaseList.appendNodeFront(gpu_card11);
	GPUDatabaseList.appendNodeFront(gpu_card12);
	GPUDatabaseList.appendNodeFront(gpu_card13);
	GPUDatabaseList.appendNodeFront(gpu_card14);
	GPUDatabaseList.appendNodeFront(gpu_card15);
	GPUDatabaseList.appendNodeFront(gpu_card16);
	GPUDatabaseList.appendNodeFront(gpu_card17);
	GPUDatabaseList.appendNodeFront(gpu_card18);
	GPUDatabaseList.appendNodeFront(gpu_card19);
	GPUDatabaseList.appendNodeFront(gpu_card20);
	GPUDatabaseList.appendNodeFront(gpu_card21);
	GPUDatabaseList.appendNodeFront(gpu_card22);
	GPUDatabaseList.appendNodeFront(gpu_card23);
	GPUDatabaseList.appendNodeFront(gpu_card24);
	GPUDatabaseList.appendNodeFront(gpu_card25);
	GPUDatabaseList.appendNodeFront(gpu_card26);
	GPUDatabaseList.appendNodeFront(gpu_card27);
	GPUDatabaseList.appendNodeFront(gpu_card28);
	GPUDatabaseList.appendNodeFront(gpu_card29);
	GPUDatabaseList.appendNodeFront(gpu_card30);
	GPUDatabaseList.appendNodeFront(gpu_card31);
	GPUDatabaseList.appendNodeFront(gpu_card32);
	GPUDatabaseList.appendNodeFront(gpu_card33);
	GPUDatabaseList.appendNodeFront(gpu_card34);
	GPUDatabaseList.appendNodeFront(gpu_card35);
	GPUDatabaseList.appendNodeFront(gpu_card36);
	GPUDatabaseList.appendNodeFront(gpu_card37);
	GPUDatabaseList.appendNodeFront(gpu_card38);
	GPUDatabaseList.appendNodeFront(gpu_card39);
	GPUDatabaseList.appendNodeFront(gpu_card40);
	GPUDatabaseList.appendNodeFront(gpu_card41);
	
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
	case 3: //Only Xe_HPG cards exist right now
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
		cout << "1. RadeonRX400series" << endl;
		cout << "2. RadeonRX500series" << endl;
		cout << "3. RadeonRX5000series" << endl;
		cout << "4. RadeonRX6000series" << endl;
		cout << "5. RadeonRX7000series" << endl;
		cin >> genNum;

		// Map generation number to name
		switch (genNum)
		{
		case 1:
			gen = "RadeonRX400series";
			break;
		case 2:
			gen = "RadeonRX500series";
			break;
		case 3:
			gen = "RadeonRX5000series";
			break;
		case 4:
			gen = "RadeonRX6000series";
			break;
		case 5:
			gen = "RadeonRX7000series";
			break;
		default:
			cout << "Invalid generation selection" << endl;
			return;
		}
		break;
	case 3: //Battlemage to Druid dose not exist yes
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

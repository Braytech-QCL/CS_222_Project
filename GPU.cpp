#include <iostream>
#include "GPU.h"

using namespace std;

void GPU::showInfo() 
{
	cout << "Graphics Card Name: " << name << endl;
	cout << "Release date: " << releaseDate << endl;
	cout << "Manufacter suggested retail price: " << MSRP << endl;

	test.showInfo();

	
}


//Constructor
GPU::GPU(string _name, string _releaseDate, int _MSRP, double slotW, int tdp, string output,
	string powerCon, double len, double wid, double hei)
	{
		test = BoardDesign(slotW, tdp, output, powerCon, len, wid, hei);
		name = _name;
		releaseDate = _releaseDate;
		MSRP = _MSRP;
	}
